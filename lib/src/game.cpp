#include "game.h"
#include "constants.h"
#include "movement.h"
#include "keys.h"
#include <iostream>
#include <sstream>
#include <vector>

const char *STARTING_FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

game_t::game_t()
    : castling(0),
      enpassant(no_sq),
      side(WHITE),
      hash(0),
      half_move_clock(0),
      full_move_number(0),
      move_tree(nullptr)
{
    for (int i = 0; i < 12; i++)
    {
        pieces[i] = 0ULL;
    }
    for (int i = 0; i < 3; i++)
    {
        occupancies[i] = 0ULL;
    }
    attack_boards_init();
    hash_keys_init();
}

game_t::game_t(const game_state_t &state)
    : castling(state.castling),
      enpassant(state.enpassant),
      side(state.side),
      half_move_clock(state.half_move_clock),
      full_move_number(state.full_move_number)
{
    for (int i = 0; i < 12; i++)
    {
        pieces[i] = state.pieces[i];
    }
    occupancies[WHITE] = state.pieces[P] | state.pieces[N] | state.pieces[B] | state.pieces[R] | state.pieces[Q] | state.pieces[K];
    occupancies[BLACK] = state.pieces[p] | state.pieces[n] | state.pieces[b] | state.pieces[r] | state.pieces[q] | state.pieces[k];
    occupancies[BOTH] = occupancies[WHITE] | occupancies[BLACK];
}

// game_t::game_t(const game_t &g)
//     : castling{g.castling},
//       enpassant{g.enpassant},
//       side{g.side},
//       hash{g.hash},
//       half_move_clock{g.half_move_clock},
//       full_move_number{g.full_move_number}
// {
//     for (int i = 0; i < 12; i++)
//     {
//         pieces[i] = g.pieces[i];
//     }
//     for (int i = 0; i < 3; i++)
//     {
//         occupancies[i] = g.occupancies[i];
//     }
// }

// game_t &game_t::operator=(const game_t &g)
// {
//     castling = g.castling;
//     enpassant = g.enpassant;
//     side = g.side;
//     hash = g.hash;
//     half_move_clock = g.half_move_clock;
//     full_move_number = g.full_move_number;

//     for (int i = 0; i < 12; i++)
//     {
//         pieces[i] = g.pieces[i];
//     }
//     for (int i = 0; i < 3; i++)
//     {
//         occupancies[i] = g.occupancies[i];
//     }

//     return *this;
// }

// game_t::game_t(game_t &&g)
//     : castling{g.castling},
//       enpassant{g.enpassant},
//       side{g.side},
//       hash{g.hash},
//       half_move_clock{g.half_move_clock},
//       full_move_number{g.full_move_number}
// {
//     for (int i = 0; i < 12; i++)
//     {
//         pieces[i] = g.pieces[i];
//     }
//     for (int i = 0; i < 3; i++)
//     {
//         occupancies[i] = g.occupancies[i];
//     }
// }

// game_t &game_t::operator=(game_t &&g)
// {
//     castling = g.castling;
//     enpassant = g.enpassant;
//     side = g.side;
//     hash = g.hash;
//     half_move_clock = g.half_move_clock;
//     full_move_number = g.full_move_number;

//     for (int i = 0; i < 12; i++)
//     {
//         pieces[i] = g.pieces[i];
//     }
//     for (int i = 0; i < 3; i++)
//     {
//         occupancies[i] = g.occupancies[i];
//     }

//     return *this;
// }

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
            g.pieces[piece].set(rank * 8 + file);
            file++;
        }
    }

    // Parse side
    g.side = (tokens[1] == "w") ? WHITE : BLACK;

    // Parse castling
    for (auto c : tokens[2])
    {
        switch (c)
        {
        case 'K':
            g.castling |= WKCA;
            break;
        case 'Q':
            g.castling |= WQCA;
            break;
        case 'k':
            g.castling |= BKCA;
            break;
        case 'q':
            g.castling |= BQCA;
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
        g.enpassant = rank * 8 + file;
    }

    // Parse half move clock
    g.half_move_clock = (uint8_t)std::stoi(tokens[4]);

    // Parse full move number
    g.full_move_number = (uint8_t)std::stoi(tokens[5]);

    g.occupancies[WHITE] = g.pieces[P] | g.pieces[N] | g.pieces[B] | g.pieces[R] | g.pieces[Q] | g.pieces[K];
    g.occupancies[BLACK] = g.pieces[p] | g.pieces[n] | g.pieces[b] | g.pieces[r] | g.pieces[q] | g.pieces[k];
    g.occupancies[BOTH] = g.occupancies[WHITE] | g.occupancies[BLACK];

    g.hash = g.generateHashKey();
    g.move_tree = new s_tree_t({.move = move_t{
                                    .piece = (uint8_t)no_piece,
                                },
                                .game = g});

    return g;
}

game_t game_t::FromStartingPosition()
{
    return game_t::FromFEN(STARTING_FEN);
}

void game_t::addPiece(int square, int piece)
{
    pieces[piece].set(square);
    for (int side = WHITE; side <= BOTH; side++)
    {
        occupancies[side].set(square);
    }
    hash = generateHashKey();
}

uint8_t game_t::isAttacked(int square, int side) const
{
    auto &attacks = ATTACK_BOARDS;
    Bitboard pawns, knights, kings, bishops, rooks, queens;
    if (side == WHITE)
    {
        pawns = pieces[P];
        knights = pieces[N];
        kings = pieces[K];
        bishops = pieces[B];
        rooks = pieces[R];
        queens = pieces[Q];
    }
    else
    {
        pawns = pieces[p];
        knights = pieces[n];
        kings = pieces[k];
        bishops = pieces[b];
        rooks = pieces[r];
        queens = pieces[q];
    }
    if (attacks.pawn[1 - side][square] & pawns)
        return 1;
    if (attacks.knight[square] & knights)
        return 1;
    if (attacks.king[square] & kings)
        return 1;
    Bitboard board;
    get_bishop_attacks(&board, square, occupancies[BOTH]);
    if (board & bishops)
        return 1;
    get_rook_attacks(&board, square, occupancies[BOTH]);
    if (board & rooks)
        return 1;
    get_queen_attacks(&board, square, occupancies[BOTH]);
    if (board & queens)
        return 1;
    return 0;
}

bool game_t::getPiece(int square, int &piece, int &side) const
{
    for (piece = P; piece <= k; piece++)
    {
        if (pieces[piece] & (1ULL << square))
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
    if (!pieces[piece][square])
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
        if (occupancies[BOTH][target] == 0)
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
            if (rank == starting_row && occupancies[BOTH][dtarget] == 0)
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
        Bitboard pawn_attacks = attacks.pawn[side][square] & occupancies[1 - side];

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
        if (enpassant != no_sq)
        {
            if (attacks.pawn[side][square] & (1ULL << enpassant))
            {
                moves.push_back({
                    .source = (uint)square,
                    .target = (uint)enpassant,
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
            get_bishop_attacks(&attacking_squares, square, occupancies[BOTH]);
            break;
        }
        case R:
        {
            get_rook_attacks(&attacking_squares, square, occupancies[BOTH]);
            break;
        }
        case Q:
        {
            get_queen_attacks(&attacking_squares, square, occupancies[BOTH]);
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
        Bitboard quiet_moves = attacking_squares & ~occupancies[BOTH];
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
        Bitboard captures = attacking_squares & occupancies[1 - side];
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
            bool canCastle = (castling & WKCA);
            bool occpuied = occupancies[BOTH][f1] || occupancies[BOTH][g1];
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
            canCastle = (castling & WQCA);
            occpuied = occupancies[BOTH][b1] || occupancies[BOTH][c1] || occupancies[BOTH][d1];
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
            bool canCastle = (castling & BKCA);
            bool occpuied = occupancies[BOTH][f8] || occupancies[BOTH][g8];
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
            canCastle = (castling & BQCA);
            occpuied = occupancies[BOTH][b8] || occupancies[BOTH][c8] || occupancies[BOTH][d8];
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

bool game_t::simulateMove(const move_t &move, s_tree_t &mt) const
{
    game_t g;
    if (!simulateMove(move, g))
        return false;

    mt = s_tree_t({.move = move,
                   .game = g},
                  move_tree);
    return true;
}

bool game_t::simulateMove(const move_t &move) const
{
    game_t g;
    return simulateMove(move, g);
}

bool game_t::makeMove(move_t &move, bool validate)
{
    if (!validate)
        return simulateMove(move, *this);
    s_tree_t tree;
    if (!validateMove(move, tree))
        return false;
    move_tree = move_tree->AddChild(tree); 
    return true;
}

bool game_t::validateMove(move_t &move, s_tree_t &move_tree) const
{
    std::vector<move_t> moves;
    bool pseudo = (move.piece >= no_piece) ? generatePseudoMoves(moves, move.source) : generatePseudoMoves(moves, side, move.piece, move.source);
    if (!pseudo)
        return false;

    // find move with source and target in moves
    auto it = std::find_if(moves.begin(), moves.end(), [&](const move_t &m)
                           { return m.source == move.source && m.target == move.target && m.promotion == move.promotion; });

    if (it == moves.end())
        return false;

    if (!simulateMove(*it, move_tree))
        return false;

    move = *it;
    return true;
}

bool game_t::generateMoves(s_tree_t &moves, int side, int piece, int square) const
{
    if (this->side != side)
        return false;
    std::vector<move_t> pseudo_moves;
    if (!generatePseudoMoves(pseudo_moves, side, piece, square))
        return false;

    for (auto &move : pseudo_moves)
    {
        game_t g;
        if (simulateMove(move, g))
        {
            moves.AddChild(sample_t{
                .move = move,
                .game = g,
            });
        }
    }

    return false;
}

bool game_t::generateMoves(s_tree_t &moves, int square) const
{
    std::vector<move_t> pseudo_moves;
    if (!generatePseudoMoves(pseudo_moves, square))
        return false;
    for (auto &move : pseudo_moves)
    {
        game_t g;
        if (simulateMove(move, g))
        {
            moves.AddChild(sample_t{
                .move = move,
                .game = g,
            });
        }
    }
    return false;
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
    auto b = occupancies[BOTH];
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

    ss << " " << (side == WHITE ? "w" : "b") << " ";
    std::string c = "KQkq";
    bool none = true;
    for (int i = 0; i < 4; i++)
    {
        if (castling & (1 << i))
        {
            ss << c[i];
            none = false;
        }
    }

    if (none)
        ss << "-";

    ss << " ";
    if (enpassant == no_sq)
        ss << "-";
    else
    {
        int rank = 8 - (enpassant / 8);
        int file = enpassant % 8;
        ss << (char)('a' + file) << rank;
    }

    ss << " " << (int)half_move_clock << " " << (int)full_move_number;
    return ss.str();
}

game_state_t game_t::getState() const
{
    game_state_t state{
        .castling = castling,
        .enpassant = enpassant,
        .side = side,
        .hash = hash,
        .half_move_clock = (uint8_t)half_move_clock,
        .full_move_number = (uint8_t)full_move_number,
    };

    for (int i = 0; i < 12; i++)
    {
        state.pieces[i] = pieces[i];
    }
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
        bitboard = pieces[piece];

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
    if (enpassant != no_sq)
        // hash enpassant
        final_key ^= HASH_KEYS.enpassant[enpassant];

    // hash castling rights
    final_key ^= HASH_KEYS.castle[castling];

    // hash the side only if black is to move
    if (side == BLACK)
        final_key ^= HASH_KEYS.side;

    // return generated hash key
    return final_key;
}

bool game_t::operator==(const game_t &g) const
{
    if (castling != g.castling)
        return false;
    if (enpassant != g.enpassant)
        return false;
    if (side != g.side)
        return false;
    if (half_move_clock != g.half_move_clock)
        return false;
    if (full_move_number != g.full_move_number)
        return false;
    for (int i = 0; i < 12; i++)
    {
        if (pieces[i] != g.pieces[i])
            return false;
    }

    for (int i = 0; i < 3; i++)
    {
        if (occupancies[i] != g.occupancies[i])
            return false;
    }
    return true;
}

bool game_t::simulateMove(const move_t &move, game_t &game) const
{
    // copy game
    game_t g = *this;

    // move piece
    g.pieces[move.piece].pop(move.source);
    g.pieces[move.piece].set(move.target);
    g.hash ^= HASH_KEYS.piece[move.piece][move.source];
    g.hash ^= HASH_KEYS.piece[move.piece][move.target];

    // increment half move clock
    g.half_move_clock++;

    if (move.piece == P || move.piece == p)
        // reset half move clock
        g.half_move_clock = 0;

    // enpassant
    if (move.enpassant)
    {
        g.half_move_clock = 0;
        int enpassant = (g.side == WHITE) ? move.target + 8 : move.target - 8;
        g.pieces[move.capture].pop(enpassant);
        g.hash ^= HASH_KEYS.piece[move.capture][enpassant];
    }
    else if (move.capture != no_piece)
    {
        g.half_move_clock = 0;
        g.pieces[move.capture].pop(move.target);
        g.hash ^= HASH_KEYS.piece[move.capture][move.target];
    }

    // promotion
    if (move.promotion != no_piece)
    {
        g.pieces[move.piece].pop(move.target);
        g.pieces[move.promotion].set(move.target);
        g.hash ^= HASH_KEYS.piece[move.piece][move.target];
        g.hash ^= HASH_KEYS.piece[move.promotion][move.target];
    }

    if (enpassant != no_sq)
        g.hash ^= HASH_KEYS.enpassant[enpassant];

    // double push
    if (move.double_push)
    {
        g.enpassant = (move.target + move.source) / 2;
        g.hash ^= HASH_KEYS.enpassant[g.enpassant];
    }
    else
    {
        g.enpassant = no_sq;
    }

    switch (move.castling)
    {
    case WKCA:
        g.pieces[R].pop(h1);
        g.pieces[R].set(f1);
        g.hash ^= HASH_KEYS.piece[R][h1];
        g.hash ^= HASH_KEYS.piece[R][f1];
        break;
    case WQCA:
        g.pieces[R].pop(a1);
        g.pieces[R].set(d1);
        g.hash ^= HASH_KEYS.piece[R][a1];
        g.hash ^= HASH_KEYS.piece[R][d1];
        break;
    case BKCA:
        g.pieces[r].pop(h8);
        g.pieces[r].set(f8);
        g.hash ^= HASH_KEYS.piece[r][h8];
        g.hash ^= HASH_KEYS.piece[r][f8];
        break;
    case BQCA:
        g.pieces[r].pop(a8);
        g.pieces[r].set(d8);
        g.hash ^= HASH_KEYS.piece[r][a8];
        g.hash ^= HASH_KEYS.piece[r][d8];
        break;
    default:
        break;
    }

    g.hash ^= HASH_KEYS.castle[castling];
    g.castling &= CASTLE_RIGHTS[move.source];
    g.castling &= CASTLE_RIGHTS[move.target];
    g.hash ^= HASH_KEYS.castle[g.castling];

    // occupied squares
    g.occupancies[WHITE] = g.pieces[P] | g.pieces[N] | g.pieces[B] | g.pieces[R] | g.pieces[Q] | g.pieces[K];
    g.occupancies[BLACK] = g.pieces[p] | g.pieces[n] | g.pieces[b] | g.pieces[r] | g.pieces[q] | g.pieces[k];
    g.occupancies[BOTH] = g.occupancies[WHITE] | g.occupancies[BLACK];

    // side to move
    g.side ^= 1;
    g.hash ^= HASH_KEYS.side;

    // full move number
    if (g.side == WHITE)
        g.full_move_number++;

    // is king attacked
    const int king = (side == WHITE) ? K : k;
    if (g.isAttacked(g.pieces[king].ls1b(), g.side))
        return false;
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
                if (g.pieces[p][square])
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

void game_new(game_t *game)
{
    *game = game_t::FromStartingPosition();
}

void game_print(game_t *game)
{
    std::cout << *game;
}
