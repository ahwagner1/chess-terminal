
#pragma once

#include "piece.hpp"

class King: public Piece {
public:
    King(uint8_t x, uint8_t y, char c);
    ~King();

    char getPiece() const override;
};
