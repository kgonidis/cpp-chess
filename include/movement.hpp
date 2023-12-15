#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP

#include "types.hpp"

namespace engine
{
    struct AttackBoards
    {
        Bitboard pawn[2][64];
        Bitboard knight[64];
        Bitboard king[64];
        Bitboard bishop[64][512];
        Bitboard rook[64][4096];
        Bitboard masks[2][64];
        bool initialized = false;

        static const AttackBoards &Init();
        static const AttackBoards &Instance();

        Bitboard GetBishopAttacks(int square, Bitboard blockers) const;
        Bitboard GetRookAttacks(int square, Bitboard blockers) const;
        Bitboard GetQueenAttacks(int square, Bitboard blockers) const;
    };
}

#endif