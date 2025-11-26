#include "include/board.hpp"

ChessBoard::ChessBoard() {
    pieces[0][0] = std::make_unique<Rook>(0, 0, 'W');
    pieces[1][0] = std::make_unique<Knight>(1, 0, 'W');
    pieces[2][0] = std::make_unique<Bishop>(2, 0, 'W');
    pieces[3][0] = std::make_unique<Queen>(3, 0, 'W');
    pieces[4][0] = std::make_unique<King>(4, 0, 'W');
    pieces[5][0] = std::make_unique<Bishop>(5, 0, 'W');
    pieces[6][0] = std::make_unique<Knight>(6, 0, 'W');
    pieces[7][0] = std::make_unique<Rook>(7, 0, 'W');
    pieces[0][1] = std::make_unique<Pawn>(0, 1, 'W');
    pieces[1][1] = std::make_unique<Pawn>(1, 1, 'W');
    pieces[2][1] = std::make_unique<Pawn>(2, 1, 'W');
    pieces[3][1] = std::make_unique<Pawn>(3, 1, 'W');
    pieces[4][1] = std::make_unique<Pawn>(4, 1, 'W');
    pieces[5][1] = std::make_unique<Pawn>(5, 1, 'W');
    pieces[6][1] = std::make_unique<Pawn>(6, 1, 'W');
    pieces[7][1] = std::make_unique<Pawn>(7, 1, 'W');


    pieces[0][6] = std::make_unique<Pawn>(0, 6, 'B');
    pieces[1][6] = std::make_unique<Pawn>(1, 6, 'B');
    pieces[2][6] = std::make_unique<Pawn>(2, 6, 'B');
    pieces[3][6] = std::make_unique<Pawn>(3, 6, 'B');
    pieces[4][6] = std::make_unique<Pawn>(4, 6, 'B');
    pieces[5][6] = std::make_unique<Pawn>(5, 6, 'B');
    pieces[6][6] = std::make_unique<Pawn>(6, 6, 'B');
    pieces[7][6] = std::make_unique<Pawn>(7, 6, 'B');
    pieces[0][7] = std::make_unique<Rook>(0, 7, 'B');
    pieces[1][7] = std::make_unique<Knight>(1, 7, 'B');
    pieces[2][7] = std::make_unique<Bishop>(2, 7, 'B');
    pieces[3][7] = std::make_unique<Queen>(3, 7, 'B');
    pieces[4][7] = std::make_unique<King>(4, 7, 'B');
    pieces[5][7] = std::make_unique<Bishop>(5, 7, 'B');
    pieces[6][7] = std::make_unique<Knight>(6, 7, 'B');
    pieces[7][7] = std::make_unique<Rook>(7, 7, 'B');

    // nullptrs are easy to add in lol
    for (uint8_t x = 0; x < 8; x++) {
        for (uint8_t y = 2; y < 6; y++) {
            pieces[x][y] = nullptr;
        }
    }
}

ChessBoard::~ChessBoard() 
{}

// color coded printing to easily differentiate things
// add in function to pieces that returns the color so we can color code each piece
// and also loop through the pieces for each play on each turn
void ChessBoard::displayBoard() const {
    std::cout << "\033[2J\033[1;1H"; // clears the terminal
 
    for (uint8_t y = 0; y < 8; y++) {
        for (uint8_t x = 0; x < 8; x++) {
            std::cout << '|';
            if (pieces[x][y] == nullptr)
                std::cout << " ";
            else
                std::cout << pieces[x][y]->getPiece();
            std::cout << '|';
        }
        std::cout << std::endl;
    }
}

void ChessBoard::resetBoard() {
pieces[0][0] = std::make_unique<Rook>(0, 0, 'W');
    pieces[1][0] = std::make_unique<Knight>(1, 0, 'W');
    pieces[2][0] = std::make_unique<Bishop>(2, 0, 'W');
    pieces[3][0] = std::make_unique<Queen>(3, 0, 'W');
    pieces[4][0] = std::make_unique<King>(4, 0, 'W');
    pieces[5][0] = std::make_unique<Bishop>(5, 0, 'W');
    pieces[6][0] = std::make_unique<Knight>(6, 0, 'W');
    pieces[7][0] = std::make_unique<Rook>(7, 0, 'W');
    pieces[0][1] = std::make_unique<Pawn>(0, 1, 'W');
    pieces[1][1] = std::make_unique<Pawn>(1, 1, 'W');
    pieces[2][1] = std::make_unique<Pawn>(2, 1, 'W');
    pieces[3][1] = std::make_unique<Pawn>(3, 1, 'W');
    pieces[4][1] = std::make_unique<Pawn>(4, 1, 'W');
    pieces[5][1] = std::make_unique<Pawn>(5, 1, 'W');
    pieces[6][1] = std::make_unique<Pawn>(6, 1, 'W');
    pieces[7][1] = std::make_unique<Pawn>(7, 1, 'W');


    pieces[0][6] = std::make_unique<Pawn>(0, 6, 'B');
    pieces[1][6] = std::make_unique<Pawn>(1, 6, 'B');
    pieces[2][6] = std::make_unique<Pawn>(2, 6, 'B');
    pieces[3][6] = std::make_unique<Pawn>(3, 6, 'B');
    pieces[4][6] = std::make_unique<Pawn>(4, 6, 'B');
    pieces[5][6] = std::make_unique<Pawn>(5, 6, 'B');
    pieces[6][6] = std::make_unique<Pawn>(6, 6, 'B');
    pieces[7][6] = std::make_unique<Pawn>(7, 6, 'B');
    pieces[0][7] = std::make_unique<Rook>(0, 7, 'B');
    pieces[1][7] = std::make_unique<Knight>(1, 7, 'B');
    pieces[2][7] = std::make_unique<Bishop>(2, 7, 'B');
    pieces[3][7] = std::make_unique<Queen>(3, 7, 'B');
    pieces[4][7] = std::make_unique<King>(4, 7, 'B');
    pieces[5][7] = std::make_unique<Bishop>(5, 7, 'B');
    pieces[6][7] = std::make_unique<Knight>(6, 7, 'B');
    pieces[7][7] = std::make_unique<Rook>(7, 7, 'B');

    // nullptrs are easy to add in lol
    for (uint8_t x = 0; x < 8; x++) {
        for (uint8_t y = 2; y < 6; y++) {
            pieces[x][y] = nullptr;
        }
    }

}
