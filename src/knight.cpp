#include "include/knight.hpp"

Knight::Knight(uint8_t x, uint8_t y, char c) : Piece(x, y, c)
{}

Knight::~Knight()
{}

// need to differ from king somehow
char Knight::getPiece() const {
    return 'N';
}
