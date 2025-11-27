#pragma once

#include "piece.hpp"

class Bishop: public Piece {
public:
    Bishop(uint8_t x, uint8_t y, char c);
    ~Bishop();

    char getPiece() const override;
    char getColor() const override;
};
