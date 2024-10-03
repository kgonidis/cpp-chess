#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "types.h"

// Global variable to store attack boards
extern attack_boards_t ATTACK_BOARDS;

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief Initializes the attack boards.
     * 
     * This function sets up the necessary data structures and precomputes
     * attack patterns for different pieces.
     */
    void attack_boards_init();

    /**
     * @brief Computes the bishop attacks for a given square.
     * 
     * @param bitboard Pointer to the bitboard where the attack pattern will be stored.
     * @param square The square on the board for which to compute the attacks.
     * @param blockers Bitboard representing the pieces that block the bishop's path.
     */
    void get_bishop_attacks(Bitboard *bitboard, int square, Bitboard blockers);

    /**
     * @brief Computes the rook attacks for a given square.
     * 
     * @param bitboard Pointer to the bitboard where the attack pattern will be stored.
     * @param square The square on the board for which to compute the attacks.
     * @param blockers Bitboard representing the pieces that block the rook's path.
     */
    void get_rook_attacks(Bitboard *bitboard, int square, Bitboard blockers);

    /**
     * @brief Computes the queen attacks for a given square.
     * 
     * @param bitboard Pointer to the bitboard where the attack pattern will be stored.
     * @param square The square on the board for which to compute the attacks.
     * @param blockers Bitboard representing the pieces that block the queen's path.
     */
    void get_queen_attacks(Bitboard *bitboard, int square, Bitboard blockers);

#ifdef __cplusplus
}
#endif

#endif // MOVEMENT_H