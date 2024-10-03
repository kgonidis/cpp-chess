#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "types.h"

/**
 * @brief Maps each square on the board to a character representation.
 * The array has 65 elements to include a null terminator.
 */
extern const char *CHAR_SQUARE_MAP[65];

/**
 * @brief Array of ASCII characters representing different chess pieces.
 * The array has 12 elements for different pieces.
 */
extern const char ASCII_PIECES[12];

/**
 * @brief Array of Unicode strings representing different chess pieces.
 * The array has 12 elements for different pieces.
 */
extern const char *UNICODE_PIECES[12];

/**
 * @brief Maps characters to piece indices.
 * The size of the array is not specified here.
 */
extern const int CHAR_EPIECE_MAP[];

/**
 * @brief Array of characters representing promoted pieces.
 * The size of the array is not specified here.
 */
extern const char PROMOTED_PIECES[];

/**
 * @brief Bitboard representing all squares except the A-file.
 */
extern const Bitboard NOT_A_FILE;

/**
 * @brief Bitboard representing all squares except the H-file.
 */
extern const Bitboard NOT_H_FILE;

/**
 * @brief Bitboard representing all squares except the H and G files.
 */
extern const Bitboard NOT_HG_FILE;

/**
 * @brief Bitboard representing all squares except the A and B files.
 */
extern const Bitboard NOT_AB_FILE;

/**
 * @brief Array of relevant bits for bishop moves for each square.
 * The array has 64 elements, one for each square on the board.
 */
extern const int BISHOP_RELEVANT_BITS[64];

/**
 * @brief Array of relevant bits for rook moves for each square.
 * The array has 64 elements, one for each square on the board.
 */
extern const int ROOK_RELEVANT_BITS[64];

/**
 * @brief Array of magic numbers for rook moves for each square.
 * The array has 64 elements, one for each square on the board.
 */
extern const Bitboard ROOK_MAGIC_NUMBERS[64];

/**
 * @brief Array of magic numbers for bishop moves for each square.
 * The array has 64 elements, one for each square on the board.
 */
extern const Bitboard BISHOP_MAGIC_NUMBERS[64];

/**
 * @brief 2D array of Zobrist keys for pieces.
 * The array has 12 elements for different pieces and 64 elements for each square.
 */
extern u64 PIECE_KEYS[12][64];

/**
 * @brief Array of Zobrist keys for en passant squares.
 * The array has 64 elements, one for each square on the board.
 */
extern u64 ENPASSANT_KEYS[64];

/**
 * @brief Array of Zobrist keys for castling rights.
 * The array has 16 elements for different castling rights combinations.
 */
extern u64 CASTLE_KEYS[16];

/**
 * @brief Zobrist key for the side to move.
 */
extern u64 SIDE_KEY;

/**
 * @brief Struct containing all hash keys.
 */
extern hash_keys_t HASH_KEYS;

/**
 * @brief Array of castling rights for each square.
 * The array has 64 elements, one for each square on the board.
 */
extern const int CASTLE_RIGHTS[64];

#endif // CONSTANTS_H