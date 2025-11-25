#include "include/bishop.hpp"

Bishop::Bishop(uint8_t x, uint8_t y, char c) : Piece(x, y, c)
{}

Bishop::~Bishop()
{}

char Bishop::getPiece() const {
    return 'B';
}
