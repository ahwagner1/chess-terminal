#include "include/knight.hpp"

Knight::Knight(uint8_t x, uint8_t y, char c) : Piece(x, y, c)
{}

Knight::~Knight()
{}

char Knight::getPiece() const {
    return 'N';
}

char Knight::getColor() const {
    return color;
}
