#include "types.hpp"
#include <iostream>

namespace engine
{
    Bitboard::Bitboard()
        : board{0ULL}
    {
    }

    Bitboard::Bitboard(const u64 &board)
        : board{board}
    {
    }

    Bitboard::Bitboard(const Bitboard &b)
        : board{b.board}
    {
    }

    Bitboard &Bitboard::operator=(const Bitboard &b)
    {
        board = b.board;
        return *this;
    }

    Bitboard &Bitboard::operator=(const u64 &b)
    {
        board = b;
        return *this;
    }

    // move constructor
    Bitboard::Bitboard(Bitboard &&b)
        : board{b.board}
    {
    }

    Bitboard::Bitboard(u64 &&board)
        : board{board}
    {
    }

    // move assignment
    Bitboard &Bitboard::operator=(Bitboard &&b)
    {
        board = b.board;
        return *this;
    }

    Bitboard &Bitboard::operator=(u64 &&b)
    {
        board = b;
        return *this;
    }

    // arithmetic operators
    Bitboard Bitboard::operator~() const
    {
        return ~board;
    }

    Bitboard &Bitboard::operator*=(const Bitboard &b)
    {
        board *= b.board;
        return *this;
    }

    Bitboard &Bitboard::operator*=(const u64 &b)
    {
        board *= b;
        return *this;
    }

    Bitboard &Bitboard::operator/=(const Bitboard &b)
    {
        board /= b.board;
        return *this;
    }

    Bitboard &Bitboard::operator/=(const u64 &b)
    {
        board /= b;
        return *this;
    }

    // bitwise operators
    Bitboard &Bitboard::operator&=(const Bitboard &b)
    {
        board &= b.board;
        return *this;
    }

    Bitboard &Bitboard::operator&=(const u64 &b)
    {
        board &= b;
        return *this;
    }

    Bitboard &Bitboard::operator^=(const Bitboard &b)
    {
        board ^= b.board;
        return *this;
    }

    Bitboard &Bitboard::operator^=(const u64 &b)
    {
        board ^= b;
        return *this;
    }

    Bitboard &Bitboard::operator|=(const Bitboard &b)
    {
        board |= b.board;
        return *this;
    }

    Bitboard &Bitboard::operator|=(const u64 &b)
    {
        board |= b;
        return *this;
    }

    Bitboard &Bitboard::operator<<=(const Bitboard &b)
    {
        board <<= b.board;
        return *this;
    }

    Bitboard &Bitboard::operator<<=(const u64 &b)
    {
        board <<= b;
        return *this;
    }

    Bitboard &Bitboard::operator>>=(const Bitboard &b)
    {
        board >>= b.board;
        return *this;
    }

    Bitboard &Bitboard::operator>>=(const u64 &b)
    {
        board >>= b;
        return *this;
    }

    uint8_t Bitboard::operator[](const int &index) const
    {
        return (board >> index) & 1ULL;
    }

    Bitboard::operator u64() const
    {
        return board;
    }

    void Bitboard::set(const int &index)
    {
        board |= (1ULL << index);
    }

    void Bitboard::pop(const int &index)
    {
        board &= ~(1ULL << index);
    }

    int Bitboard::count() const
    {
        Bitboard b = *this;
        int count = 0;
        while (b)
        {
            b.board &= b.board - 1;
            count++;
        }
        return count;
    }

    int Bitboard::ls1b() const
    {
        if (!board)
            return -1;
        Bitboard b = (*this & -(*this)) - 1ULL;
        return b.count();
    }

    std::ostream &operator<<(std::ostream &os, const Bitboard &b)
    {
        for (int rank = 0; rank <= 7; rank++)
        {
            os << 8 - rank << " ";
            for (int file = 0; file <= 7; file++)
            {
                os << ((b.board & (1ULL << (rank * 8 + file))) ? '1' : '0') << " ";
            }
            os << std::endl;
        }

        os << "  a b c d e f g h" << std::endl;
        os << "value: " << b.board << "ULL" << std::endl;
        return os;
    }
}