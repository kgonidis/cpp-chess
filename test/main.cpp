
#include "engine.hpp"
#include <iostream>

using namespace engine;

int main()
{
    auto game = Game::fromFEN("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    std::cout << game << std::endl;

    std::vector<Move> moves;
    game.generateMoves(moves, ESquare::e2);
    bool correct = game.makeMove(moves[1]);
    moves.clear();
    game.generateMoves(moves, ESquare::e7);
    correct = game.makeMove(moves[1]);

    // bishop
    moves.clear();
    game.generateAllMoves(moves, ESide::WHITE);

    for (auto move : moves)
    {
        Game g;
        game.simulateMove(move, g);

        std::cout << g << std::endl;

        // wait for input
        std::string input;
        std::cin >> input;
    }
    
    return 0;
}