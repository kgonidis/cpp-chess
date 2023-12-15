#ifndef BOARD_HPP
#define BOARD_HPP

#include "types.hpp"
#include <string>
#include <vector>

namespace engine
{
    enum ECastling
    {
        WKCA = 1,
        WQCA = 2,
        BKCA = 4,
        BQCA = 8
    };

    class Game
    {
    public:
        Game();
        // copy constructor
        Game(const Game &g);
        // copy assignment
        Game &operator=(const Game &g);
        // move constructor
        Game(Game &&g);
        // move assignment
        Game &operator=(Game &&g);
        // ostream operator
        static Game fromFEN(std::string fen);

        uint8_t isAttacked(int square, int side) const;
        bool getPiece(int square, int &piece, int &side) const;
        bool generatePseudoMoves(std::vector<Move> &moves, int side, int piece, int square) const;
        bool generatePseudoMoves(std::vector<Move> &moves, int square) const;
        bool simulateMove(const Move &move, Game &game) const;
        bool simulateMove(const Move &move) const;
        bool validateMove(Move &move, Game &game) const;
        bool generateMoves(std::vector<Move> &moves, int side, int piece, int square) const;
        bool generateMoves(std::vector<Move> &moves, int square) const;
        void generateAllMoves(std::vector<Move> &moves, int side) const;
        u64 generateHashKey() const;
        void printAttackedSquares(int side) const;

        void addPiece(int square, int piece);
        bool makeMove(Move &move, bool validate = true);


        friend std::ostream &operator<<(std::ostream &os, const Game &g);

        Bitboard pieces[12];
        Bitboard occupancies[3];
        uint8_t castling;
        int enpassant;
        int side;
        u64 repetition_table[1000];
        u64 r_index;
        u64 hash;

        int halfMoveClock;
        int fullMoveNumber;
    };

    void printBitboard(Bitboard board);
}

#endif