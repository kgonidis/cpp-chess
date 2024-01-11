#include "parser.h"
#include "constants.h"
#include "keys.h"

#include "EnhancedPGNParser.h"
#include "EnhancedPGNLexer.h"
#include <fstream>
#include <sstream>

move_state_t parse_san(EnhancedPGNParser::SanContext *context, game_t &game)
{
    auto location_to_index = [](std::string loc) -> int
    {
        int file = loc[0] - 'a';
        int rank = 7 - loc[1] + '1';
        return rank * 8 + file;
    };

    auto add_move = [&game](move_t m)
    {
        if (!game.makeMove(m))
            throw std::runtime_error("Invalid move");
        return move_state_t{
            .move = m,
            .state = game.getState(),
        };
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
        Bitboard source_mask = get_file_rank_bitboard(file, rank) & game.pieces[piece];
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
            get_bishop_attacks(&board, target_index, game.occupancies[BOTH]);
            break;
        }
        case R:
        case r:
        {
            get_rook_attacks(&board, target_index, game.occupancies[BOTH]);
            break;
        }
        case Q:
        case q:
        {
            get_queen_attacks(&board, target_index, game.occupancies[BOTH]);
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
                return move_state_t{
                    .move = m,
                    .state = game.getState()};
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

            Bitboard pawns = ATTACK_BOARDS.pawn[1 - game.side][target_index] & file_mask;
            int source_index = pawns.popls1b();
            if (source_index == -1)
                throw std::runtime_error("Invalid move");
            int promotion = no_piece;
            if (pawn_capture->piece() != nullptr)
            {
                int p = pawn_capture->piece()->getText()[0];
                promotion = CHAR_EPIECE_MAP[p];
                if (game.side == BLACK)
                    promotion += 6;
            }
            return add_move({
                .source = (uint32_t)source_index,
                .target = (uint32_t)target_index,
                .piece = (uint32_t)(game.side == WHITE ? P : p),
                .promotion = (uint32_t)promotion,
                .capture = (uint)no_piece,
            });
        }

        auto piece_capture = capture->piece_capture();
        if (piece_capture != nullptr)
        {
            int p = piece_capture->piece()->getText()[0];
            int piece = CHAR_EPIECE_MAP[p];
            if (game.side == BLACK)
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
        int piece = game.side == WHITE ? P : p;
        int target_index = location_to_index(pawn_move->LOCATION()->getText());
        int promotion = no_piece;
        if (pawn_move->piece() != nullptr)
        {
            int p = pawn_move->piece()->getText()[0];
            promotion = CHAR_EPIECE_MAP[p];
            if (game.side == BLACK)
                promotion += 6;
        }
        int increment = game.side == WHITE ? 8 : -8;
        int source_index = target_index + increment;

        if (game.pieces[piece][source_index])
            return add_move({
                .source = (uint32_t)source_index,
                .target = (uint32_t)target_index,
                .piece = (uint32_t)piece,
                .promotion = (uint32_t)promotion,
                .capture = (uint)no_piece,
            });

        source_index += increment;
        if (game.pieces[piece][source_index])
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
        if (game.side == BLACK)
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
        int piece = game.side == WHITE ? K : k;

        bool king_side = castle->SHORT_CASTLE() != nullptr;
        int source_index = game.side == WHITE ? e1 : e8;
        int target_index = game.side == WHITE ? g1 : g8;
        int castling = game.side == WHITE ? WKCA : BKCA;
        if (!king_side)
        {
            target_index = game.side == WHITE ? c1 : c8;
            castling = game.side == WHITE ? WQCA : BQCA;
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

move_tree_t *ParseTurn(EnhancedPGNParser::TurnContext *turn, move_tree_t *move_tree, game_t &game)
{
    std::pair<move_tree_t *, game_t> white(move_tree, game), black(nullptr, game);
    // get moves
    for (auto *s : turn->san())
    {
        auto move = parse_san(s, game);
        if (move_tree->value == nullptr)
            move_tree->value = new move_state_t(move);
        else
            move_tree = move_tree->AddChild(move);
        if (s->number == 0)
            black = std::make_pair(move_tree, game);
    }

    // append alternate moves
    for (auto *al : turn->alternate_line())
    {
        auto &side = al->number == 0 ? white : black;
        auto *mt = side.first;
        auto game = side.second;

        for (auto *turn : al->turn())
        {
            mt = ParseTurn(turn, mt, game);
        }
    }
    return move_tree;
}

void pgn_parse(pgn_db_t *db, const char *filename)
{
    std::ifstream stream(filename);
    if (!stream.is_open())
        throw std::runtime_error("Could not open file " + std::string(filename));
    // std::stringstream stream;
    // stream << "[Event \"San Sebastian\"]\n[Site \"San Sebastian\"]\n[Date \"1911.??.??\"]\n[Round \"?\"]\n[White \"Capablanca, Jose\"]\n[Black \"Burn, Amos\"]\n[Result \"1-0\"]\n\n1.e4 e5 2.Nf3 Nc6 3.Bb5 a6 4.Ba4 Nf6 5.d3 { This is a very solid development, to which I was much addicted at the time, because of my ignorance of the multiple variations of the openings. } 5...d6 6.c3 Be7 ( { In this variation there is the alternative of developing this Bishop via **g7**, after } 6...g6 ) 7.Nbd2 O-O 8.Nf1 b5 9.Bc2 d5 10.Qe2 dxe4 11.dxe4 Bc5 { Evidently to make room for the Queen at **e7**, but I do not think the move advisable at this stage. } ( 11...Be6 { is a more natural and effective move. It develops a piece and threatens Bc4 which would have to be stopped. } ) 12.Bg5 Be6 { Now it is not so effective, because White\'s Queen\'s Bishop is out, and the Knight, in going to **e3** } 13.Ne3 { defends **c4** and does not block the Queen\'s Bishop. } 13...Re8 14.O-O Qe7 { # This is bad. Black\'s game was already not good. He probably had no choice but to take the Knight with the Bishop before making this move. } 15.Nd5 Bxd5 16.exd5 Nb8 { In order to bring it to **d7**, to support the other Knight and also his King\'s Pawn. White, however, does not allow time for this, and by taking advantage of his superior position is able to win a Pawn. } 17.a4 b4 ( { Since he had no way to prevent the loss of a Pawn, he should have given it up where it is, and played } 17...Nbd7 { in order to make his position more solid. The text move not only loses a Pawn, but leaves Black\'s game very much weakened. } ) 18.cxb4 Bxb4 19.Bxf6 Qxf6 20.Qe4 Bd6 21.Qxh7+ Kf8 { With a Pawn more and all his pieces ready for action, while Black is still backward in development, it only remains for White to drive home his advantage before Black can come out with his pieces, in which case, by using the open h-file, Black might be able to start a strong attack against White\'s King. White is able by his next move to eliminate all danger. # } 22.Nh4 Qh6 { This is practically forced. } ( { Black could not play } 22...g6 { because of } 23.Bxg6 { White meanwhile threatened } ) 23.Qxh6 gxh6 24.Nf5 h5 25.Bd1 Nd7 26.Bxh5 Nf6 27.Be2 Nxd5 28.Rfd1 Nf4 29.Bc4 Red8 30.h4 a5 { Black must lose time assuring the safety of this Pawn. } 31.g3 Ne6 32.Bxe6 fxe6 33.Ne3 Rdb8 34.Nc4 Ke7 { Black fights a hopeless battle. He is two Pawns down for all practical purposes, and the Pawns he has are isolated and have to be defended by pieces. } 35.Rac1 Ra7 { White threatened } 36.Re1 Kf6 37.Re4 Rb4 38.g4 Ra6 ( { If } 38...Rxa4 { then } 39.Nxd6 { would of course win a piece. } ) 39.Rc3 Bc5 40.Rf3+ Kg7 41.b3 Bd4 42.Kg2 Ra8 43.g5 Ra6 44.h5 Rxc4 45.bxc4 Rc6 46.g6 { Black resigns. } 1-0";

    antlr4::ANTLRInputStream input(stream);

    EnhancedPGNLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    EnhancedPGNParser parser(&tokens);

    auto *context = parser.parse();

    std::vector<pgn_t> tmp_db;

    for (auto &p : context->pgn_database()->pgn())
    {
        pgn_t pgn = {
            .moves = new move_tree_t(),
        };
        std::vector<pair_t> pairs;
        move_tree_t *move_tree = pgn.moves;
        game_t game = game_t::FromStartingPosition();

        for (auto &tag_pair : p->tag_pairs()->tag_pair())
        {
            pairs.emplace_back(pair_t{
                .key = tag_pair->tag_key()->getText().c_str(),
                .value = tag_pair->tag_value()->getText().c_str(),
            });
        }
        pgn.pairs = new pair_t[pairs.size()];
        memcpy(pgn.pairs, pairs.data(), pairs.size() * sizeof(pair_t));
        pgn.n_pairs = pairs.size();

        for (auto &move_text_item : p->move_text()->move_text_item())
        {
            auto *turn = move_text_item->turn();
            if (turn != nullptr)
                move_tree = ParseTurn(turn, move_tree, game);
        }

        tmp_db.push_back(pgn);
    }
    db->pgns = new pgn_t[tmp_db.size()];
    memcpy(db->pgns, tmp_db.data(), tmp_db.size() * sizeof(pgn_t));
    db->n_pgns = tmp_db.size();
}

move_tree_t *pgn_moves(pgn_db_t *db, int index)
{
    return db->pgns[index].moves;
}

void free_pgn_db(pgn_db_t *db)
{
    for (int i = 0; i < db->n_pgns; i++)
    {
        delete db->pgns[i].moves;
        delete[] db->pgns[i].pairs;
    }
    delete[] db->pgns;
}
