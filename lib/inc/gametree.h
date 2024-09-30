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

public:
    gametree_t();
    gametree_t(movetree_t *root);
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

#endif // GAMETREE_H
