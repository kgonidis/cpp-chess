#ifndef KEYS_H
#define KEYS_H

#include "types.h"

typedef struct hash_keys_s
{
    u64 piece[12][64];
    u64 enpassant[64];
    u64 castle[16];
    u64 side;
    uint8_t initialized;
} hash_keys_t;

extern hash_keys_t HASH_KEYS;

#ifdef __cplusplus
extern "C"
{
#endif

    void hash_keys_init();

#ifdef __cplusplus
}
#endif

#endif