#pragma once

#include "board.hpp"

enum Player {
    WHITE = 0,
    BLACK = 1
};

class ChessGame {
private:
    ChessBoard board;

    uint32_t turnCount;

public:
    ChessGame();
    ~ChessGame();

    Player determineTurn() const;
    void playGame();

    // need function that can parse chess algebraic notation
    // and then checks if that move is legal or not
};
