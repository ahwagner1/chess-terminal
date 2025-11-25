#include "include/pawn.hpp"

Pawn::Pawn(uint8_t x, uint8_t y, char c) : Piece(x, y, c) {
    enPessantable = false;
}

Pawn::~Pawn()
{}

char Pawn::getPiece() const {
    return 'P';
}
