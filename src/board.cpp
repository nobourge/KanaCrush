//
// Created by bourg on 28-12-21.
//

#include "board.h"

class Board {
public:
    static const int rows = 9;
    static const int columns = 9;
    //static const int toWin = 3;
    static const int toCrush = 3;
    enum squareType {Empty, Red, Black};
    squareType candy_types[2] =  {Red, Black};
    int candy_types_len = 2;
    //enum gameState {RedTurn, BlackTurn, RedWins, BlackWins, Tie};
    enum gameState {Play, Crush, Win};
private:
    gameState currentGameState = Play;
    //bool blackWentFirst = true;
    array< array< squareType, columns >, rows > board;
public:
    Board() {
        newGame();
    }
    squareType getSquareType(int row, int column) const {
        return board.at(row).at(column);
    }
    gameState getGameState() const {
        return currentGameState;
    }

    void swap(int col1, int row1, int col2, int row2){
        squareType candy1square_type = getSquareType(row1, col1);
        board.at(row1).at(col1) = getSquareType(row2, col2);
        board.at(row2).at(col2) = candy1square_type;
    }