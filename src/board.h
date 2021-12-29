//
// Created by bourg on 28-12-21.
//

#ifndef KANACRUSH_BOARD_H
#define KANACRUSH_BOARD_H

#include srcCommon.h

class Board {
public:
    static const int rows = 9;
    static const int columns = 9;
    static const int toCrush = 3;
    enum squareType {Empty, Red, Black};
    squareType candy_types[2] =  {Red, Black};
    int candy_types_len = 2;
    //enum gameState {RedTurn, BlackTurn, RedWins, BlackWins, Tie};
    enum gameState {Play, Crush, Win};
private:
    gameState currentGameState = Play;
    array< array< squareType, columns >, rows > board;
public:
    Board() {}
    squareType getSquareType() const {}
    gameState getGameState() const {}

    void swap(){}
#endif //KANACRUSH_BOARD_H
