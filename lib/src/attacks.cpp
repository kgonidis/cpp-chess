#include "attacks.h"
#include "types.h"
#include "constants.h"
#include <iostream>

attack_boards_t ATTACK_BOARDS = {
    .initialized = 0,
};

Bitboard mask_pawn_attacks(int side, int square)
{
    // result attacks bitboard
    Bitboard attacks = 0ULL;

    // piece bitboard
    Bitboard bitboard = 0ULL;

    // set piece on board
    bitboard.set(square);

    // white pawns
    if (side == WHITE)
    {
        // generate pawn attacks
        if ((bitboard >> 7) & NOT_A_FILE)
            attacks |= (bitboard >> 7);
        if ((bitboard >> 9) & NOT_H_FILE)
            attacks |= (bitboard >> 9);
    }
    // black pawns
    else
    {
        // generate pawn attacks
        if ((bitboard << 7) & NOT_H_FILE)
            attacks |= (bitboard << 7);
        if ((bitboard << 9) & NOT_A_FILE)
            attacks |= (bitboard << 9);
    }

    // return attack map
    return attacks;
}

// generate knight attacks
Bitboard mask_knight_attacks(int square)
{
    // result attacks bitboard
    Bitboard attacks = 0ULL;

    // piece bitboard
    Bitboard bitboard = 0ULL;

    // set piece on board
    bitboard.set(square);

    // generate knight attacks
    if ((bitboard >> 17) & NOT_H_FILE)
        attacks |= (bitboard >> 17);
    if ((bitboard >> 15) & NOT_A_FILE)
        attacks |= (bitboard >> 15);
    if ((bitboard >> 10) & NOT_HG_FILE)
        attacks |= (bitboard >> 10);
    if ((bitboard >> 6) & NOT_AB_FILE)
        attacks |= (bitboard >> 6);
    if ((bitboard << 17) & NOT_A_FILE)
        attacks |= (bitboard << 17);
    if ((bitboard << 15) & NOT_H_FILE)
        attacks |= (bitboard << 15);
    if ((bitboard << 10) & NOT_AB_FILE)
        attacks |= (bitboard << 10);
    if ((bitboard << 6) & NOT_HG_FILE)
        attacks |= (bitboard << 6);

    // return attack map
    return attacks;
}

// generate king attacks
Bitboard mask_king_attacks(int square)
{
    // result attacks bitboard
    Bitboard attacks = 0ULL;

    // piece bitboard
    Bitboard bitboard = 0ULL;

    // set piece on board
    bitboard.set(square);

    // generate king attacks
    if (bitboard >> 8)
        attacks |= (bitboard >> 8);
    if ((bitboard >> 9) & NOT_H_FILE)
        attacks |= (bitboard >> 9);
    if ((bitboard >> 7) & NOT_A_FILE)
        attacks |= (bitboard >> 7);
    if ((bitboard >> 1) & NOT_H_FILE)
        attacks |= (bitboard >> 1);
    if (bitboard << 8)
        attacks |= (bitboard << 8);
    if ((bitboard << 9) & NOT_A_FILE)
        attacks |= (bitboard << 9);
    if ((bitboard << 7) & NOT_H_FILE)
        attacks |= (bitboard << 7);
    if ((bitboard << 1) & NOT_A_FILE)
        attacks |= (bitboard << 1);

    // return attack map
    return attacks;
}

Bitboard mask_bishop_attacks(int square)
{
    // result attacks bitboard
    Bitboard attacks = 0ULL;

    // init ranks & files
    int r, f;

    // init target rank & files
    int tr = square / 8;
    int tf = square % 8;

    // mask relevant bishop occupancy bits
    for (r = tr + 1, f = tf + 1; r <= 6 && f <= 6; r++, f++)
        attacks |= (1ULL << (r * 8 + f));
    for (r = tr - 1, f = tf + 1; r >= 1 && f <= 6; r--, f++)
        attacks |= (1ULL << (r * 8 + f));
    for (r = tr + 1, f = tf - 1; r <= 6 && f >= 1; r++, f--)
        attacks |= (1ULL << (r * 8 + f));
    for (r = tr - 1, f = tf - 1; r >= 1 && f >= 1; r--, f--)
        attacks |= (1ULL << (r * 8 + f));

    // return attack map
    return attacks;
}

Bitboard mask_rook_attacks(int square)
{
    // result attacks bitboard
    Bitboard attacks = 0ULL;

    // init ranks & files
    int r, f;

    // init target rank & files
    int tr = square / 8;
    int tf = square % 8;

    // mask relevant rook occupancy bits
    for (r = tr + 1; r <= 6; r++)
        attacks |= (1ULL << (r * 8 + tf));
    for (r = tr - 1; r >= 1; r--)
        attacks |= (1ULL << (r * 8 + tf));
    for (f = tf + 1; f <= 6; f++)
        attacks |= (1ULL << (tr * 8 + f));
    for (f = tf - 1; f >= 1; f--)
        attacks |= (1ULL << (tr * 8 + f));

    // return attack map
    return attacks;
}

Bitboard set_occupancy(int index, int bits_in_mask, Bitboard attack_mask)
{
    // occupancy map
    Bitboard occupancy = 0ULL;

    // loop over the range of bits within attack mask
    for (int count = 0; count < bits_in_mask; count++)
    {
        // get LS1B index of attacks mask
        int square = attack_mask.ls1b();

        // pop LS1B in attack map
        attack_mask.pop(square);

        // make sure occupancy is on board
        if (index & (1 << count))
            // populate occupancy map
            occupancy |= (1ULL << square);
    }

    // return occupancy map
    return occupancy;
}

Bitboard bishop_attacks_on_the_fly(int square, Bitboard block)
{
    // result attacks bitboard
    Bitboard attacks = 0ULL;

    // init ranks & files
    int r, f;

    // init target rank & files
    int tr = square / 8;
    int tf = square % 8;

    // generate bishop atacks
    for (r = tr + 1, f = tf + 1; r <= 7 && f <= 7; r++, f++)
    {
        attacks |= (1ULL << (r * 8 + f));
        if ((1ULL << (r * 8 + f)) & block)
            break;
    }

    for (r = tr - 1, f = tf + 1; r >= 0 && f <= 7; r--, f++)
    {
        attacks |= (1ULL << (r * 8 + f));
        if ((1ULL << (r * 8 + f)) & block)
            break;
    }

    for (r = tr + 1, f = tf - 1; r <= 7 && f >= 0; r++, f--)
    {
        attacks |= (1ULL << (r * 8 + f));
        if ((1ULL << (r * 8 + f)) & block)
            break;
    }

    for (r = tr - 1, f = tf - 1; r >= 0 && f >= 0; r--, f--)
    {
        attacks |= (1ULL << (r * 8 + f));
        if ((1ULL << (r * 8 + f)) & block)
            break;
    }

    // return attack map
    return attacks;
}

// generate rook attacks on the fly
Bitboard rook_attacks_on_the_fly(int square, Bitboard block)
{
    // result attacks bitboard
    Bitboard attacks = 0ULL;

    // init ranks & files
    int r, f;

    // init target rank & files
    int tr = square / 8;
    int tf = square % 8;

    // generate rook attacks
    for (r = tr + 1; r <= 7; r++)
    {
        attacks |= (1ULL << (r * 8 + tf));
        if ((1ULL << (r * 8 + tf)) & block)
            break;
    }

    for (r = tr - 1; r >= 0; r--)
    {
        attacks |= (1ULL << (r * 8 + tf));
        if ((1ULL << (r * 8 + tf)) & block)
            break;
    }

    for (f = tf + 1; f <= 7; f++)
    {
        attacks |= (1ULL << (tr * 8 + f));
        if ((1ULL << (tr * 8 + f)) & block)
            break;
    }

    for (f = tf - 1; f >= 0; f--)
    {
        attacks |= (1ULL << (tr * 8 + f));
        if ((1ULL << (tr * 8 + f)) & block)
            break;
    }

    // return attack map
    return attacks;
}

void attack_boards_init()
{
    if (ATTACK_BOARDS.initialized)
        return;
    // initialize leaper attack board
    for (size_t square = 0; square < 64; square++)
    {
        ATTACK_BOARDS.pawn[WHITE][square] = mask_pawn_attacks(WHITE, square);
        ATTACK_BOARDS.pawn[BLACK][square] = mask_pawn_attacks(BLACK, square);
        ATTACK_BOARDS.knight[square] = mask_knight_attacks(square);
        ATTACK_BOARDS.king[square] = mask_king_attacks(square);
    }

    // loop over 64 board squares
    for (int square = 0; square < 64; square++)
    {
        // init bishop & rook masks
        ATTACK_BOARDS.masks[BISHOP][square] = mask_bishop_attacks(square);
        ATTACK_BOARDS.masks[ROOK][square] = mask_rook_attacks(square);

        Bitboard masks[] = {ATTACK_BOARDS.masks[BISHOP][square], ATTACK_BOARDS.masks[ROOK][square]};

        for (int mask_type = 0; mask_type < 2; mask_type++)
        {
            Bitboard attack_mask = ATTACK_BOARDS.masks[mask_type][square];
            auto magic_numbers = (mask_type == BISHOP) ? BISHOP_MAGIC_NUMBERS : ROOK_MAGIC_NUMBERS;
            auto relevant_bits = (mask_type == BISHOP) ? BISHOP_RELEVANT_BITS : ROOK_RELEVANT_BITS;

            // init relevant occupancy bit count
            int relevant_bits_count = attack_mask.count();

            // init occupancy indices
            int occupancy_indices = (1 << relevant_bits_count);

            // loop over occupancy indices
            for (int index = 0; index < occupancy_indices; index++)
            {
                // init current occupancy variation
                Bitboard occupancy = set_occupancy(index, relevant_bits_count, attack_mask);

                // init magic index
                int magic_index = (occupancy * magic_numbers[square]) >> (64 - relevant_bits[square]);

                if (mask_type == BISHOP)
                    ATTACK_BOARDS.bishop[square][magic_index] = bishop_attacks_on_the_fly(square, occupancy);
                else
                    ATTACK_BOARDS.rook[square][magic_index] = rook_attacks_on_the_fly(square, occupancy);
            }
        }
    }
    ATTACK_BOARDS.initialized = 1;
}

void get_bishop_attacks(Bitboard *bitboard, int square, Bitboard blockers)
{
    Bitboard magic_index = blockers & ATTACK_BOARDS.masks[BISHOP][square];
    magic_index *= BISHOP_MAGIC_NUMBERS[square];
    magic_index >>= 64 - BISHOP_RELEVANT_BITS[square];
    *bitboard = ATTACK_BOARDS.bishop[square][magic_index];
}

void get_rook_attacks(Bitboard *bitboard, int square, Bitboard blockers)
{
    Bitboard magic_index = blockers & ATTACK_BOARDS.masks[ROOK][square];
    magic_index *= ROOK_MAGIC_NUMBERS[square];
    magic_index >>= 64 - ROOK_RELEVANT_BITS[square];
    *bitboard = ATTACK_BOARDS.rook[square][magic_index];
}

void get_queen_attacks(Bitboard *bitboard, int square, Bitboard blockers)
{
    Bitboard bishop, rook;
    get_bishop_attacks(&bishop, square, blockers);
    get_rook_attacks(&rook, square, blockers);
    *bitboard = bishop | rook;
}