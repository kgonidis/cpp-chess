#ifndef TYPES_H
#define TYPES_H

#ifdef __cplusplus
#include <cstdint>
#else
#include <stdint.h>
#endif

typedef uint64_t u64;

enum e_square
{
    a8,
    b8,
    c8,
    d8,
    e8,
    f8,
    g8,
    h8,
    a7,
    b7,
    c7,
    d7,
    e7,
    f7,
    g7,
    h7,
    a6,
    b6,
    c6,
    d6,
    e6,
    f6,
    g6,
    h6,
    a5,
    b5,
    c5,
    d5,
    e5,
    f5,
    g5,
    h5,
    a4,
    b4,
    c4,
    d4,
    e4,
    f4,
    g4,
    h4,
    a3,
    b3,
    c3,
    d3,
    e3,
    f3,
    g3,
    h3,
    a2,
    b2,
    c2,
    d2,
    e2,
    f2,
    g2,
    h2,
    a1,
    b1,
    c1,
    d1,
    e1,
    f1,
    g1,
    h1,
    no_sq
};

enum e_piece
{
    P,
    N,
    B,
    R,
    Q,
    K,
    p,
    n,
    b,
    r,
    q,
    k,
    no_piece
};

enum e_side
{
    WHITE,
    BLACK,
    BOTH
};

enum e_castling
{
    NOCA = 0,
    WKCA = 1,
    WQCA = 2,
    BKCA = 4,
    BQCA = 8,
    KCA = WKCA | BKCA,
    QCA = WQCA | BQCA
};

enum e_attack
{
    ROOK = 0,
    BISHOP = 1
};

#ifdef __cplusplus

#include <iostream>

class Bitboard
{
public:
    Bitboard();
    // copy constructor
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
    int popls1b();

    // friend ostream operator
    friend std::ostream &operator<<(std::ostream &os, const Bitboard &b);

private:
    u64 board;
};
#else

typedef u64 Bitboard;

#endif

typedef struct
{
    Bitboard pieces[12];
    Bitboard occupancies[3];
    uint8_t castling;
    uint8_t enpassant;
    uint8_t side;
    uint8_t half_move_clock;
    uint8_t full_move_number;
    u64 hash;
} game_state_t;

typedef struct
{
    uint32_t source : 6;
    uint32_t target : 6;
    uint32_t piece : 4;
    uint32_t capture : 4;
    uint32_t promotion : 4;
    uint32_t castling : 4;
    uint32_t enpassant : 1;
    uint32_t double_push : 1;
    uint8_t check : 1;
    uint8_t checkmate : 1;
    uint8_t stalemate : 1;
    uint8_t draw : 1;
    uint8_t fifty_move : 1;
    uint8_t threefold_repetition : 1;
    uint8_t gameover : 1;
} move_t;

typedef struct
{
    game_state_t state;
    move_t move;
} move_node_t;

typedef struct attack_boards_s
{
    Bitboard pawn[2][64];
    Bitboard knight[64];
    Bitboard king[64];
    Bitboard bishop[64][512];
    Bitboard rook[64][4096];
    Bitboard masks[2][64];
    uint8_t initialized;
} attack_boards_t;

typedef struct hash_keys_s
{
    u64 piece[12][64];
    u64 enpassant[64];
    u64 castle[16];
    u64 side;
    uint8_t initialized;
} hash_keys_t;

#ifdef __cplusplus
extern "C"
{
#endif

    void bitboard_set(Bitboard *b, int index);
    void bitboard_pop(Bitboard *b, int index);
    int bitboard_count(const Bitboard *b);
    int bitboard_ls1b(const Bitboard *b);
    int bitboard_popls1b(Bitboard *b);
    void move_to_san(const move_t move, char *san);
    void hash_keys_init();

#ifdef __cplusplus
}
#endif


#endif // TYPES_H