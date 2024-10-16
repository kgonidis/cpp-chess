#include "gametree.h"
#include "attacks.h"
#include "constants.h"

#include "EnhancedPGNParser.h"
#include "EnhancedPGNLexer.h"
#include <fstream>
#include <sstream>

movetree_t *parse_turn(EnhancedPGNParser::TurnContext *turn, movetree_t *movetree);
std::vector<pgn_token_t> to_pgn_tokens(movetree_t *moves);
std::string to_pgn_string(movetree_t *moves);
bool compare_moves(const move_t &move1, const move_t &move2);
bool compare_nodes(const movetree_t *node1, const movetree_t *node2);
u64 to_hash(movetree_t *node);

gametree_t::gametree_t()
    : current(new movetree_t()), tags(), n_tags(0), ref_count(std::make_shared<uint8_t>(0))
{
}

gametree_t::~gametree_t()
{
    if (ref_count.use_count() > 1 || current == nullptr)
        return;
    movetree_t *root = current;
    movetree_t *parent = root->getParent();
    while (parent != nullptr)
    {
        root = parent;
        parent = root->getParent();
    }
    root->deleteChildren();
    delete root;
    current = nullptr;
}

bool gametree_t::operator==(const gametree_t &tree) const
{
    // Compare tags
    if (n_tags != tree.n_tags)
    {
        return false;
    }

    for (size_t i = 0; i < n_tags; ++i)
    {
        if (tags[i].key != tree.tags[i].key || tags[i].value != tree.tags[i].value)
        {
            return false;
        }
    }

    auto root1 = getRoot();
    auto root2 = tree.getRoot();
    if (!root1.has_value() && !root2.has_value())
        return true;
    if (!root1.has_value() || !root2.has_value())
        return false;
    return compare_nodes(&root1.value(), &root2.value());
}

std::vector<gametree_t> gametree_t::FromPgn(const char *pgn)
{
    std::vector<gametree_t> gametrees;
    try
    {
        std::stringstream stream(pgn);
        antlr4::ANTLRInputStream input(stream);

        EnhancedPGNLexer lexer(&input);
        antlr4::CommonTokenStream tokens(&lexer);
        EnhancedPGNParser parser(&tokens);

        auto *context = parser.parse();

        auto pgn_database = context->pgn_database()->pgn();
        gametrees.resize(pgn_database.size());

        for (int i = 0; i < context->pgn_database()->pgn().size(); i++)
        {
            auto *p = pgn_database[i];
            gametree_t &gametree = gametrees[i];
            movetree_t *movetree = gametree.current;

            for (auto &tag_pair : p->tag_pairs()->tag_pair())
            {
                pair_t pair = {
                    .key = tag_pair->tag_key()->getText(),
                    .value = tag_pair->tag_value()->getText()};
                pair.value = pair.value.substr(1, pair.value.size() - 2);
                gametree.tags.push_back(pair);
            }
            gametree.n_tags = gametree.tags.size();

            for (auto &move_text_item : p->move_text()->move_text_item())
            {
                auto *turn = move_text_item->turn();
                if (turn != nullptr)
                    movetree = parse_turn(turn, movetree);
            }
        }
    }
    catch (std::exception &e)
    {
        std::cerr << "Error parsing PGN: " << e.what() << std::endl;
        gametrees.clear();
    }

    return gametrees;
}

game_t gametree_t::getPosition() const
{
    return current != nullptr ? game_t(current->getData().state) : game_t();
}

std::optional<movetree_t> gametree_t::getCurrent() const
{
    if (current == nullptr)
        return std::nullopt;
    return *current;
}

std::optional<movetree_t> gametree_t::getNext() const
{
    if (current == nullptr)
        return std::nullopt;
    auto next = current->getNext();
    if (next == nullptr)
        return std::nullopt;
    return *next;
}

std::optional<movetree_t> gametree_t::getPrev() const
{
    if (current == nullptr)
        return std::nullopt;
    auto prev = current->getParent();
    if (prev == nullptr)
        return std::nullopt;
    return *prev;
}

std::optional<movetree_t> gametree_t::getRoot() const
{
    if (current == nullptr)
        return std::nullopt;
    movetree_t *root = current;
    movetree_t *parent = root->getParent();
    while (parent != nullptr)
    {
        root = parent;
        parent = root->getParent();
    }
    return *root;
}

std::vector<pgn_token_t> gametree_t::getPgnTokens() const
{
    auto root = getRoot();
    if (!root.has_value())
        return {};
    return to_pgn_tokens(&root.value());
}

std::string gametree_t::toPgn() const
{
    std::string pgn = "";
    for (auto &tag : tags)
    {
        pgn += "[" + std::string(tag.key) + " \"" + std::string(tag.value) + "\"]\n";
    }
    auto root = getRoot();
    if (!root.has_value())
        return pgn;

    pgn += "\n" + to_pgn_string(&root.value());
    // if last non whitespace character is not a checkmate symbol, add *
    if (pgn.back() != '#' && pgn.back() != '+')
        pgn += "*";
    return pgn;
}

u64 gametree_t::getHash() const
{
    auto root = getRoot();
    if (!root.has_value())
        return 0;
    return to_hash(&root.value());
}

void gametree_t::setCurrent(movetree_t *move, bool setLine)
{
    current = move;
    if (setLine)
    {
        current->setLine();
    }
}

std::optional<movetree_t> gametree_t::makeMove(move_t &move, bool setLine)
{
    if (current == nullptr)
        return std::nullopt;

    auto game = getPosition();

    if (!game.makeMove(move))
        return std::nullopt;

    current = current->addChild({game.getState(), move});
    if (setLine)
        current->setLine();
    return *current;
}

std::optional<movetree_t> gametree_t::overwriteMove(move_t &move)
{
    if (current == nullptr)
        return std::nullopt;

    auto next = current->getNext();
    if (next == nullptr)
        return makeMove(move);

    auto game = getPosition();
    if (!game.makeMove(move))
        return std::nullopt;

    next->setData({game.getState(), move});
    return *next;
}

std::optional<movetree_t> gametree_t::undoMove(bool setLine)
{
    if (current == nullptr)
        return std::nullopt;
    auto prev = current->getParent();
    if (prev == nullptr)
        return std::nullopt;
    current = prev;
    if (setLine)
        current->setLine();
    return *current;
}

std::optional<movetree_t> gametree_t::redoMove(bool setLine)
{
    if (current == nullptr)
        return std::nullopt;
    auto next = current->getNext();
    if (next == nullptr)
        return std::nullopt;
    current = next;
    if (setLine)
        current->setLine();
    return *current;
}

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
            board = ATTACK_BOARDS.knight[target_index];
            break;
        }
        case K:
        case k:
        {
            board = ATTACK_BOARDS.king[target_index];
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

        board &= source_mask;
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

movetree_t *parse_turn(EnhancedPGNParser::TurnContext *turn, movetree_t *movetree)
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
            m = parse_turn(turn, m);
        }
    }
    return mt;
}

int gametrees_from_pgn(gametree_t **gametrees, const char *pgn)
{
    auto trees = gametree_t::FromPgn(pgn);
    *gametrees = new gametree_t[trees.size()];
    memccpy(*gametrees, trees.data(), (int)trees.size(), sizeof(gametree_t));
    return (int)trees.size();
}

gametree_t *gametree_new()
{
    return new gametree_t();
}

void gametree_free(gametree_t *tree)
{
    delete tree;
}

movetree_t *gametree_make_move(gametree_t *tree, move_t *move)
{
    auto result = tree->makeMove(*move);
    if (!result.has_value())
        return nullptr;
    return tree->current;
}

movetree_t *gametree_undo_move(gametree_t *tree)
{
    auto result = tree->undoMove();
    if (!result.has_value())
        return nullptr;
    return tree->current;
}

movetree_t *gametree_redo_move(gametree_t *tree)
{
    auto result = tree->redoMove();
    if (!result.has_value())
        return nullptr;
    return tree->current;
}

movetree_t *gametree_overwrite_move(gametree_t *tree, move_t *move)
{
    auto result = tree->overwriteMove(*move);
    if (!result.has_value())
        return nullptr;
    return tree->current;
}

movetree_t *gametree_get_current(gametree_t *tree)
{
    return tree->current;
}

movetree_t *gametree_get_root(gametree_t *tree)
{
    auto root = tree->current;
    if (root == nullptr)
        return nullptr;
    auto parent = root->getParent();
    while (parent != nullptr)
    {
        root = parent;
        parent = root->getParent();
    }
    return root;
}

movetree_t *gametree_get_next(gametree_t *tree)
{
    if (tree->current == nullptr)
        return nullptr;
    return tree->current->getNext();
}

movetree_t *gametree_get_prev(gametree_t *tree)
{
    if (tree->current == nullptr)
        return nullptr;
    return tree->current->getParent();
}

void gametree_get_position(gametree_t *tree, game_state_t *state)
{
    *state = tree->getPosition().getState();
}

int gametree_to_pgn(gametree_t *tree, pgn_token_t **tokens)
{
    auto pgn = tree->getPgnTokens();
    *tokens = new pgn_token_t[pgn.size()];
    memccpy(*tokens, pgn.data(), (int)pgn.size(), sizeof(pgn_token_t));
    return (int)pgn.size();
}

void gametree_set_current(gametree_t *tree, movetree_t *move, int setLine)
{
    tree->setCurrent(move, setLine);
}

std::vector<pgn_token_t> to_pgn_tokens(movetree_t *moves)
{
    std::vector<pgn_token_t> tokens;
    auto to_san = [](game_state_t state, move_t move, Bitboard pieces, Bitboard occupancies)
    {
        std::string san = "";
        if (state.side == BLACK)
            san += std::to_string(state.full_move_number) + ". ";

        if (move.castling & e_castling::KCA)
            return san + "O-O ";
        if (move.castling & e_castling::QCA)
            return san + "O-O-O ";

        if (move.piece != e_piece::P && move.piece != e_piece::p)
            san += ASCII_PIECES[move.piece % 6];
        // if more than one piece can move to the target square

        Bitboard attacks;
        if (move.piece == e_piece::P)
            attacks = ATTACK_BOARDS.pawn[BLACK][move.target];
        else if (move.piece == e_piece::p)
            attacks = ATTACK_BOARDS.pawn[WHITE][move.target];
        else if (move.piece == e_piece::N || move.piece == e_piece::n)
            attacks = ATTACK_BOARDS.knight[move.target];
        else if (move.piece == e_piece::K || move.piece == e_piece::k)
            attacks = ATTACK_BOARDS.king[move.target];
        else if (move.piece == e_piece::B || move.piece == e_piece::b)
            get_bishop_attacks(&attacks, move.target, occupancies);
        else if (move.piece == e_piece::R || move.piece == e_piece::r)
            get_rook_attacks(&attacks, move.target, occupancies);
        else if (move.piece == e_piece::Q || move.piece == e_piece::q)
            get_queen_attacks(&attacks, move.target, occupancies);

        Bitboard is_attacked = pieces & attacks;
        int n_attacks = is_attacked.count();
        int row = move.source / 8;
        int col = move.source % 8;
        Bitboard row_board = 0xFFULL << (row * 8);
        Bitboard col_board = 0x0101010101010101ULL << col;
        bool same_row = Bitboard(row_board & is_attacked).count() > 1;
        bool same_col = Bitboard(col_board & is_attacked).count() > 1;

        // std::stringstream ss;
        // ss << "piece: " << ASCII_PIECES[move.piece] << " target: " << CHAR_SQUARE_MAP[move.target] << std::endl;
        // ss << "Pieces:\n"
        //    << pieces << std::endl;
        // ss << "Attacks:\n"
        //    << attacks << std::endl;
        // ss << "Is Attacked:\n"
        //    << is_attacked << std::endl;
        // ss << "N Attacks: " << n_attacks << std::endl;

        if (move.capture != e_piece::no_piece)
        {
            if (move.piece == e_piece::P || move.piece == e_piece::p)
            {
                san += (char)(move.source % 8 + 'a');
            }
            else if (n_attacks > 1)
            {
                if (same_row)
                    san += (char)(move.source % 8 + 'a');
                if (same_col)
                    san += (char)((64 - move.source) / 8 + '1');
                if (!same_row && !same_col)
                    san += (char)(move.source % 8 + 'a');
            }
            san += "x";
        }
        else if (move.piece != e_piece::P && move.piece != e_piece::p && n_attacks > 1)
        {
            if (same_row)
                san += (char)(move.source % 8 + 'a');
            if (same_col)
                san += (char)((64 - move.source) / 8 + '1');
            if (!same_row && !same_col)
                san += (char)(move.source % 8 + 'a');
        }

        san += CHAR_SQUARE_MAP[move.target];

        if (move.promotion != e_piece::no_piece)
        {
            san += "=";
            san += ASCII_PIECES[move.promotion % 6];
        }

        if (move.checkmate)
            san += "#";
        else if (move.check)
            san += "+";
        san += " ";
        return san;
    };

    if (moves->getParent() == nullptr)
    {
        auto children = moves->getChildren();
        if (!children.size())
            return tokens;
        moves = children[0];
    }

    bool newLine = false;
    while (moves != nullptr)
    {
        auto *parent = moves->getParent();
        game_t preboard(parent->getData().state);
        auto state = moves->getData().state;
        auto move = moves->getData().move;

        pgn_token_t token{
            .move = moves,
            .newline = newLine,
            .alternate_start = false,
            .alternate_end = 0};
        auto san = to_san(state, move, preboard.state.pieces[move.piece], preboard.state.occupancies[BOTH]);
        strcpy(token.san, san.c_str());
        newLine = false;
        tokens.push_back(token);

        auto children = parent->getChildren();
        if (children.size() > 1 && children[0] == moves)
        {
            newLine = true;
            for (size_t i = 1; i < children.size(); i++)
            {
                auto &child = children[i];
                auto state = child->getData().state;
                std::string prepend = "";
                if (state.side == WHITE)
                    prepend = std::to_string(state.full_move_number - 1) + "... ";
                auto child_tokens = to_pgn_tokens(child);
                if (child_tokens.size())
                {
                    std::string san = prepend + std::string(child_tokens[0].san);
                    strcpy(child_tokens[0].san, san.c_str());
                    child_tokens[0].alternate_start = true;
                    child_tokens[0].newline = true;
                    child_tokens.back().alternate_end += 1;
                    tokens.insert(tokens.end(), child_tokens.begin(), child_tokens.end());
                }
            }
        }
        children = moves->getChildren();
        moves = children.size() ? children[0] : nullptr;
    }
    return tokens;
}

std::string to_pgn_string(movetree_t *moves)
{
    std::string pgn = "";
    auto to_san = [](game_state_t state, move_t move, Bitboard pieces, Bitboard occupancies)
    {
        std::string san = "";
        if (state.side == BLACK)
            san += std::to_string(state.full_move_number) + ". ";

        if (move.castling & e_castling::KCA)
            return san + "O-O";
        if (move.castling & e_castling::QCA)
            return san + "O-O-O";

        if (move.piece != e_piece::P && move.piece != e_piece::p)
            san += ASCII_PIECES[move.piece % 6];
        // if more than one piece can move to the target square

        Bitboard attacks;
        if (move.piece == e_piece::P)
            attacks = ATTACK_BOARDS.pawn[BLACK][move.target];
        else if (move.piece == e_piece::p)
            attacks = ATTACK_BOARDS.pawn[WHITE][move.target];
        else if (move.piece == e_piece::N || move.piece == e_piece::n)
            attacks = ATTACK_BOARDS.knight[move.target];
        else if (move.piece == e_piece::K || move.piece == e_piece::k)
            attacks = ATTACK_BOARDS.king[move.target];
        else if (move.piece == e_piece::B || move.piece == e_piece::b)
            get_bishop_attacks(&attacks, move.target, occupancies);
        else if (move.piece == e_piece::R || move.piece == e_piece::r)
            get_rook_attacks(&attacks, move.target, occupancies);
        else if (move.piece == e_piece::Q || move.piece == e_piece::q)
            get_queen_attacks(&attacks, move.target, occupancies);

        Bitboard is_attacked = pieces & attacks;
        int n_attacks = is_attacked.count();
        int row = move.source / 8;
        int col = move.source % 8;
        Bitboard row_board = 0xFFULL << (row * 8);
        Bitboard col_board = 0x0101010101010101ULL << col;
        bool same_row = Bitboard(row_board & is_attacked).count() > 1;
        bool same_col = Bitboard(col_board & is_attacked).count() > 1;

        // std::stringstream ss;
        // ss << "piece: " << ASCII_PIECES[move.piece] << " target: " << CHAR_SQUARE_MAP[move.target] << std::endl;
        // ss << "Pieces:\n"
        //    << pieces << std::endl;
        // ss << "Attacks:\n"
        //    << attacks << std::endl;
        // ss << "Is Attacked:\n"
        //    << is_attacked << std::endl;
        // ss << "N Attacks: " << n_attacks << std::endl;

        if (move.capture != e_piece::no_piece)
        {
            if (move.piece == e_piece::P || move.piece == e_piece::p)
            {
                san += (char)(move.source % 8 + 'a');
            }
            else if (n_attacks > 1)
            {
                if (same_row)
                    san += (char)(move.source % 8 + 'a');
                if (same_col)
                    san += (char)((64 - move.source) / 8 + '1');
                if (!same_row && !same_col)
                    san += (char)(move.source % 8 + 'a');
            }
            san += "x";
        }
        else if (move.piece != e_piece::P && move.piece != e_piece::p && n_attacks > 1)
        {
            if (same_row)
                san += (char)(move.source % 8 + 'a');
            if (same_col)
                san += (char)((64 - move.source) / 8 + '1');
            if (!same_row && !same_col)
                san += (char)(move.source % 8 + 'a');
        }

        san += CHAR_SQUARE_MAP[move.target];

        if (move.promotion != e_piece::no_piece)
        {
            san += "=";
            san += ASCII_PIECES[move.promotion % 6];
        }

        if (move.checkmate)
            san += "#";
        else if (move.check)
            san += "+";
        return san;
    };

    if (moves->getParent() == nullptr)
    {
        auto children = moves->getChildren();
        if (!children.size())
            return pgn;
        moves = children[0];
    }

    while (moves != nullptr)
    {
        auto *parent = moves->getParent();
        game_t preboard(parent->getData().state);
        auto state = moves->getData().state;
        auto move = moves->getData().move;

        pgn += to_san(state, move, preboard.state.pieces[move.piece], preboard.state.occupancies[BOTH]);

        auto children = parent->getChildren();
        if (children.size() > 1 && children[0] == moves)
        {
            for (size_t i = 1; i < children.size(); i++)
            {
                auto &child = children[i];
                auto state = child->getData().state;
                std::string prepend = " (";
                if (state.side == WHITE)
                    prepend += std::to_string(state.full_move_number - 1) + "... ";
                pgn += prepend + to_pgn_string(child) + ")";
            }
        }
        pgn += " ";
        children = moves->getChildren();
        moves = children.size() ? children[0] : nullptr;
    }
    return pgn;
}

bool compare_moves(const move_t &move1, const move_t &move2)
{
    return move1.capture == move2.capture &&
           move1.castling == move2.castling &&
           move1.check == move2.check &&
           move1.checkmate == move2.checkmate &&
           move1.draw == move2.draw &&
           move1.enpassant == move2.enpassant &&
           move1.fifty_move == move2.fifty_move &&
           move1.gameover == move2.gameover &&
           move1.piece == move2.piece &&
           move1.promotion == move2.promotion &&
           move1.source == move2.source &&
           move1.stalemate == move2.stalemate &&
           move1.target == move2.target &&
           move1.threefold_repetition == move2.threefold_repetition;
}

// Function to compare two nodes
bool compare_nodes(const movetree_t *node1, const movetree_t *node2)
{
    // If both nodes are nullptr, they are equal
    if (node1 == nullptr && node2 == nullptr)
    {
        return true;
    }

    // If one node is nullptr and the other is not, they are not equal
    if (node1 == nullptr || node2 == nullptr)
    {
        return false;
    }

    if (!compare_moves(node1->getData().move, node2->getData().move))
    {
        return false;
    }

    if (node1->getData().state.hash != node2->getData().state.hash)
    {
        return false;
    }

    auto children1 = node1->getChildren();
    auto children2 = node2->getChildren();

    // Recursively compare children
    if (children1.size() != children2.size())
    {
        return false;
    }

    for (size_t i = 0; i < children1.size(); ++i)
    {
        if (!compare_nodes(children1[i], children2[i]))
        {
            return false;
        }
    }

    return true;
}

u64 to_hash(movetree_t *node)
{
    u64 hash = 0;
    if (node == nullptr)
        return hash;
    hash ^= node->getData().state.hash;
    for (auto child : node->getChildren())
    {
        hash ^= to_hash(child);
    }
    return hash;
}