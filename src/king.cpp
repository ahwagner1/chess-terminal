#include "include/king.hpp"

King::King(uint8_t x, uint8_t y, char c) : Piece(x, y, c) {
    checked = false;
}

King::~King()
{}

bool King::getCheckStatus() const {
    return checked;
}

void King::setCheckStatus(bool status) {
    checked = status;
}

char King::getPiece() const {
    return 'K';
}

char King::getColor() const {
    return color;
}
