#ifndef GAMETREE_H
#define GAMETREE_H

#include "game.h"

/**
 * @brief Represents a PGN token.
 */
typedef struct
{
    char san[10];                ///< Standard Algebraic Notation for the move.
    movetree_t *move;            ///< Pointer to the move tree node.
    uint8_t newline : 1;         ///< Flag indicating if this token starts a new line.
    uint8_t alternate_start : 1; ///< Flag indicating if this token is the start of an alternate line.
    uint8_t alternate_end : 6;   ///< Flag indicating if this token is the end of an alternate line.
} pgn_token_t;

#ifdef __cplusplus

#include <optional>
#include <memory>

/**
 * @brief Represents a key-value pair.
 */
struct pair_t
{
    std::string key;   ///< The key of the pair.
    std::string value; ///< The value of the pair.
};

/**
 * @brief Represents a game tree for a chess game.
 */
class gametree_t
{
public:
    movetree_t *current;      ///< Pointer to the current move in the tree.
    std::vector<pair_t> tags; ///< Vector of tags associated with the game.
    size_t n_tags;            ///< Number of tags.

    /**
     * @brief Default constructor.
     */
    gametree_t();

    /**
     * @brief Destructor.
     */
    ~gametree_t();

    /**
     * @brief Equality operator for game trees.
     *
     * @param tree The game tree to compare with.
     * @return true if the game trees are equal, false otherwise.
     */
    bool operator==(const gametree_t &tree) const;

    /**
     * @brief Creates game trees from a PGN string.
     *
     * @param pgn The PGN string.
     * @return A vector of game trees.
     */
    static std::vector<gametree_t> FromPgn(const char *pgn);

    /**
     * @brief Gets the current game position.
     *
     * @return The current game position.
     */
    game_t getPosition() const;

    /**
     * @brief Gets the current move in the tree.
     *
     * @return Pointer to the current move.
     */
    std::optional<movetree_t> getCurrent() const;

    /**
     * @brief Gets the next move in the tree.
     *
     * @return Pointer to the next move.
     */
    std::optional<movetree_t> getNext() const;

    /**
     * @brief Gets the previous move in the tree.
     *
     * @return Pointer to the previous move.
     */
    std::optional<movetree_t> getPrev() const;

    /**
     * @brief Gets the root of the move tree.
     *
     * @return Pointer to the root of the move tree.
     */
    std::optional<movetree_t> getRoot() const;

    /**
     * @brief Converts the game tree to a PGN string.
     *
     * @return A vector of PGN tokens.
     */
    std::vector<pgn_token_t> getPgnTokens() const;

    /**
     * @brief Converts the game tree to a PGN string.
     *
     * @return A string representing the game in PGN format.
     */
    std::string toPgn() const;

    u64 getHash() const;

    /**
     * @brief Sets the current move in the tree.
     *
     * @param move Pointer to the move to set as current.
     * @param setLine Flag indicating if this move should be set as the main line (default is true).
     */
    void setCurrent(movetree_t *move, bool setLine = true);

    /**
     * @brief Makes a move and updates the game tree.
     *
     * @param move The move to make.
     * @param setLine Flag indicating if this move should be set as the main line (default is true).
     * @return Pointer to the new current move.
     */
    std::optional<movetree_t> makeMove(move_t &move, bool setLine = true);

    /**
     * @brief Overwrites the current move with a new move.
     *
     * @param move The new move to overwrite with.
     * @return Pointer to the new current move.
     */
    std::optional<movetree_t> overwriteMove(move_t &move);

    /**
     * @brief Undoes the current move.
     *
     * @param setLine Flag indicating if the previous move should be set as the main line (default is false).
     * @return Pointer to the new current move.
     */
    std::optional<movetree_t> undoMove(bool setLine = false);

    /**
     * @brief Redoes the current move.
     *
     * @param setLine Flag indicating if the next move should be set as the main line (default is false).
     * @return Pointer to the new current move.
     */
    std::optional<movetree_t> redoMove(bool setLine = false);

private:
    std::shared_ptr<uint8_t> ref_count;
};

#else

/**
 * @brief Represents a key-value pair (C version).
 */
typedef struct pair_s
{
    char *key;   ///< The key of the pair.
    char *value; ///< The value of the pair.
} pair_t;

/**
 * @brief Represents a game tree for a chess game (C version).
 */
typedef struct gametree_s
{
    movetree_t *current; ///< Pointer to the current move in the tree.
    pair_t *tags;        ///< Array of tags associated with the game.
} gametree_t;

#endif // __cplusplus

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief Creates game trees from a PGN string.
     *
     * @param gametrees Pointer to the array of game trees.
     * @param pgn The PGN string.
     * @return The number of game trees created.
     */
    int gametrees_from_pgn(gametree_t **gametrees, const char *pgn);

    /**
     * @brief Initializes a new game tree.
     *
     * @return Pointer to the new game tree.
     */
    gametree_t *gametree_new();

    /**
     * @brief Frees the memory allocated for a game tree.
     *
     * @param tree Pointer to the game tree to free.
     */
    void gametree_free(gametree_t *tree);

    /**
     * @brief Makes a move and updates the game tree.
     *
     * @param tree Pointer to the game tree.
     * @param move Pointer to the move to make.
     * @return Pointer to the new current move.
     */
    movetree_t *gametree_make_move(gametree_t *tree, move_t *move);

    /**
     * @brief Undoes the current move.
     *
     * @param tree Pointer to the game tree.
     * @return Pointer to the new current move.
     */
    movetree_t *gametree_undo_move(gametree_t *tree);

    /**
     * @brief Redoes the current move.
     *
     * @param tree Pointer to the game tree.
     * @return Pointer to the new current move.
     */
    movetree_t *gametree_redo_move(gametree_t *tree);

    /**
     * @brief Overwrites the current move with a new move.
     *
     * @param tree Pointer to the game tree.
     * @param move Pointer to the new move to overwrite with.
     * @return Pointer to the new current move.
     */
    movetree_t *gametree_overwrite_move(gametree_t *tree, move_t *move);

    /**
     * @brief Gets the current move in the tree.
     *
     * @param tree Pointer to the game tree.
     * @return Pointer to the current move.
     */
    movetree_t *gametree_get_current(gametree_t *tree);

    /**
     * @brief Gets the root of the move tree.
     *
     * @param tree Pointer to the game tree.
     * @return Pointer to the root of the move tree.
     */
    movetree_t *gametree_get_root(gametree_t *tree);

    /**
     * @brief Gets the next move in the tree.
     *
     * @param tree Pointer to the game tree.
     * @return Pointer to the next move.
     */
    movetree_t *gametree_get_next(gametree_t *tree);

    /**
     * @brief Gets the previous move in the tree.
     *
     * @param tree Pointer to the game tree.
     * @return Pointer to the previous move.
     */
    movetree_t *gametree_get_prev(gametree_t *tree);

    /**
     * @brief Gets the current game position.
     *
     * @param tree Pointer to the game tree.
     * @param state Pointer to the game state to update.
     */
    void gametree_get_position(gametree_t *tree, game_state_t *state);

    /**
     * @brief Converts the game tree to a PGN string.
     *
     * @param tree Pointer to the game tree.
     * @param pgn Pointer to the array of PGN tokens.
     * @return The number of PGN tokens created.
     */
    int gametree_to_pgn(gametree_t *tree, pgn_token_t **pgn);

    /**
     * @brief Sets the current move in the tree.
     *
     * @param tree Pointer to the game tree.
     * @param move Pointer to the move to set as current.
     * @param setLine Flag indicating if this move should be set as the main line.
     */
    void gametree_set_current(gametree_t *tree, movetree_t *move, int setLine);

#ifdef __cplusplus
}
#endif

#endif // GAMETREE_H