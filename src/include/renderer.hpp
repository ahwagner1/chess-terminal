#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <array>
#include <fstream>
#include <algorithm>

/*
*   TODO:
*       Make ability to set the settings for the chess board
*           e.g. parse some sort of input config file to render the chess board
*           this way the user is responsible for it and not me
*
*           otherwise default to maybe something like white/blue board with spaces being
*           4 x 4 cells (with 2 spaces to make squares)
*/

// this will be the engine behing the TUI
// should be able to make a pretty clean UI
class Renderer {
private:
    // probably some sort of memory here on what colors to use for for/backgrounds
    // for both white and black pieces
    int rows, cols;

    void parseConfigFile(std::string filepath);
    std::string runCommand(const char *cmd) const;
    std::string colorToANSI(std::string color) const;

    // settings for output
    int xMargin, yMargin;
    int spaceWidth, spaceHeight;
    float cellWidth, cellHeight; // for determining ratio to make the board as "square" as possible
    std::string lightColor, darkColor;

public:
    Renderer();
    ~Renderer();

    void render();
};
