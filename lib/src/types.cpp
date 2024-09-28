#include "types.h"
#include "constants.h"
#include <iostream>

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

int Bitboard::popls1b()
{
    int index = ls1b();
    if (index != -1)
        pop(index);
    return index;
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

void bitboard_set(Bitboard *b, int index)
{
    *b |= (1ULL << index);
}

void bitboard_pop(Bitboard *b, int index)
{
    *b &= ~(1ULL << index);
}

int bitboard_count(const Bitboard *b)
{
    Bitboard bb = *b;
    int count = 0;
    while (bb)
    {
        bb &= bb - 1;
        count++;
    }
    return count;
}

int bitboard_ls1b(const Bitboard *b)
{
    if (!*b)
        return -1;
    Bitboard bb = (*b & -(*b)) - 1ULL;
    return bb.count();
}

int bitboard_popls1b(Bitboard *b)
{
    int index = bitboard_ls1b(b);
    if (index != -1)
        bitboard_pop(b, index);
    return index;
}

void move_to_san(const move_t san, char *san_str)
{
    if (san.castling & e_castling::KCA)
    {
        strcpy(san_str, "O-O");
        return;
    }
    if (san.castling & e_castling::QCA)
    {
        strcpy(san_str, "O-O-O");
        return;
    }

    int index = 0;
    if (san.piece != e_piece::P && san.piece != e_piece::p)
    {
        *san_str = ASCII_PIECES[san.piece % 6];
        index++;
    }

    if (san.capture != e_piece::no_piece)
    {
        if (san.piece == e_piece::P || san.piece == e_piece::p)
            san_str[index++] = (char)(san.source % 8 + 'a');
        san_str[index++] = 'x';
    }

    strcpy(&san_str[index], CHAR_SQUARE_MAP[san.target]);
    index += strlen(CHAR_SQUARE_MAP[san.target]);

    if (san.promotion != e_piece::no_piece)
        san_str[index++] = ASCII_PIECES[san.promotion];

    if (san.check)
        san_str[index] = '+';

    if (san.checkmate)
        san_str[index] = '#';
}