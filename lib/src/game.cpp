#include "game.h"
#include "constants.h"
#include "attacks.h"
#include <iostream>
#include <sstream>
#include <vector>

const char *STARTING_FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

game_t::game_t()
{
    state.castling = 0;
    state.enpassant = no_sq;
    state.side = WHITE;
    state.half_move_clock = 0;
    state.full_move_number = 0;
    for (int i = 0; i < 12; i++)
    {
        state.pieces[i] = 0ULL;
    }
    for (int i = 0; i < 3; i++)
    {
        state.occupancies[i] = 0ULL;
    }
    attack_boards_init();
    hash_keys_init();
}

game_t::game_t(const game_state_t &state)
{
    this->state = state;
    attack_boards_init();
    hash_keys_init();
}

game_t game_t::FromFEN(const char *fen)
{
    std::stringstream ss(fen);
    std::vector<std::string> tokens;
    std::string token;

    while (std::getline(ss, token, ' '))
    {
        tokens.push_back(token);
    }

    game_t g;

    // Parse pieces
    int rank = 0;
    int file = 0;

    for (auto c : tokens[0])
    {
        if (c == '/')
        {
            rank++;
            file = 0;
        }
        else if (isdigit(c))
        {
            file += c - '0';
        }
        else
        {
            int piece = CHAR_EPIECE_MAP[(int)c];
            g.state.pieces[piece].set(rank * 8 + file);
            file++;
        }
    }

    // Parse side
    g.state.side = (tokens[1] == "w") ? WHITE : BLACK;

    // Parse castling
    for (auto c : tokens[2])
    {
        switch (c)
        {
        case 'K':
            g.state.castling |= WKCA;
            break;
        case 'Q':
            g.state.castling |= WQCA;
            break;
        case 'k':
            g.state.castling |= BKCA;
            break;
        case 'q':
            g.state.castling |= BQCA;
            break;
        default:
            break;
        }
    }

    // Parse enpassant
    if (tokens[3] != "-")
    {
        int rank = 8 - (tokens[3][1] - '0');
        int file = tokens[3][0] - 'a';
        g.state.enpassant = rank * 8 + file;
    }

    // Parse half move clock
    g.state.half_move_clock = (uint8_t)std::stoi(tokens[4]);

    // Parse full move number
    g.state.full_move_number = (uint8_t)std::stoi(tokens[5]);

    g.state.occupancies[WHITE] = g.state.pieces[P] | g.state.pieces[N] | g.state.pieces[B] | g.state.pieces[R] | g.state.pieces[Q] | g.state.pieces[K];
    g.state.occupancies[BLACK] = g.state.pieces[p] | g.state.pieces[n] | g.state.pieces[b] | g.state.pieces[r] | g.state.pieces[q] | g.state.pieces[k];
    g.state.occupancies[BOTH] = g.state.occupancies[WHITE] | g.state.occupancies[BLACK];

    g.state.hash = g.generateHashKey();

    return g;
}

game_t game_t::FromStartingPosition()
{
    return game_t::FromFEN(STARTING_FEN);
}

std::string game_t::ToPGN(movetree_t *moves)
{
    std::string san = "";
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

    while (moves != nullptr)
    {
        auto *parent = moves->getParent();
        if (parent != nullptr)
        {
            game_t preboard(parent->getData().state);
            auto state = moves->getData().state;
            auto move = moves->getData().move;

            san += to_san(state, move, preboard.state.pieces[move.piece], preboard.state.occupancies[BOTH]);

            auto children = parent->getChildren();
            if (children.size() && children[0] == moves)
            {
                for (size_t i = 1; i < children.size(); i++)
                {
                    auto &child = children[i];
                    san += "(";
                    auto state = child->getData().state;
                    if (state.side == WHITE)
                        san += std::to_string(state.full_move_number - 1) + "... ";
                    san += ToPGN(child) + ")";
                }
            }
        }

        auto children = moves->getChildren();
        moves = children.size() ? children[0] : nullptr;
    }
    return san;
}

uint8_t game_t::isAttacked(int square, int side) const
{
    auto &attacks = ATTACK_BOARDS;
    Bitboard pawns, knights, kings, bishops, rooks, queens;
    if (side == WHITE)
    {
        pawns = state.pieces[P];
        knights = state.pieces[N];
        kings = state.pieces[K];
        bishops = state.pieces[B];
        rooks = state.pieces[R];
        queens = state.pieces[Q];
    }
    else
    {
        pawns = state.pieces[p];
        knights = state.pieces[n];
        kings = state.pieces[k];
        bishops = state.pieces[b];
        rooks = state.pieces[r];
        queens = state.pieces[q];
    }
    if (attacks.pawn[1 - side][square] & pawns)
        return 1;
    if (attacks.knight[square] & knights)
        return 1;
    if (attacks.king[square] & kings)
        return 1;
    Bitboard board;
    get_bishop_attacks(&board, square, state.occupancies[BOTH]);
    if (board & bishops)
        return 1;
    get_rook_attacks(&board, square, state.occupancies[BOTH]);
    if (board & rooks)
        return 1;
    get_queen_attacks(&board, square, state.occupancies[BOTH]);
    if (board & queens)
        return 1;
    return 0;
}

bool game_t::isInCheck() const
{
    int king_square = (state.side == WHITE) ? state.pieces[K].ls1b() : state.pieces[k].ls1b();
    return isAttacked(king_square, 1 - state.side);
}

bool game_t::isCheckmated() const
{
    if (!isInCheck())
        return false;
    int start = (state.side == WHITE) ? P : p;
    int end = (state.side == WHITE) ? K : k;
    for (int piece = start; piece <= end; piece++)
    {
        Bitboard bb = state.pieces[piece];
        int square = bb.popls1b();
        while (square != -1)
        {
            if (generateMoves(state.side, piece, square).size() > 0)
                return false;
            square = bb.popls1b();
        }
    }
    return true;
}

bool game_t::getPiece(int square, int &piece, int &side) const
{
    for (piece = P; piece <= k; piece++)
    {
        if (state.pieces[piece] & (1ULL << square))
        {
            side = (piece < p) ? WHITE : BLACK;
            return true;
        }
    }
    return false;
}

bool game_t::generatePseudoMoves(std::vector<move_t> &moves, int side, int piece, int square) const
{
    if (piece >= no_piece)
        return false;
    if (side >= BOTH)
        return false;
    if (!state.pieces[piece][square])
        return false;

    auto &attacks = ATTACK_BOARDS;

    // generate pawn moves
    if (piece == P || piece == p)
    {
        int target = square + (side == WHITE ? -8 : 8);
        if (target < 0 || target > 63)
            return true;

        std::vector<uint> promotions;
        if (target < 8 || target >= 56)
        {
            for (int promotion = N; promotion <= Q; promotion++)
            {
                promotions.push_back(promotion + (side == WHITE ? 0 : 6));
            }
        }
        else
        {
            promotions.push_back((uint)no_piece);
        }

        // no piece on target square
        if (state.occupancies[BOTH][target] == 0)
        {
            for (auto promotion : promotions)
            {
                moves.push_back({
                    .source = (uint)square,
                    .target = (uint)target,
                    .piece = (uint)piece,
                    .promotion = promotion,
                    .capture = (uint)no_piece,
                });
            }

            // square rank
            int rank = square / 8;
            int starting_row = (side == WHITE ? 6 : 1);
            // double push
            int dtarget = square + (side == WHITE ? -16 : 16);

            // if pawn on starting row and no piece on double push square
            if (rank == starting_row && state.occupancies[BOTH][dtarget] == 0)
            {
                moves.push_back({
                    .source = (uint)square,
                    .target = (uint)dtarget,
                    .piece = (uint)piece,
                    .double_push = 1,
                    .promotion = (uint)no_piece,
                    .capture = (uint)no_piece,
                });
            }
        }

        // attacks
        Bitboard pawn_attacks = attacks.pawn[side][square] & state.occupancies[1 - side];

        // loop over pawn attacks
        while (pawn_attacks)
        {
            // init target square
            int target = pawn_attacks.ls1b();
            pawn_attacks.pop(target);
            int tpiece, tside;
            if (!getPiece(target, tpiece, tside))
                throw std::runtime_error("getPiece failed in generatePseudoMoves");

            for (auto promotion : promotions)
            {
                moves.push_back({
                    .source = (uint)square,
                    .target = (uint)target,
                    .piece = (uint)piece,
                    .capture = (uint)tpiece,
                    .promotion = promotion,
                });
            }
        }

        // enpassant
        if (state.enpassant != no_sq)
        {
            if (attacks.pawn[side][square] & (1ULL << state.enpassant))
            {
                moves.push_back({
                    .source = (uint)square,
                    .target = (uint)state.enpassant,
                    .piece = (uint)piece,
                    .capture = (uint)(side == WHITE ? p : P),
                    .enpassant = 1,
                    .promotion = (uint)no_piece,
                });
            }
        }
        return true;
    }

    for (int p = N; p <= K; p++)
    {
        if (piece != p && piece != p + 6)
            continue;

        Bitboard attacking_squares;
        switch (p)
        {
        case N:
        {
            attacking_squares = attacks.knight[square];
            break;
        }
        case B:
        {
            get_bishop_attacks(&attacking_squares, square, state.occupancies[BOTH]);
            break;
        }
        case R:
        {
            get_rook_attacks(&attacking_squares, square, state.occupancies[BOTH]);
            break;
        }
        case Q:
        {
            get_queen_attacks(&attacking_squares, square, state.occupancies[BOTH]);
            break;
        }
        case K:
        {
            attacking_squares = attacks.king[square];
            break;
        }
        default:
            throw std::runtime_error("Invalid piece in generatePseudoMoves");
        }

        // loop over quiet moves
        Bitboard quiet_moves = attacking_squares & ~state.occupancies[BOTH];
        while (quiet_moves)
        {
            int target = quiet_moves.ls1b();
            quiet_moves.pop(target);
            moves.push_back({
                .source = (uint)square,
                .target = (uint)target,
                .piece = (uint)piece,
                .promotion = (uint)no_piece,
                .capture = (uint)no_piece,
            });
        }

        // loop over captures
        Bitboard captures = attacking_squares & state.occupancies[1 - side];
        while (captures)
        {
            int target = captures.ls1b();
            captures.pop(target);
            int tpiece, tside;
            if (!getPiece(target, tpiece, tside))
                throw std::runtime_error("getPiece failed in generatePseudoMoves");
            moves.push_back({
                .source = (uint)square,
                .target = (uint)target,
                .piece = (uint)piece,
                .capture = (uint)tpiece,
                .promotion = (uint)no_piece,
            });
        }
    }

    // castling
    if (piece == K || piece == k)
    {
        if (side == WHITE)
        {
            // king side
            bool canCastle = (state.castling & WKCA);
            bool occpuied = state.occupancies[BOTH][f1] || state.occupancies[BOTH][g1];
            bool attacked = isAttacked(e1, BLACK) || isAttacked(f1, BLACK);
            if (canCastle && !occpuied && !attacked)
            {
                moves.push_back({
                    .source = (uint)square,
                    .target = (uint)g1,
                    .piece = (uint)piece,
                    .castling = (uint)WKCA,
                    .promotion = (uint)no_piece,
                    .capture = (uint)no_piece,
                });
            }

            // queen side
            canCastle = (state.castling & WQCA);
            occpuied = state.occupancies[BOTH][b1] || state.occupancies[BOTH][c1] || state.occupancies[BOTH][d1];
            attacked = isAttacked(e1, BLACK) || isAttacked(d1, BLACK);

            if (canCastle && !occpuied && !attacked)
            {
                moves.push_back({
                    .source = (uint)square,
                    .target = (uint)c1,
                    .piece = (uint)piece,
                    .castling = (uint)WQCA,
                    .promotion = (uint)no_piece,
                    .capture = (uint)no_piece,
                });
            }
            // black
        }
        else
        {
            // king side
            bool canCastle = (state.castling & BKCA);
            bool occpuied = state.occupancies[BOTH][f8] || state.occupancies[BOTH][g8];
            bool attacked = isAttacked(e8, WHITE) || isAttacked(f8, WHITE);

            if (canCastle && !occpuied && !attacked)
            {
                moves.push_back({
                    .source = (uint)square,
                    .target = (uint)g8,
                    .piece = (uint)piece,
                    .castling = (uint)BKCA,
                    .promotion = (uint)no_piece,
                    .capture = (uint)no_piece,
                });
            }

            // queen side
            canCastle = (state.castling & BQCA);
            occpuied = state.occupancies[BOTH][b8] || state.occupancies[BOTH][c8] || state.occupancies[BOTH][d8];
            attacked = isAttacked(e8, WHITE) || isAttacked(d8, WHITE);

            if (canCastle && !occpuied && !attacked)
            {
                moves.push_back({
                    .source = (uint)square,
                    .target = (uint)c8,
                    .piece = (uint)piece,
                    .castling = (uint)BQCA,
                    .promotion = (uint)no_piece,
                    .capture = (uint)no_piece,
                });
            }
        }
    }
    return true;
}

bool game_t::generatePseudoMoves(std::vector<move_t> &moves, int square) const
{
    int piece, side;
    if (!getPiece(square, piece, side))
        return false;
    return generatePseudoMoves(moves, side, piece, square);
}

bool game_t::makeMove(move_t &move, bool validate)
{
    if (!validate)
        return simulateMove(move, this);
    std::vector<move_t> moves;
    bool pseudo = (move.piece >= no_piece) ? generatePseudoMoves(moves, move.source) : generatePseudoMoves(moves, state.side, move.piece, move.source);
    if (!pseudo)
        return false;

    // find move with source and target in moves
    auto it = std::find_if(moves.begin(), moves.end(), [&](const move_t &m)
                           { return m.source == move.source && m.target == move.target && m.promotion == move.promotion; });

    if (it == moves.end())
        return false;
    move = *it;
    return simulateMove(move, this);
}

std::vector<move_t> game_t::generateMoves(int side, int piece, int square) const
{
    std::vector<move_t> moves;
    if (this->state.side != side)
        return moves;
    std::vector<move_t> pseudo_moves;
    if (!generatePseudoMoves(pseudo_moves, side, piece, square))
        return moves;

    for (auto &move : pseudo_moves)
    {
        game_t g;
        if (simulateMove(move, &g))
        {
            moves.push_back(move);
        }
    }

    return moves;
}

std::vector<move_t> game_t::generateMoves(int square) const
{
    int piece, side;
    if (!getPiece(square, piece, side))
        return std::vector<move_t>();
    return generateMoves(side, piece, square);
}

void game_t::printAttackedSquares(int side) const
{
    for (int rank = 0; rank <= 7; rank++)
    {
        printf("%d ", 8 - rank);
        for (int file = 0; file <= 7; file++)
        {
            int square = rank * 8 + file;
            printf("%c ", (isAttacked(square, side)) ? '1' : '0');
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n\n");
}

std::string game_t::toFEN() const
{
    auto b = state.occupancies[BOTH];
    int fen_index = 0;
    int i = b.popls1b();
    std::stringstream ss;
    while (i > -1)
    {
        int gap = i - fen_index;
        int row_gap = 8 - (fen_index % 8);
        fen_index += gap + 1;
        if (row_gap <= gap)
        {
            ss << row_gap << "/";
            gap -= row_gap;
        }
        while (gap > 7)
        {
            ss << "8/";
            gap -= 8;
        }

        if (gap > 0)
            ss << gap;

        int piece, side;
        getPiece(i, piece, side);
        ss << ASCII_PIECES[piece];
        if (fen_index % 8 == 0 && fen_index < 64)
            ss << "/";
        i = b.popls1b();
    }

    ss << " " << (state.side == WHITE ? "w" : "b") << " ";
    std::string c = "KQkq";
    bool none = true;
    for (int i = 0; i < 4; i++)
    {
        if (state.castling & (1 << i))
        {
            ss << c[i];
            none = false;
        }
    }

    if (none)
        ss << "-";

    ss << " ";
    if (state.enpassant == no_sq)
        ss << "-";
    else
    {
        int rank = 8 - (state.enpassant / 8);
        int file = state.enpassant % 8;
        ss << (char)('a' + file) << rank;
    }

    ss << " " << (int)state.half_move_clock << " " << (int)state.full_move_number;
    return ss.str();
}

game_state_t game_t::getState() const
{
    return state;
}

u64 game_t::generateHashKey() const
{
    // final hash key
    u64 final_key = 0ULL;

    // temp piece bitboard copy
    Bitboard bitboard;

    // loop over piece bitboards
    for (int piece = P; piece <= k; piece++)
    {
        // init piece bitboard copy
        bitboard = state.pieces[piece];

        // loop over the pieces within a bitboard
        while (bitboard)
        {
            // init square occupied by the piece
            int square = bitboard.ls1b();

            // hash piece
            final_key ^= HASH_KEYS.piece[piece][square];

            // pop LS1B
            bitboard.pop(square);
        }
    }

    // if enpassant square is on board
    if (state.enpassant != no_sq)
        // hash enpassant
        final_key ^= HASH_KEYS.enpassant[state.enpassant];

    // hash castling rights
    final_key ^= HASH_KEYS.castle[state.castling];

    // hash the side only if black is to move
    if (state.side == BLACK)
        final_key ^= HASH_KEYS.side;

    // return generated hash key
    return final_key;
}

bool game_t::operator==(const game_t &g) const
{
    if (state.castling != g.state.castling)
        return false;
    if (state.enpassant != g.state.enpassant)
        return false;
    if (state.side != g.state.side)
        return false;
    if (state.half_move_clock != g.state.half_move_clock)
        return false;
    if (state.full_move_number != g.state.full_move_number)
        return false;
    for (int i = 0; i < 12; i++)
    {
        if (state.pieces[i] != g.state.pieces[i])
            return false;
    }

    for (int i = 0; i < 3; i++)
    {
        if (state.occupancies[i] != g.state.occupancies[i])
            return false;
    }
    return true;
}

bool game_t::simulateMove(move_t &move, game_t *game) const
{
    // copy game
    game_t g = *this;

    // move piece
    g.state.pieces[move.piece].pop(move.source);
    g.state.pieces[move.piece].set(move.target);
    g.state.hash ^= HASH_KEYS.piece[move.piece][move.source];
    g.state.hash ^= HASH_KEYS.piece[move.piece][move.target];

    // increment half move clock
    g.state.half_move_clock++;

    if (move.piece == P || move.piece == p)
        // reset half move clock
        g.state.half_move_clock = 0;

    // enpassant
    if (move.enpassant)
    {
        g.state.half_move_clock = 0;
        int enpassant = (g.state.side == WHITE) ? move.target + 8 : move.target - 8;
        g.state.pieces[move.capture].pop(enpassant);
        g.state.hash ^= HASH_KEYS.piece[move.capture][enpassant];
    }
    else if (move.capture != no_piece)
    {
        g.state.half_move_clock = 0;
        g.state.pieces[move.capture].pop(move.target);
        g.state.hash ^= HASH_KEYS.piece[move.capture][move.target];
    }

    // promotion
    if (move.promotion != no_piece)
    {
        g.state.pieces[move.piece].pop(move.target);
        g.state.pieces[move.promotion].set(move.target);
        g.state.hash ^= HASH_KEYS.piece[move.piece][move.target];
        g.state.hash ^= HASH_KEYS.piece[move.promotion][move.target];
    }

    if (state.enpassant != no_sq)
        g.state.hash ^= HASH_KEYS.enpassant[state.enpassant];

    // double push
    if (move.double_push)
    {
        g.state.enpassant = (move.target + move.source) / 2;
        g.state.hash ^= HASH_KEYS.enpassant[g.state.enpassant];
    }
    else
    {
        g.state.enpassant = no_sq;
    }

    switch (move.castling)
    {
    case WKCA:
        g.state.pieces[R].pop(h1);
        g.state.pieces[R].set(f1);
        g.state.hash ^= HASH_KEYS.piece[R][h1];
        g.state.hash ^= HASH_KEYS.piece[R][f1];
        break;
    case WQCA:
        g.state.pieces[R].pop(a1);
        g.state.pieces[R].set(d1);
        g.state.hash ^= HASH_KEYS.piece[R][a1];
        g.state.hash ^= HASH_KEYS.piece[R][d1];
        break;
    case BKCA:
        g.state.pieces[r].pop(h8);
        g.state.pieces[r].set(f8);
        g.state.hash ^= HASH_KEYS.piece[r][h8];
        g.state.hash ^= HASH_KEYS.piece[r][f8];
        break;
    case BQCA:
        g.state.pieces[r].pop(a8);
        g.state.pieces[r].set(d8);
        g.state.hash ^= HASH_KEYS.piece[r][a8];
        g.state.hash ^= HASH_KEYS.piece[r][d8];
        break;
    default:
        break;
    }

    g.state.hash ^= HASH_KEYS.castle[state.castling];
    g.state.castling &= CASTLE_RIGHTS[move.source];
    g.state.castling &= CASTLE_RIGHTS[move.target];
    g.state.hash ^= HASH_KEYS.castle[g.state.castling];

    // occupied squares
    g.state.occupancies[WHITE] = g.state.pieces[P] | g.state.pieces[N] | g.state.pieces[B] | g.state.pieces[R] | g.state.pieces[Q] | g.state.pieces[K];
    g.state.occupancies[BLACK] = g.state.pieces[p] | g.state.pieces[n] | g.state.pieces[b] | g.state.pieces[r] | g.state.pieces[q] | g.state.pieces[k];
    g.state.occupancies[BOTH] = g.state.occupancies[WHITE] | g.state.occupancies[BLACK];

    // side to move
    g.state.side ^= 1;
    g.state.hash ^= HASH_KEYS.side;

    // full move number
    if (g.state.side == WHITE)
        g.state.full_move_number++;

    // is king attacked
    const int king = (state.side == WHITE) ? K : k;
    if (g.isAttacked(g.state.pieces[king].ls1b(), g.state.side))
        return false;

    if (g.isCheckmated())
    {
        move.checkmate = 1;
        move.gameover = 1;
    }
    else if (g.isInCheck())
    {
        move.check = 1;
    }

    *game = g;
    return true;
}

std::ostream &operator<<(std::ostream &os, const game_t &g)
{
    // loop over ranks
    for (int rank = 0; rank <= 7; rank++)
    {
        // print rank number
        os << 8 - rank << " ";

        // loop over files
        for (int file = 0; file <= 7; file++)
        {
            // init square
            int square = rank * 8 + file;

            // init piece
            int piece = -1;

            // loop over pieces
            for (int p = P; p <= k; p++)
            {
                // if piece is on square
                if (g.state.pieces[p][square])
                {
                    piece = p;
                    break;
                }
            }

            if (piece == -1)
                os << ". ";
            else
                os << UNICODE_PIECES[piece] << " ";
        }

        // print new line
        os << std::endl;
    }
    os << "  a b c d e f g h" << std::endl;
    return os;
}

void bitboard_print(Bitboard board)
{
    for (int rank = 0; rank <= 7; rank++)
    {
        printf("%d ", 8 - rank);
        for (int file = 0; file <= 7; file++)
        {
            printf("%c ", (board & (1ULL << (rank * 8 + file))) ? '1' : '0');
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n\n");
}

void game_new(game_state_t *game)
{
    *game = game_t::FromStartingPosition().getState();
}

void game_print(const game_state_t game)
{
    game_t g(game);
    std::cout << g;
}
