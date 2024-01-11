#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "types.h"

extern const char *CHAR_SQUARE_MAP[65];
extern const char ASCII_PIECES[12];
extern const char *UNICODE_PIECES[12];
extern const int CHAR_EPIECE_MAP[];
extern const char PROMOTED_PIECES[];

extern const Bitboard NOT_A_FILE;
extern const Bitboard NOT_H_FILE;
extern const Bitboard NOT_HG_FILE;
extern const Bitboard NOT_AB_FILE;

extern const int BISHOP_RELEVANT_BITS[64];
extern const int ROOK_RELEVANT_BITS[64];
extern const Bitboard ROOK_MAGIC_NUMBERS[64];
extern const Bitboard BISHOP_MAGIC_NUMBERS[64];

extern u64 PIECE_KEYS[12][64];
extern u64 ENPASSANT_KEYS[64];
extern u64 CASTLE_KEYS[16];
extern u64 SIDE_KEY;

extern const int CASTLE_RIGHTS[64];

#endif
