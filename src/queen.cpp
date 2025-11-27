#include "include/queen.hpp"

Queen::Queen(uint8_t x, uint8_t y, char c) : Piece(x, y, c)
{}

Queen::~Queen()
{}

char Queen::getPiece() const {
    return 'Q';
}

char Queen::getColor() const {
    return color;
}
