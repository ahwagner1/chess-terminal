#include "include/game.hpp"

ChessGame::ChessGame() : board(ChessBoard()), turnCount(0)
{}

ChessGame::~ChessGame()
{}

Player ChessGame::determineTurn() const {
    if ((turnCount % 2) == 0)
        return Player::WHITE;

    return Player::BLACK;
}

void ChessGame::playGame() {

    // can make this check for checkmate or resignation instead of breaking from inf loop
    while (true) {
        Player whoseTurn = determineTurn();

        board.displayBoard();
        if (whoseTurn == Player::WHITE) {
            std::cout << "Choice?" << std::endl;

            char choice;
            std::cin >> choice;

            if (choice == 'Q')
                break;

        }
        else {

        }

        turnCount++;
    }
}
