#ifndef GAME_H
#define GAME_H

#include "types.h"
#include "movetree.h"

#ifdef __cplusplus
#include <string>
#include <vector>

/**
 * @brief Represents a game of chess.
 */
class game_t
{
public:
    /**
     * @brief Default constructor.
     */
    game_t();

    /**
     * @brief Constructs a game from a given state.
     * 
     * @param state The initial state of the game.
     */
    game_t(const game_state_t &state);

    /**
     * @brief Creates a game from a FEN string.
     * 
     * @param fen The FEN string representing the game state.
     * @return A game_t object initialized to the state described by the FEN string.
     */
    static game_t FromFEN(const char *fen);

    /**
     * @brief Creates a game from the standard starting position.
     * 
     * @return A game_t object initialized to the standard starting position.
     */
    static game_t FromStartingPosition();

    /**
     * @brief Converts a move tree to a PGN string.
     * 
     * @param moves The move tree to convert.
     * @return A string representing the moves in PGN format.
     */
    static std::string ToPGN(movetree_t *moves);

    /**
     * @brief Checks if a square is attacked by a given side.
     * 
     * @param square The square to check.
     * @param side The side to check for attacks.
     * @return 1 if the square is attacked, 0 otherwise.
     */
    uint8_t isAttacked(int square, int side) const;

    /**
     * @brief Checks if the current player is in check.
     * 
     * @return true if the current player is in check, false otherwise.
     */
    bool isInCheck() const;

    /**
     * @brief Checks if the current player is checkmated.
     * 
     * @return true if the current player is checkmated, false otherwise.
     */
    bool isCheckmated() const;

    /**
     * @brief Gets the piece and side at a given square.
     * 
     * @param square The square to check.
     * @param piece Reference to store the piece.
     * @param side Reference to store the side.
     * @return true if there is a piece at the square, false otherwise.
     */
    bool getPiece(int square, int &piece, int &side) const;

    /**
     * @brief Generates pseudo-legal moves for a given piece.
     * 
     * @param moves Vector to store the generated moves.
     * @param side The side to generate moves for.
     * @param piece The piece to generate moves for.
     * @param square The square of the piece.
     * @return true if moves were generated, false otherwise.
     */
    bool generatePseudoMoves(std::vector<move_t> &moves, int side, int piece, int square) const;

    /**
     * @brief Generates pseudo-legal moves for any piece at a given square.
     * 
     * @param moves Vector to store the generated moves.
     * @param square The square to generate moves for.
     * @return true if moves were generated, false otherwise.
     */
    bool generatePseudoMoves(std::vector<move_t> &moves, int square) const;

    /**
     * @brief Simulates a move and updates the game state.
     * 
     * @param move The move to simulate.
     * @param game Pointer to the game object to update.
     * @return true if the move was valid, false otherwise.
     */
    bool simulateMove(move_t &move, game_t *game) const;

    /**
     * @brief Generates all legal moves for a given piece.
     * 
     * @param side The side to generate moves for.
     * @param piece The piece to generate moves for.
     * @param square The square of the piece.
     * @return A vector of generated moves.
     */
    std::vector<move_t> generateMoves(int side, int piece, int square) const;

    /**
     * @brief Generates all legal moves for any piece at a given square.
     * 
     * @param square The square to generate moves for.
     * @return A vector of generated moves.
     */
    std::vector<move_t> generateMoves(int square) const;

    /**
     * @brief Generates a hash key for the current game state.
     * 
     * @return The generated hash key.
     */
    u64 generateHashKey() const;

    /**
     * @brief Prints the squares attacked by a given side.
     * 
     * @param side The side to check for attacks.
     */
    void printAttackedSquares(int side) const;

    /**
     * @brief Converts the current game state to a FEN string.
     * 
     * @return A string representing the current game state in FEN format.
     */
    std::string toFEN() const;

    /**
     * @brief Gets the current game state.
     * 
     * @return The current game state.
     */
    game_state_t getState() const;

    /**
     * @brief Makes a move and updates the game state.
     * 
     * @param move The move to make.
     * @param validate Whether to validate the move.
     * @return true if the move was valid, false otherwise.
     */
    bool makeMove(move_t &move, bool validate = true);

    /**
     * @brief Equality operator for game_t.
     * 
     * @param g The game to compare with.
     * @return true if the games are equal, false otherwise.
     */
    bool operator==(const game_t &g) const;

    /**
     * @brief Output stream operator for game_t.
     * 
     * @param os The output stream.
     * @param g The game to output.
     * @return The output stream.
     */
    friend std::ostream &operator<<(std::ostream &os, const game_t &g);

    game_state_t state; ///< The current state of the game.
};

#endif // __cplusplus

extern const char *STARTING_FEN;

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief Initializes a new game state.
 * 
 * @param state Pointer to the game state to initialize.
 */
void game_new(game_state_t *state);

/**
 * @brief Prints the current game state.
 * 
 * @param state The game state to print.
 */
void game_print(const game_state_t state);

#ifdef __cplusplus
}
#endif

#endif // GAME_H