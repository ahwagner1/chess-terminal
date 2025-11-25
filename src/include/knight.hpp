#pragma once

#include "piece.hpp"

class Knight : public Piece {
public:
    Knight(uint8_t x, uint8_t y, char color);
    ~Knight();

    char getPiece() const override;
};
