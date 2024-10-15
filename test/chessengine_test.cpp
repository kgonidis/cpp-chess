#include "engine.h"
#include "stdio.h"
#include <iostream>
#include <fstream>
#include <sstream>

#include <gtest/gtest.h>

TEST(ChessEngine, PGNS)
{
    std::string filename = "assets/pgns/e4NYStyle.pgn";
    std::ifstream file(filename.c_str());
    
    EXPECT_EQ(file.is_open(), true);

    // read file into string
    std::stringstream buffer;
    buffer << file.rdbuf();
    auto trees = gametree_t::FromPGN(buffer.str().c_str());

    EXPECT_EQ(trees.size(), 17);
}