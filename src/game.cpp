#include "game.hpp"
#include "constants.hpp"
#include "movement.hpp"
#include "keys.hpp"
#include <iostream>
#include <sstream>
#include <vector>

namespace engine
{
    Game::Game()
        : castling{0}, enpassant{ESquare::no_sq}, side{ESide::WHITE}, repetition_table{0}, r_index{0}, hash{0}, halfMoveClock{0}, fullMoveNumber{0}
    {
        for (int i = 0; i < 12; i++)
        {
            pieces[i] = 0ULL;
        }
        for (int i = 0; i < 3; i++)
        {
            occupancies[i] = 0ULL;
        }
        AttackBoards::Init();
        HashKeys::Init();
    }

    Game::Game(const Game &g)
        : castling{g.castling},
          enpassant{g.enpassant},
          side{g.side},
          r_index{g.r_index},
          hash{g.hash},
          halfMoveClock{g.halfMoveClock},
          fullMoveNumber{g.fullMoveNumber}
    {
        for (int i = 0; i < 12; i++)
        {
            pieces[i] = g.pieces[i];
        }
        for (int i = 0; i < 3; i++)
        {
            occupancies[i] = g.occupancies[i];
        }
        for (int i = 0; i < 1000; i++)
        {
            repetition_table[i] = g.repetition_table[i];
        }
    }

    Game &Game::operator=(const Game &g)
    {
        castling = g.castling;
        enpassant = g.enpassant;
        side = g.side;
        r_index = g.r_index;
        hash = g.hash;
        halfMoveClock = g.halfMoveClock;
        fullMoveNumber = g.fullMoveNumber;

        for (int i = 0; i < 12; i++)
        {
            pieces[i] = g.pieces[i];
        }
        for (int i = 0; i < 3; i++)
        {
            occupancies[i] = g.occupancies[i];
        }
        for (int i = 0; i < 1000; i++)
        {
            repetition_table[i] = g.repetition_table[i];
        }

        return *this;
    }

    Game::Game(Game &&g)
        : castling{g.castling},
          enpassant{g.enpassant},
          side{g.side},
          r_index{g.r_index},
          hash{g.hash},
          halfMoveClock{g.halfMoveClock},
          fullMoveNumber{g.fullMoveNumber}
    {
        for (int i = 0; i < 12; i++)
        {
            pieces[i] = g.pieces[i];
        }
        for (int i = 0; i < 3; i++)
        {
            occupancies[i] = g.occupancies[i];
        }
        for (int i = 0; i < 1000; i++)
        {
            repetition_table[i] = g.repetition_table[i];
        }
    }

    Game &Game::operator=(Game &&g)
    {
        castling = g.castling;
        enpassant = g.enpassant;
        side = g.side;
        r_index = g.r_index;
        hash = g.hash;
        halfMoveClock = g.halfMoveClock;
        fullMoveNumber = g.fullMoveNumber;

        for (int i = 0; i < 12; i++)
        {
            pieces[i] = g.pieces[i];
        }
        for (int i = 0; i < 3; i++)
        {
            occupancies[i] = g.occupancies[i];
        }
        for (int i = 0; i < 1000; i++)
        {
            repetition_table[i] = g.repetition_table[i];
        }

        return *this;
    }

    Game Game::fromFEN(std::string fen)
    {
        std::stringstream ss(fen);
        std::vector<std::string> tokens;
        std::string token;

        while (std::getline(ss, token, ' '))
        {
            tokens.push_back(token);
        }

        Game g;

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
        g.side = (tokens[1] == "w") ? ESide::WHITE : ESide::BLACK;

        // Parse castling
        for (auto c : tokens[2])
        {
            switch (c)
            {
            case 'K':
                g.castling |= ECastling::WKCA;
                break;
            case 'Q':
                g.castling |= ECastling::WQCA;
                break;
            case 'k':
                g.castling |= ECastling::BKCA;
                break;
            case 'q':
                g.castling |= ECastling::BQCA;
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
        g.halfMoveClock = std::stoi(tokens[4]);

        // Parse full move number
        g.fullMoveNumber = std::stoi(tokens[5]);

        // update occupied squares
        for (int piece = EPiece::P; piece <= EPiece::K; piece++)
        {
            g.occupancies[ESide::WHITE] |= g.pieces[piece];
        }
        for (int piece = EPiece::p; piece <= EPiece::k; piece++)
        {
            g.occupancies[ESide::BLACK] |= g.pieces[piece];
        }
        g.occupancies[ESide::BOTH] = g.occupancies[ESide::WHITE] | g.occupancies[ESide::BLACK];
        g.hash = g.generateHashKey();

        return g;
    }

    void Game::addPiece(int square, int piece)
    {
        pieces[piece].set(square);
        for (int side = ESide::WHITE; side <= ESide::BOTH; side++)
        {
            occupancies[side].set(square);
        }
        hash = generateHashKey();
    }

    uint8_t Game::isAttacked(int square, int side) const
    {
        auto attacks = AttackBoards::Instance();
        Bitboard pawns, knights, kings, bishops, rooks, queens;
        if (side == ESide::WHITE)
        {
            pawns = pieces[EPiece::P];
            knights = pieces[EPiece::N];
            kings = pieces[EPiece::K];
            bishops = pieces[EPiece::B];
            rooks = pieces[EPiece::R];
            queens = pieces[EPiece::Q];
        }
        else
        {
            pawns = pieces[EPiece::p];
            knights = pieces[EPiece::n];
            kings = pieces[EPiece::k];
            bishops = pieces[EPiece::b];
            rooks = pieces[EPiece::r];
            queens = pieces[EPiece::q];
        }
        if (attacks.pawn[1 - side][square] & pawns)
            return 1;
        if (attacks.knight[square] & knights)
            return 1;
        if (attacks.king[square] & kings)
            return 1;
        if (attacks.GetBishopAttacks(square, occupancies[ESide::BOTH]) & bishops)
            return 1;
        if (attacks.GetRookAttacks(square, occupancies[ESide::BOTH]) & rooks)
            return 1;
        if (attacks.GetQueenAttacks(square, occupancies[ESide::BOTH]) & queens)
            return 1;
        return 0;
    }

    bool Game::getPiece(int square, int &piece, int &side) const
    {
        for (piece = EPiece::P; piece <= EPiece::k; piece++)
        {
            if (pieces[piece] & (1ULL << square))
            {
                side = (piece < EPiece::p) ? ESide::WHITE : ESide::BLACK;
                return true;
            }
        }
        return false;
    }

    bool Game::generatePseudoMoves(std::vector<Move> &moves, int side, int piece, int square) const
    {
        if (piece >= EPiece::no_piece)
            return false;
        if (side >= ESide::BOTH)
            return false;
        if (!pieces[piece][square])
            return false;

        auto attacks = AttackBoards::Instance();

        // generate pawn moves
        if (piece == P || piece == p)
        {
            int target = square + (side == ESide::WHITE ? -8 : 8);
            if (target < 0 || target > 63)
                return true;

            std::vector<uint> promotions;
            if (target < 8 || target >= 56)
            {
                for (int promotion = EPiece::N; promotion <= EPiece::Q; promotion++)
                {
                    promotions.push_back(promotion + (side == ESide::WHITE ? 0 : 6));
                }
            }
            else
            {
                promotions.push_back((uint)no_piece);
            }

            // no piece on target square
            if (occupancies[ESide::BOTH][target] == 0)
            {
                for (auto promotion : promotions)
                {
                    moves.push_back({
                        .source = (uint)square,
                        .target = (uint)target,
                        .piece = (uint)piece,
                        .promotion = promotion,
                    });
                }

                // square rank
                int rank = square / 8;
                int starting_row = (side == ESide::WHITE ? 6 : 1);
                // double push
                int dtarget = square + (side == ESide::WHITE ? -16 : 16);

                // if pawn on starting row and no piece on double push square
                if (rank == starting_row && occupancies[ESide::BOTH][dtarget] == 0)
                {
                    moves.push_back({
                        .source = (uint)square,
                        .target = (uint)dtarget,
                        .piece = (uint)piece,
                        .double_push = 1,
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
                        .capture = (uint)(EPiece::P + (side == ESide::WHITE ? 0 : 6)),
                        .enpassant = 1,
                    });
                }
            }
            return true;
        }

        for (int p = EPiece::N; p <= EPiece::K; p++)
        {
            if (piece != p && piece != p + 6)
                continue;

            Bitboard attacking_squares;
            switch (p)
            {
            case EPiece::N:
            {
                attacking_squares = attacks.knight[square];
                break;
            }
            case EPiece::B:
            {
                attacking_squares = attacks.GetBishopAttacks(square, occupancies[ESide::BOTH]);
                break;
            }
            case EPiece::R:
            {
                attacking_squares = attacks.GetRookAttacks(square, occupancies[ESide::BOTH]);
                break;
            }
            case EPiece::Q:
            {
                attacking_squares = attacks.GetQueenAttacks(square, occupancies[ESide::BOTH]);
                break;
            }
            case EPiece::K:
            {
                attacking_squares = attacks.king[square];
                break;
            }
            default:
                throw std::runtime_error("Invalid piece in generatePseudoMoves");
            }

            // loop over quiet moves
            Bitboard quiet_moves = attacking_squares & ~occupancies[ESide::BOTH];
            while (quiet_moves)
            {
                int target = quiet_moves.ls1b();
                quiet_moves.pop(target);
                moves.push_back({
                    .source = (uint)square,
                    .target = (uint)target,
                    .piece = (uint)piece,
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
                });
            }
        }

        // castling
        if (piece == K || piece == k)
        {
            if (side == ESide::WHITE)
            {
                // king side
                bool canCastle = (castling & ECastling::WKCA);
                bool occpuied = occupancies[ESide::BOTH][ESquare::f1] || occupancies[ESide::BOTH][ESquare::g1];
                bool attacked = isAttacked(ESquare::e1, ESide::BLACK) || isAttacked(ESquare::f1, ESide::BLACK);
                if (canCastle && !occpuied && !attacked)
                {
                    moves.push_back({
                        .source = (uint)square,
                        .target = (uint)ESquare::g1,
                        .piece = (uint)piece,
                        .castling = (uint)ECastling::WKCA,
                    });
                }

                // queen side
                canCastle = (castling & ECastling::WQCA);
                occpuied = occupancies[ESide::BOTH][ESquare::b1] || occupancies[ESide::BOTH][ESquare::c1] || occupancies[ESide::BOTH][ESquare::d1];
                attacked = isAttacked(ESquare::e1, ESide::BLACK) || isAttacked(ESquare::d1, ESide::BLACK);

                if (canCastle && !occpuied && !attacked)
                {
                    moves.push_back({
                        .source = (uint)square,
                        .target = (uint)ESquare::c1,
                        .piece = (uint)piece,
                        .castling = (uint)ECastling::WQCA,
                    });
                }
                // black
            }
            else
            {
                // king side
                bool canCastle = (castling & ECastling::BKCA);
                bool occpuied = occupancies[ESide::BOTH][ESquare::f8] || occupancies[ESide::BOTH][ESquare::g8];
                bool attacked = isAttacked(ESquare::e8, ESide::WHITE) || isAttacked(ESquare::f8, ESide::WHITE);

                if (canCastle && !occpuied && !attacked)
                {
                    moves.push_back({
                        .source = (uint)square,
                        .target = (uint)ESquare::g8,
                        .piece = (uint)piece,
                        .castling = (uint)ECastling::BKCA,
                    });
                }

                // queen side
                canCastle = (castling & ECastling::BQCA);
                occpuied = occupancies[ESide::BOTH][ESquare::b8] || occupancies[ESide::BOTH][ESquare::c8] || occupancies[ESide::BOTH][ESquare::d8];
                attacked = isAttacked(ESquare::e8, ESide::WHITE) || isAttacked(ESquare::d8, ESide::WHITE);

                if (canCastle && !occpuied && !attacked)
                {
                    moves.push_back({
                        .source = (uint)square,
                        .target = (uint)ESquare::c8,
                        .piece = (uint)piece,
                        .castling = (uint)ECastling::BQCA,
                    });
                }
            }
        }
        return true;
    }

    bool Game::generatePseudoMoves(std::vector<Move> &moves, int square) const
    {
        int piece, side;
        if (!getPiece(square, piece, side))
            return false;
        return generatePseudoMoves(moves, side, piece, square);
    }

    bool Game::simulateMove(const Move &move, Game &game) const
    {
        // copy game
        Game g = *this;
        auto hash_keys = HashKeys::Instance();

        // move piece
        g.pieces[move.piece].pop(move.source);
        g.pieces[move.piece].set(move.target);
        g.hash ^= hash_keys.piece[move.piece][move.source];
        g.hash ^= hash_keys.piece[move.piece][move.target];

        // increment half move clock
        g.halfMoveClock++;

        if (move.piece == EPiece::P || move.piece == EPiece::p)
            // reset half move clock
            g.halfMoveClock = 0;

        // capture piece
        if (move.capture != EPiece::no_piece)
        {
            g.halfMoveClock = 0;
            g.pieces[move.capture].pop(move.target);
            g.hash ^= hash_keys.piece[move.capture][move.target];
        }

        // promotion
        if (move.promotion != EPiece::no_piece)
        {
            g.pieces[move.piece].pop(move.target);
            g.pieces[move.promotion].set(move.target);
            g.hash ^= hash_keys.piece[move.piece][move.target];
            g.hash ^= hash_keys.piece[move.promotion][move.target];
        }

        // enpassant
        if (move.enpassant)
        {
            g.halfMoveClock = 0;
            g.pieces[move.capture].pop(enpassant);
            g.hash ^= hash_keys.piece[move.capture][enpassant];
        }

        if (enpassant != no_sq)
            g.hash ^= hash_keys.enpassant[enpassant];

        // double push
        if (move.double_push)
        {
            g.enpassant = (move.target + move.source) / 2;
            g.hash ^= hash_keys.enpassant[g.enpassant];
        }
        else
        {
            g.enpassant = no_sq;
        }

        switch (move.castling)
        {
        case ECastling::WKCA:
            g.pieces[EPiece::R].pop(ESquare::h1);
            g.pieces[EPiece::R].set(ESquare::f1);
            g.hash ^= hash_keys.piece[EPiece::R][ESquare::h1];
            g.hash ^= hash_keys.piece[EPiece::R][ESquare::f1];
            break;
        case ECastling::WQCA:
            g.pieces[EPiece::R].pop(ESquare::a1);
            g.pieces[EPiece::R].set(ESquare::d1);
            g.hash ^= hash_keys.piece[EPiece::R][ESquare::a1];
            g.hash ^= hash_keys.piece[EPiece::R][ESquare::d1];
            break;
        case ECastling::BKCA:
            g.pieces[EPiece::r].pop(ESquare::h8);
            g.pieces[EPiece::r].set(ESquare::f8);
            g.hash ^= hash_keys.piece[EPiece::r][ESquare::h8];
            g.hash ^= hash_keys.piece[EPiece::r][ESquare::f8];
            break;
        case ECastling::BQCA:
            g.pieces[EPiece::r].pop(ESquare::a8);
            g.pieces[EPiece::r].set(ESquare::d8);
            g.hash ^= hash_keys.piece[EPiece::r][ESquare::a8];
            g.hash ^= hash_keys.piece[EPiece::r][ESquare::d8];
            break;
        default:
            break;
        }

        g.hash ^= hash_keys.castle[g.castling];
        g.castling &= CASTLE_RIGHTS[move.source];
        g.castling &= CASTLE_RIGHTS[move.target];
        g.hash ^= hash_keys.castle[g.castling];

        // occupied squares
        g.occupancies[ESide::WHITE] = g.pieces[EPiece::P] | g.pieces[EPiece::N] | g.pieces[EPiece::B] | g.pieces[EPiece::R] | g.pieces[EPiece::Q] | g.pieces[EPiece::K];
        g.occupancies[ESide::BLACK] = g.pieces[EPiece::p] | g.pieces[EPiece::n] | g.pieces[EPiece::b] | g.pieces[EPiece::r] | g.pieces[EPiece::q] | g.pieces[EPiece::k];
        g.occupancies[ESide::BOTH] = g.occupancies[ESide::WHITE] | g.occupancies[ESide::BLACK];

        // side to move
        g.side ^= 1;
        g.hash ^= hash_keys.side;

        // full move number
        if (g.side == ESide::WHITE)
            g.fullMoveNumber++;

        // is king attacked
        const int king = (side == ESide::WHITE) ? EPiece::K : EPiece::k;
        if (g.isAttacked(g.pieces[king].ls1b(), g.side))
            return false;

        game = g;
        return true;
    }

    bool Game::simulateMove(const Move &move) const
    {
        Game g;
        return simulateMove(move, g);
    }

    bool Game::makeMove(Move &move, bool validate)
    {
        if (!validate)
            return simulateMove(move, *this);
        Game g = *this;
        if (!validateMove(move, g))
            return false;
        *this = g;
        return true;
    }

    bool Game::validateMove(Move &move, Game &result) const
    {
        std::vector<Move> moves;
        bool pseudo = (move.piece >= EPiece::no_piece) ? generatePseudoMoves(moves, move.source) : generatePseudoMoves(moves, side, move.piece, move.source);
        if (!pseudo)
            return false;

        // find move with source and target in moves
        auto it = std::find_if(moves.begin(), moves.end(), [&](const Move &m)
                               { return m.source == move.source && m.target == move.target; });

        if (it == moves.end())
            return false;

        if (!simulateMove(*it, result))
            return false;

        move = *it;
        return true;
    }

    bool Game::generateMoves(std::vector<Move> &moves, int side, int piece, int square) const
    {
        std::vector<Move> pseudo_moves;
        if (!generatePseudoMoves(pseudo_moves, side, piece, square))
            return false;
        std::copy_if(pseudo_moves.begin(), pseudo_moves.end(), std::back_inserter(moves), [&](const Move &m)
                     { return simulateMove(m); });

        return false;
    }

    bool Game::generateMoves(std::vector<Move> &moves, int square) const
    {
        std::vector<Move> pseudo_moves;
        if(!generatePseudoMoves(pseudo_moves, square))
            return false;
        std::copy_if(pseudo_moves.begin(), pseudo_moves.end(), std::back_inserter(moves), [&](const Move &m)
                     { return simulateMove(m); });
        return false;
    }

    void Game::generateAllMoves(std::vector<Move> &moves, int side) const
    {
        int start_piece = (side == ESide::WHITE) ? EPiece::P : EPiece::p;
        for (int piece = start_piece; piece <= start_piece + 5; piece++)
        {
            Bitboard bitboard = pieces[piece];
            while (bitboard)
            {
                int square = bitboard.ls1b();
                bitboard.pop(square);
                generateMoves(moves, side, piece, square);
            }
        }
    }

    void Game::printAttackedSquares(int side) const
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

    u64 Game::generateHashKey() const
    {
        auto &hash_keys = HashKeys::Instance();
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
                final_key ^= hash_keys.piece[piece][square];

                // pop LS1B
                bitboard.pop(square);
            }
        }

        // if enpassant square is on board
        if (enpassant != no_sq)
            // hash enpassant
            final_key ^= hash_keys.enpassant[enpassant];

        // hash castling rights
        final_key ^= hash_keys.castle[castling];

        // hash the side only if black is to move
        if (side == ESide::BLACK)
            final_key ^= hash_keys.side;

        // return generated hash key
        return final_key;
    }

    std::ostream &operator<<(std::ostream &os, const Game &g)
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

    void printBitboard(Bitboard board)
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

}