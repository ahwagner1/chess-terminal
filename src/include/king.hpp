
#pragma once

#include "piece.hpp"

class King: public Piece {
public:
    bool checked;
public:
    King(uint8_t x, uint8_t y, char c);
    ~King();

    bool getCheckStatus() const;
    void setCheckStatus(bool status);

    char getPiece() const override;
    char getColor() const override;
};
