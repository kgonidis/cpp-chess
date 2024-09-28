#ifndef GAME_H
#define GAME_H

#include "types.h"
#include "movetree.h"

#ifdef __cplusplus
#include <string>
#include <vector>

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

    bool makeMove(move_t &move, bool validate = true);

    bool operator==(const game_t &g) const;
    friend std::ostream &operator<<(std::ostream &os, const game_t &g);

    game_state_t state;
};

#endif

extern const char *STARTING_FEN;

#ifdef __cplusplus
extern "C"
{
#endif
    
void game_new(game_state_t *state);
void game_print(const game_state_t state);

#ifdef __cplusplus
}
#endif

#endif