#pragma once

#include "piece.hpp"

class Pawn: public Piece {
private:
    bool enPessantable;
public:
    Pawn(uint8_t x, uint8_t y, char c);
    ~Pawn();


    char getPiece() const override;
};
