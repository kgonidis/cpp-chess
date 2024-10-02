#ifndef GAMETREE_H
#define GAMETREE_H

#include "game.h"

typedef struct
{
    char san[10];
    movetree_t *move;
    uint8_t newline : 1;
    uint8_t alternate_start : 1;
    uint8_t alternate_end : 6;
} pgn_token_t;

#ifdef __cplusplus

typedef struct pair_s
{
    std::string key;
    std::string value;
} pair_t;

class gametree_t
{
private:
    movetree_t *current;
    std::vector<pair_t> tags;
    size_t n_tags;

public:
    gametree_t();
    gametree_t(movetree_t *root, const std::vector<pair_t> &tags = {});
    void operator delete(void *p);
    static std::vector<gametree_t> FromPGN(const char *pgn);

    game_t getPosition() const;
    movetree_t *getCurrent() const;
    movetree_t *getNext() const;
    movetree_t *getPrev() const;
    movetree_t *getRoot() const;
    std::vector<pgn_token_t> toPGN() const;

    void setCurrent(movetree_t *move, bool setLine = true);

    movetree_t *makeMove(move_t &move, bool setLine = true);
    movetree_t *overwriteMove(move_t &move);
    movetree_t *undoMove(bool setLine = false);
    movetree_t *redoMove(bool setLine = false);
};

#else
typedef struct pair_s
{
    char *key;
    char *value;
} pair_t;

typedef struct gametree_s
{
    movetree_t *current;
    pair_t *tags;
} gametree_t;

#endif // __cplusplus

#ifdef __cplusplus
extern "C"
{
#endif
    int gametrees_from_pgn(gametree_t **gametrees, const char *pgn);
    gametree_t *gametree_new();
    void gametree_free(gametree_t *tree);
    movetree_t *gametree_make_move(gametree_t *tree, move_t *move);
    movetree_t *gametree_undo_move(gametree_t *tree);
    movetree_t *gametree_redo_move(gametree_t *tree);
    movetree_t *gametree_overwrite_move(gametree_t *tree, move_t *move);
    movetree_t *gametree_get_current(gametree_t *tree);
    movetree_t *gametree_get_root(gametree_t *tree);
    movetree_t *gametree_get_next(gametree_t *tree);
    movetree_t *gametree_get_prev(gametree_t *tree);
    void gametree_get_position(gametree_t *tree, game_state_t *state);
    int gametree_to_pgn(gametree_t *tree, pgn_token_t **pgn);
    void gametree_set_current(gametree_t *tree, movetree_t *move, int setLine);
#ifdef __cplusplus
}
#endif

#endif // GAMETREE_H
