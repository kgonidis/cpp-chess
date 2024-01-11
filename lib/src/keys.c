#include "keys.h"

hash_keys_t HASH_KEYS = {.initialized = 0};

// pseudo random number state
unsigned int random_state = 1804289383;

// generate 32-bit pseudo legal numbers
unsigned int get_random_U32_number()
{
    // get current state
    unsigned int number = random_state;

    // XOR shift algorithm
    number ^= number << 13;
    number ^= number >> 17;
    number ^= number << 5;

    // update random number state
    random_state = number;

    // return random number
    return number;
}

// generate 64-bit pseudo legal numbers
u64 get_random_u64_number()
{
    // define 4 random numbers
    u64 n1, n2, n3, n4;

    // init random numbers slicing 16 bits from MS1B side
    n1 = (u64)(get_random_U32_number()) & 0xFFFF;
    n2 = (u64)(get_random_U32_number()) & 0xFFFF;
    n3 = (u64)(get_random_U32_number()) & 0xFFFF;
    n4 = (u64)(get_random_U32_number()) & 0xFFFF;

    // return random number
    return n1 | (n2 << 16) | (n3 << 32) | (n4 << 48);
}

void hash_keys_init()
{
    // update pseudo random number state
    random_state = 1804289383;

    // loop over piece codes
    for (int piece = P; piece <= k; piece++)
    {
        // loop over board squares
        for (int square = 0; square < 64; square++)
            // init random piece keys
            HASH_KEYS.piece[piece][square] = get_random_u64_number();
    }

    // loop over board squares
    for (int square = 0; square < 64; square++)
        // init random enpassant keys
        HASH_KEYS.enpassant[square] = get_random_u64_number();

    // loop over castling keys
    for (int index = 0; index < 16; index++)
        // init castling keys
        HASH_KEYS.castle[index] = get_random_u64_number();

    // init random side key
    HASH_KEYS.side = get_random_u64_number();
    HASH_KEYS.initialized = 1;
}
