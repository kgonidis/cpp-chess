#ifndef TYPES_HPP
#define TYPES_HPP

#include <cstdint>
#include <map>

// #define SET_BIT(bitboard, square) ((bitboard) |= (1ULL << (square)))
// #define GET_BIT(bitboard, square) ((bitboard) & (1ULL << (square)))
// #define POP_BIT(bitboard, square) ((bitboard) &= ~(1ULL << (square)))

namespace engine
{

    typedef uint64_t u64;
    class Bitboard
    {
    public:
        Bitboard();
        //copy constructor
        Bitboard(const Bitboard &b);
        Bitboard(const u64 &b);
        // copy assignment
        Bitboard &operator=(const Bitboard &b);
        Bitboard &operator=(const u64 &b);
        // move constructor
        Bitboard(Bitboard &&b);
        Bitboard(u64 &&b);
        // move assignment
        Bitboard &operator=(Bitboard &&b);
        Bitboard &operator=(u64 &&b);

        // arithmetic operators
        Bitboard operator~() const;
        Bitboard &operator*=(const Bitboard &b);
        Bitboard &operator*=(const u64 &b);
        Bitboard &operator/=(const Bitboard &b);
        Bitboard &operator/=(const u64 &b);

        // bitwise operators
        Bitboard &operator|=(const Bitboard &b);
        Bitboard &operator|=(const u64 &b);
        Bitboard &operator&=(const Bitboard &b);
        Bitboard &operator&=(const u64 &b);
        Bitboard &operator^=(const Bitboard &b);
        Bitboard &operator^=(const u64 &b);
        Bitboard &operator<<=(const Bitboard &b);
        Bitboard &operator<<=(const u64 &b);
        Bitboard &operator>>=(const Bitboard &b);
        Bitboard &operator>>=(const u64 &b);

        // index operator
        uint8_t operator[](const int &index) const;

        // conversion operators
        operator u64() const;

        void set(const int &index);
        void pop(const int &index);
        int count() const;
        int ls1b() const;

        // friend ostream operator
        friend std::ostream &operator<<(std::ostream &os, const Bitboard &b);
        
    private:
        u64 board;
    };

    enum  ESquare {
        a8, b8, c8, d8, e8, f8, g8, h8,
        a7, b7, c7, d7, e7, f7, g7, h7,
        a6, b6, c6, d6, e6, f6, g6, h6,
        a5, b5, c5, d5, e5, f5, g5, h5,
        a4, b4, c4, d4, e4, f4, g4, h4,
        a3, b3, c3, d3, e3, f3, g3, h3,
        a2, b2, c2, d2, e2, f2, g2, h2,
        a1, b1, c1, d1, e1, f1, g1, h1, no_sq
    };

    enum EPiece {
        P, N, B, R, Q, K, p, n, b, r, q, k, no_piece
    };

    struct Move
    {
        uint32_t source: 6;
        uint32_t target: 6;
        uint32_t piece: 4;
        uint32_t capture: 4 = (uint32_t)no_piece;
        uint32_t promotion: 4 = (uint32_t)no_piece;
        uint32_t castling: 4 = 0;
        uint32_t enpassant: 1 = 0;
        uint32_t double_push: 1 = 0;
    };

    


    enum ESide {
        WHITE, BLACK, BOTH
    };

    enum EAttack {
        ROOK, BISHOP
    };
}

#endif