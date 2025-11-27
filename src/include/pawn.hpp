#pragma once

#include "piece.hpp"

class Pawn: public Piece {
private:
    bool enPessantStatus;
public:
    Pawn(uint8_t x, uint8_t y, char c);
    ~Pawn();

    bool getEnPessantStatus() const;
    void setEnPessantStatus(bool status);

    char getPiece() const override;
    char getColor() const override;
};
