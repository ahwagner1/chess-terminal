#pragma once

#include "piece.hpp"

class Rook: public Piece {
public:
    Rook(uint8_t x, uint8_t y, char c);
    ~Rook();

    char getPiece() const override;
};
