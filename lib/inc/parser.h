#ifndef PARSER_H
#define PARSER_H

#include "game.h"
#include "types.h"
#include "movetree.h"

typedef struct pair_s
{
    char *key;
    char *value;
} pair_t;

typedef struct pgn_s
{
    movetree_t *moves;
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
    movetree_t *pgn_moves(pgn_db_t *db, int index);
    void free_pgn_db(pgn_db_t *db);
    void print_pgn_db(pgn_db_t *db);

#ifdef __cplusplus
}
#endif

#endif