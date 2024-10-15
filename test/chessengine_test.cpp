#include "engine.h"
#include "stdio.h"
#include <iostream>
#include <fstream>
#include <sstream>

#include <gtest/gtest.h>

TEST(ChessEngine, PgnString)
{
    std::array<std::string, 5> files = {
        "assets/pgns/lines.pgn",
        "assets/pgns/e4NYStyle.pgn",
        "assets/pgns/Morphy.pgn",
        "assets/pgns/MorphyTest.pgn",
        "assets/pgns/Vienna.pgn"};

    for (auto &filename : files)
    {
        std::ifstream file(filename.c_str());

        EXPECT_EQ(file.is_open(), true);

        // read file into string
        std::stringstream buffer;
        buffer << file.rdbuf();
        auto trees = gametree_t::FromPgn(buffer.str().c_str());

        for (auto &tree : trees)
        {
            std::string pgn = tree.toPgn();
            auto new_trees = gametree_t::FromPgn(pgn.c_str());
            EXPECT_EQ(new_trees.size(), 1);
            gametree_t &new_tree = new_trees[0];
            EXPECT_EQ(tree, new_tree);
        }
        file.close();
    }
}