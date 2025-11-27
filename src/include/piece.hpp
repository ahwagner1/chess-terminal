#pragma once

#include <stdint.h>
#include <utility>

class Piece {
protected:
    std::pair<uint8_t, uint8_t> position;
    char color; // W or B

public:
    Piece(uint8_t x, uint8_t y, char c);
    virtual ~Piece();

    virtual char getPiece() const = 0;
    virtual char getColor() const = 0;
};
