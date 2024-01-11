#ifndef PARSER_H
#define PARSER_H

#include "game.h"
#include "types.h"
#include "movement.h"

typedef struct pair_s
{
    const char *key;
    const char *value;
} pair_t;

typedef struct pgn_s
{
    move_tree_t *moves;
    pair_t *pairs;
    uint8_t n_pairs;
} pgn_t;

typedef struct pgn_db_s
{
    pgn_t *pgns;
    uint8_t n_pgns;
} pgn_db_t;

#ifdef __cplusplus
extern "C"
{
#endif

    void pgn_parse(pgn_db_t *db, const char *filename);
    move_tree_t *pgn_moves(pgn_db_t *db, int index);
    void free_pgn_db(pgn_db_t *db);

#ifdef __cplusplus
}
#endif

#endif