#ifndef TYPES_H
#define TYPES_H

#ifdef __cplusplus
#include <cstdint>
#else
#include <stdint.h>
#endif

typedef uint64_t u64;

/**
 * @brief Enum representing the squares on a chessboard.
 */
enum e_square
{
    a8, b8, c8, d8, e8, f8, g8, h8,
    a7, b7, c7, d7, e7, f7, g7, h7,
    a6, b6, c6, d6, e6, f6, g6, h6,
    a5, b5, c5, d5, e5, f5, g5, h5,
    a4, b4, c4, d4, e4, f4, g4, h4,
    a3, b3, c3, d3, e3, f3, g3, h3,
    a2, b2, c2, d2, e2, f2, g2, h2,
    a1, b1, c1, d1, e1, f1, g1, h1,
    no_sq
};

/**
 * @brief Enum representing the different types of chess pieces.
 */
enum e_piece
{
    P, N, B, R, Q, K, // White pieces
    p, n, b, r, q, k, // Black pieces
    no_piece
};

/**
 * @brief Enum representing the sides in a chess game.
 */
enum e_side
{
    WHITE,
    BLACK,
    BOTH
};

/**
 * @brief Enum representing castling rights.
 */
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

/**
 * @brief Enum representing attack types.
 */
enum e_attack
{
    ROOK = 0,
    BISHOP = 1
};

#ifdef __cplusplus

#include <iostream>

/**
 * @brief Class representing a bitboard. Wrapper for a 64-bit unsigned integer.
 */
class Bitboard
{
public:
    Bitboard();
    Bitboard(const Bitboard &b); ///< Copy constructor
    Bitboard(const u64 &b);
    Bitboard &operator=(const Bitboard &b); ///< Copy assignment
    Bitboard &operator=(const u64 &b);
    Bitboard(Bitboard &&b); ///< Move constructor
    Bitboard(u64 &&b);
    Bitboard &operator=(Bitboard &&b); ///< Move assignment
    Bitboard &operator=(u64 &&b);

    // Arithmetic operators
    Bitboard operator~() const;
    Bitboard &operator*=(const Bitboard &b);
    Bitboard &operator*=(const u64 &b);
    Bitboard &operator/=(const Bitboard &b);
    Bitboard &operator/=(const u64 &b);

    // Bitwise operators
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

    // Index operator
    uint8_t operator[](const int &index) const;

    // Conversion operators
    operator u64() const;

    void set(const int &index);
    void pop(const int &index);
    int count() const;
    int ls1b() const;
    int popls1b();

    friend std::ostream &operator<<(std::ostream &os, const Bitboard &b);

    u64 board;
};

#else

/**
 * @brief Struct representing a bitboard (C version).
 */
typedef struct Bitboard_s
{
    u64 board;
} Bitboard;

#endif

/**
 * @brief Struct representing the state of a chess game.
 */
typedef struct game_state_s
{
    Bitboard pieces[12]; ///< Bitboards for each piece type.
    Bitboard occupancies[3]; ///< Bitboards for occupancies of each side.
    uint8_t castling; ///< Castling rights.
    uint8_t enpassant; ///< En passant square.
    uint8_t side; ///< Side to move.
    uint8_t half_move_clock; ///< Half-move clock for the fifty-move rule.
    uint8_t full_move_number; ///< Full move number.
    u64 hash; ///< Zobrist hash of the position.
} game_state_t;

/**
 * @brief Struct representing a move in a chess game.
 */
typedef struct
{
    uint32_t source : 6; ///< Source square.
    uint32_t target : 6; ///< Target square.
    uint32_t piece : 4; ///< Piece type.
    uint32_t capture : 4; ///< Captured piece type.
    uint32_t promotion : 4; ///< Promotion piece type.
    uint32_t castling : 4; ///< Castling rights.
    uint32_t enpassant : 1; ///< En passant flag.
    uint32_t double_push : 1; ///< Double pawn push flag.
    uint8_t check : 1; ///< Check flag.
    uint8_t checkmate : 1; ///< Checkmate flag.
    uint8_t stalemate : 1; ///< Stalemate flag.
    uint8_t draw : 1; ///< Draw flag.
    uint8_t fifty_move : 1; ///< Fifty-move rule flag.
    uint8_t threefold_repetition : 1; ///< Threefold repetition flag.
    uint8_t gameover : 1; ///< Game over flag.
} move_t;

/**
 * @brief Struct representing a node in the move tree.
 */
typedef struct
{
    game_state_t state; ///< Game state at this node.
    move_t move; ///< Move leading to this node.
} move_node_t;

/**
 * @brief Struct representing precomputed attack boards.
 */
typedef struct attack_boards_s
{
    Bitboard pawn[2][64]; ///< Pawn attack bitboards.
    Bitboard knight[64]; ///< Knight attack bitboards.
    Bitboard king[64]; ///< King attack bitboards.
    Bitboard bishop[64][512]; ///< Bishop attack bitboards.
    Bitboard rook[64][4096]; ///< Rook attack bitboards.
    Bitboard masks[2][64]; ///< Masks for attack bitboards.
    uint8_t initialized; ///< Initialization flag.
} attack_boards_t;

/**
 * @brief Struct representing Zobrist hash keys.
 */
typedef struct hash_keys_s
{
    u64 piece[12][64]; ///< Hash keys for pieces.
    u64 enpassant[64]; ///< Hash keys for en passant squares.
    u64 castle[16]; ///< Hash keys for castling rights.
    u64 side; ///< Hash key for side to move.
    uint8_t initialized; ///< Initialization flag.
} hash_keys_t;

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief Sets a bit in the bitboard.
     * 
     * @param b Pointer to the bitboard.
     * @param index Index of the bit to set.
     */
    void bitboard_set(Bitboard *b, int index);

    /**
     * @brief Clears a bit in the bitboard.
     * 
     * @param b Pointer to the bitboard.
     * @param index Index of the bit to clear.
     */
    void bitboard_pop(Bitboard *b, int index);

    /**
     * @brief Counts the number of set bits in the bitboard.
     * 
     * @param b Pointer to the bitboard.
     * @return Number of set bits.
     */
    int bitboard_count(const Bitboard *b);

    /**
     * @brief Finds the least significant set bit in the bitboard.
     * 
     * @param b Pointer to the bitboard.
     * @return Index of the least significant set bit.
     */
    int bitboard_ls1b(const Bitboard *b);

    /**
     * @brief Pops the least significant set bit in the bitboard.
     * 
     * @param b Pointer to the bitboard.
     * @return Index of the popped bit.
     */
    int bitboard_popls1b(Bitboard *b);

    /**
     * @brief Converts a move to Standard Algebraic Notation (SAN).
     * 
     * @param move The move to convert.
     * @param san Pointer to the buffer to store the SAN string.
     */
    void move_to_san(const move_t move, char *san);

    /**
     * @brief Initializes the Zobrist hash keys.
     */
    void hash_keys_init();

#ifdef __cplusplus
}
#endif

#endif // TYPES_H