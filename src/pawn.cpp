#include "include/pawn.hpp"

Pawn::Pawn(uint8_t x, uint8_t y, char c) : Piece(x, y, c) {
    enPessantStatus = false;
}

Pawn::~Pawn()
{}

void Pawn::setEnPessantStatus(bool status) {
    enPessantStatus = status;
}

bool Pawn::getEnPessantStatus() const {
    return enPessantStatus;
}

char Pawn::getPiece() const {
    return 'P';
}

char Pawn::getColor() const {
    return color;
}
