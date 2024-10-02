#include "engine.h"
#include "stdio.h"
#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char **argv)
{
    std::string filename  = "assets/pgns/" + std::string(argc > 1 ? argv[1] : "e4NYStyle.pgn");
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "File not found: " << filename << std::endl;
        return 1;
    }

    // read file into string
    std::stringstream buffer;
    buffer << file.rdbuf();
    auto gametrees = gametree_t::FromPGN(buffer.str().c_str())[0];

    gametrees.redoMove();
    game_t game = gametrees.getPosition();
    std::cout << game << std::endl;
    gametrees.redoMove();

    movetree_t *root = gametrees.getRoot();
    delete root;
    return 0;
}