#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "types.h"

extern attack_boards_t ATTACK_BOARDS;

#ifdef __cplusplus
extern "C"
{
#endif

    void attack_boards_init();
    void get_bishop_attacks(Bitboard *bitboard, int square, Bitboard blockers);
    void get_rook_attacks(Bitboard *bitboard, int square, Bitboard blockers);
    void get_queen_attacks(Bitboard *bitboard, int square, Bitboard blockers);

#ifdef __cplusplus
}
#endif

#endif