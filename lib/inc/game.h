#ifndef GAME_H
#define GAME_H

#include "types.h"
#include "movetree.h"

#ifdef __cplusplus
#include <string>
#include <vector>
class game_t;
#else
typedef struct game_s game_t;
#endif

typedef struct sample_s sample_t;

#ifdef __cplusplus

class game_t
{
public:
    game_t();
    game_t(const game_state_t &state);

    static game_t FromFEN(const char *fen);
    static game_t FromStartingPosition();
    static std::string ToPGN(movetree_t *moves);

    uint8_t isAttacked(int square, int side) const;
    bool isInCheck() const;
    bool isCheckmated() const;
    bool getPiece(int square, int &piece, int &side) const;
    bool generatePseudoMoves(std::vector<move_t> &moves, int side, int piece, int square) const;
    bool generatePseudoMoves(std::vector<move_t> &moves, int square) const;
    bool simulateMove(move_t &move, game_t *game) const;
    std::vector<move_t> generateMoves(int side, int piece, int square) const;
    std::vector<move_t> generateMoves(int square) const;
    u64 generateHashKey() const;
    void printAttackedSquares(int side) const;
    std::string toFEN() const;
    game_state_t getState() const;

    void addPiece(int square, int piece);
    bool makeMove(move_t &move, bool validate = true);

    bool operator==(const game_t &g) const;
    friend std::ostream &operator<<(std::ostream &os, const game_t &g);

    game_state_t state;
};

#else

typedef void s_tree_t;

struct game_s
{
    Bitboard pieces[12];
    Bitboard occupancies[3];
    uint8_t castling;
    uint8_t enpassant;
    uint8_t side;
    u64 hash;
    uint8_t half_move_clock;
    uint8_t full_move_number;
    s_tree_t *move_tree;
};

#endif

extern const char *STARTING_FEN;

#ifdef __cplusplus
extern "C"
{
#endif
    struct sample_s
    {
        move_t move;
        game_t game;
    };
    void bitboard_print(Bitboard board);
    void game_new(game_t *game);
    void game_print(game_t *game);

#ifdef __cplusplus
}
#endif

#endif