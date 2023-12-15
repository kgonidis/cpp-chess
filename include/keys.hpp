#ifndef KEYS_HPP
#define KEYS_HPP

#include "types.hpp"

namespace engine
{
    class HashKeys
    {
    private:
        bool initialized;
    public:
        HashKeys();
        static HashKeys& Init();
        static HashKeys& Instance();
        u64 piece[12][64];
        u64 enpassant[64];
        u64 castle[16];
        u64 side;
    };
}

#endif