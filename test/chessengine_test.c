#include "engine.h"
#include "stdio.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
    const char *input = argc > 1 ? argv[1] : "e4NYStyle.pgn";
    // prepend with assets/pgns/ without std::string
    char filename[100];
    sprintf(filename, "assets/pgns/%s", input);

    char *buffer = 0;
    long length;
    FILE *f = fopen(filename, "rb");

    if (f)
    {
        fseek(f, 0, SEEK_END);
        length = ftell(f);
        fseek(f, 0, SEEK_SET);
        buffer = malloc(length);
        if (buffer)
        {
            fread(buffer, 1, length, f);
        }
        fclose(f);
    }

    if (!buffer)
    {
        fprintf(stderr, "File not found: %s\n", filename);
        return 1;
    }

    gametree_t *gametrees;
    int n_games = gametrees_from_pgn(&gametrees, buffer);

    gametree_redo_move(gametrees);

    game_state_t game;
    gametree_get_position(gametrees, &game);
    game_print(game);

    gametree_undo_move(gametrees);

    return 0;
}