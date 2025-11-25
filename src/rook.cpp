#include "include/rook.hpp"

Rook::Rook(uint8_t x, uint8_t y, char c) : Piece(x, y, c)
{}

Rook::~Rook()
{}

char Rook::getPiece() const {
    return 'R';
}
