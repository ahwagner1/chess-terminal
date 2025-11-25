#include "include/king.hpp"

King::King(uint8_t x, uint8_t y, char c) : Piece(x, y, c)
{}

King::~King()
{}

char King::getPiece() const {
    return 'R';
}
