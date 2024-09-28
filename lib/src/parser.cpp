#include "parser.h"
#include "constants.h"

#include "EnhancedPGNParser.h"
#include "EnhancedPGNLexer.h"
#include <fstream>
#include <sstream>
#include <attacks.h>

movetree_t *parse_san(EnhancedPGNParser::SanContext *context, movetree_t *movetree)
{
    game_t game(movetree->getData().state);
    auto location_to_index = [](std::string loc) -> int
    {
        int file = loc[0] - 'a';
        int rank = 7 - loc[1] + '1';
        return rank * 8 + file;
    };

    auto add_move = [&game, &movetree](move_t m)
    {
        if (!game.makeMove(m))
            throw std::runtime_error("Invalid move");
        move_node_t node = {
            .move = m,
            .state = game.getState()};
        auto *mt = movetree->addChild(node);
        return mt;
    };

    auto get_file_rank_bitboard = [](int file, int rank) -> Bitboard
    {
        Bitboard mask = 0ULL;
        if (file > -1 && file < 8)
        {
            for (int i = 0; i < 8; i++)
            {
                mask |= (1ULL << (file + i * 8));
            }
        }

        if (rank > -1 && rank < 8)
        {
            for (int i = 0; i < 8; i++)
            {
                mask |= (1ULL << (rank * 8 + i));
            }
        }

        if (mask == 0ULL)
            mask = ~mask;
        return mask;
    };

    auto add_piece_move = [&](int piece, int file, int rank, int target_index)
    {
        Bitboard source_mask = get_file_rank_bitboard(file, rank) & game.state.pieces[piece];
        Bitboard board = 0ULL;
        switch (piece)
        {
        case N:
        case n:
        {
            board = ATTACK_BOARDS.knight[target_index] & source_mask;
            break;
        }
        case K:
        case k:
        {
            board = ATTACK_BOARDS.king[target_index] & source_mask;
            break;
        }
        case B:
        case b:
        {
            get_bishop_attacks(&board, target_index, game.state.occupancies[BOTH]);
            break;
        }
        case R:
        case r:
        {
            get_rook_attacks(&board, target_index, game.state.occupancies[BOTH]);
            break;
        }
        case Q:
        case q:
        {
            get_queen_attacks(&board, target_index, game.state.occupancies[BOTH]);
            break;
        }
        }

        int source_index = board.popls1b();
        while (source_index > -1)
        {
            move_t m = {
                .source = (uint32_t)source_index,
                .target = (uint32_t)target_index,
                .piece = (uint32_t)piece,
                .promotion = (uint32_t)no_piece,
                .capture = (uint)no_piece,
            };
            if (game.makeMove(m))
            {
                move_node_t node = {
                    .move = m,
                    .state = game.getState()};
                return movetree->addChild(node);
            }
            source_index = board.popls1b();
        }
        throw std::runtime_error("Invalid move");
    };

    auto *capture = context->capture();
    if (capture != nullptr)
    {
        auto *pawn_capture = capture->pawn_capture();
        if (pawn_capture != nullptr)
        {
            int file = pawn_capture->FILE()->getText()[0] - 'a';
            Bitboard file_mask = 0ULL;
            for (int i = 0; i < 8; i++)
            {
                file_mask |= (1ULL << (file + i * 8));
            }

            int target_index = location_to_index(pawn_capture->LOCATION()->getText());

            Bitboard pawns = ATTACK_BOARDS.pawn[1 - game.state.side][target_index] & file_mask;
            int source_index = pawns.popls1b();
            if (source_index == -1)
                throw std::runtime_error("Invalid move");
            int promotion = no_piece;
            if (pawn_capture->piece() != nullptr)
            {
                int p = pawn_capture->piece()->getText()[0];
                promotion = CHAR_EPIECE_MAP[p];
                if (game.state.side == BLACK)
                    promotion += 6;
            }
            return add_move({
                .source = (uint32_t)source_index,
                .target = (uint32_t)target_index,
                .piece = (uint32_t)(game.state.side == WHITE ? P : p),
                .promotion = (uint32_t)promotion,
                .capture = (uint)no_piece,
            });
        }

        auto piece_capture = capture->piece_capture();
        if (piece_capture != nullptr)
        {
            int p = piece_capture->piece()->getText()[0];
            int piece = CHAR_EPIECE_MAP[p];
            if (game.state.side == BLACK)
                piece += 6;

            auto *f = piece_capture->FILE();
            auto *r = piece_capture->RANK();
            int target_index = location_to_index(piece_capture->LOCATION()->getText());
            int file = f == nullptr ? -1 : f->getText()[0] - 'a';
            int rank = r == nullptr ? -1 : 7 - r->getText()[0] + '1';
            return add_piece_move(piece, file, rank, target_index);
        }
        throw std::runtime_error("Invalid move: Should not reach here");
    }

    auto *pawn_move = context->pawn_move();
    if (pawn_move != nullptr)
    {
        int piece = game.state.side == WHITE ? P : p;
        int target_index = location_to_index(pawn_move->LOCATION()->getText());
        int promotion = no_piece;
        if (pawn_move->piece() != nullptr)
        {
            int p = pawn_move->piece()->getText()[0];
            promotion = CHAR_EPIECE_MAP[p];
            if (game.state.side == BLACK)
                promotion += 6;
        }
        int increment = game.state.side == WHITE ? 8 : -8;
        int source_index = target_index + increment;

        if (game.state.pieces[piece][source_index])
            return add_move({
                .source = (uint32_t)source_index,
                .target = (uint32_t)target_index,
                .piece = (uint32_t)piece,
                .promotion = (uint32_t)promotion,
                .capture = (uint)no_piece,
            });

        source_index += increment;
        if (game.state.pieces[piece][source_index])
            return add_move({
                .source = (uint32_t)source_index,
                .target = (uint32_t)target_index,
                .piece = (uint32_t)piece,
                .promotion = (uint32_t)promotion,
                .capture = (uint)no_piece,
            });
        throw std::runtime_error("Invalid move");
    }

    auto *piece_move = context->piece_move();
    if (piece_move != nullptr)
    {
        int p = piece_move->piece()->getText()[0];
        int piece = CHAR_EPIECE_MAP[p];
        if (game.state.side == BLACK)
            piece += 6;

        auto *f = piece_move->FILE();
        auto *r = piece_move->RANK();
        int target_index = location_to_index(piece_move->LOCATION()->getText());
        int file = f == nullptr ? -1 : f->getText()[0] - 'a';
        int rank = r == nullptr ? -1 : 7 - r->getText()[0] + '1';
        return add_piece_move(piece, file, rank, target_index);
    }

    auto *castle = context->castle();
    if (castle != nullptr)
    {
        int piece = game.state.side == WHITE ? K : k;

        bool king_side = castle->SHORT_CASTLE() != nullptr;
        int source_index = game.state.side == WHITE ? e1 : e8;
        int target_index = game.state.side == WHITE ? g1 : g8;
        int castling = game.state.side == WHITE ? WKCA : BKCA;
        if (!king_side)
        {
            target_index = game.state.side == WHITE ? c1 : c8;
            castling = game.state.side == WHITE ? WQCA : BQCA;
        }

        return add_move({
            .source = (uint32_t)source_index,
            .target = (uint32_t)target_index,
            .piece = (uint32_t)piece,
            .promotion = (uint32_t)no_piece,
            .castling = (uint32_t)castling,
            .capture = (uint)no_piece,
        });
    }
    throw std::runtime_error("Invalid move: Should not reach here");
}

movetree_t *ParseTurn(EnhancedPGNParser::TurnContext *turn, movetree_t *movetree)
{
    movetree_t *white = movetree, *black = nullptr, *mt = nullptr;
    // get moves
    for (auto *s : turn->san())
    {
        mt = parse_san(s, s->number == 0 ? white : black);
        if (s->number == 0)
            black = mt;
    }

    // append alternate moves
    for (auto *al : turn->alternate_line())
    {
        auto *m = al->number == 0 ? white : black;

        for (auto *turn : al->turn())
        {
            m = ParseTurn(turn, m);
        }
    }
    return mt;
}

void pgn_parse(pgn_db_t *db, const char *filename)
{
    std::ifstream stream(filename);
    if (!stream.is_open())
        throw std::runtime_error("Could not open file " + std::string(filename));

    antlr4::ANTLRInputStream input(stream);

    EnhancedPGNLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    EnhancedPGNParser parser(&tokens);

    auto *context = parser.parse();

    std::vector<pgn_t> tmp_db;

    for (auto &p : context->pgn_database()->pgn())
    {
        pgn_t pgn = {
            .moves = new movetree_t({
                .state = game_t::FromStartingPosition().getState(),
            }),
        };
        std::vector<pair_t> pairs;
        movetree_t *movetree = pgn.moves;
        game_t game = game_t::FromStartingPosition();

        for (auto &tag_pair : p->tag_pairs()->tag_pair())
        {
            pair_t pair{
                .key = new char[tag_pair->tag_key()->getText().size() + 1],
                .value = new char[tag_pair->tag_value()->getText().size() + 1],
            };
            strcpy(pair.key, tag_pair->tag_key()->getText().c_str());
            strcpy(pair.value, tag_pair->tag_value()->getText().c_str());
            pairs.push_back(pair);
        }
        pgn.pairs = new pair_t[pairs.size()];
        memcpy(pgn.pairs, pairs.data(), pairs.size() * sizeof(pair_t));
        pgn.n_pairs = pairs.size();

        for (auto &move_text_item : p->move_text()->move_text_item())
        {
            auto *turn = move_text_item->turn();
            if (turn != nullptr)
                movetree = ParseTurn(turn, movetree);
        }

        tmp_db.push_back(pgn);
    }
    db->pgns = new pgn_t[tmp_db.size()];
    memcpy(db->pgns, tmp_db.data(), tmp_db.size() * sizeof(pgn_t));
    db->n_pgns = tmp_db.size();
}

void print_pgn_db(pgn_db_t *db)
{
    for (int i = 0; i < db->n_pgns; i++)
    {
        auto &pgn = db->pgns[i];
        for (int j = 0; j < pgn.n_pairs; j++)
        {
            auto &pair = pgn.pairs[j];
            printf("[%s %s]\n", pair.key, pair.value);
        }
        std::cout << std::endl << game_t::ToPGN(pgn.moves) << std::endl << std::endl;
    }
}
