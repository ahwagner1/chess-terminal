#pragma once

#include "board.hpp"

enum Player {
    W = 0,
    B = 1
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
    // likely could make some sort of class or enum representing individual moves
    // parsing should be pretty easy i think
    //std::vector<MOVES??> parseInputMove(std::string move) const;
    
};
