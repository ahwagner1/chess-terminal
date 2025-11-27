#pragma once

#include "piece.hpp"

class Queen: public Piece {
public:
    Queen(uint8_t x, uint8_t y, char c);
    ~Queen();

    char getPiece() const override;
    char getColor() const override;
};
