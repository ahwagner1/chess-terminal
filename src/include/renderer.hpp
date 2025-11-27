#pragma once

#include <iostream>

#include "board.hpp"

// this will be the engine behing the TUI
// should be able to make a pretty clean UI
class Renderer {
private:
    // probably some sort of memory here on what colors to use for for/backgrounds
    // for both white and black pieces
public:
    Renderer();
    ~Renderer();

    void render(ChessBoard& board);
};
