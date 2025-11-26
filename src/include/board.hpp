#pragma once

#include <iostream>
#include <array>
#include <memory>

#include "piece.hpp"
#include "pawn.hpp"
#include "rook.hpp"
#include "knight.hpp"
#include "bishop.hpp"
#include "queen.hpp"
#include "king.hpp"

class ChessBoard {
private:
    // so ugly lol
    std::array<std::array<std::unique_ptr<Piece>, 8>, 8> pieces;
    void setDefaultBoard();

public:
    ChessBoard();
    ~ChessBoard();

    void displayBoard() const;
    void resetBoard();
};
