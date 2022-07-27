//
// Created by bourg on 28-12-21.
//

#ifndef KANACRUSH_MBOARD_H
#define KANACRUSH_MBOARD_H

#include "cell/Mcell.h"
//#include "candy/candy.h"

class Board {
public:
    static const int rows = 9;
    static const int columns = 9;
    static const int toCrush = 3;

    enum squareType {Empty, Red, Black};
    //squareType candy_types[2] =  {Red, Black};
    //int candy_types_len = 2;
    enum gameState {Play, Crush, Win};
private:
    //gameState currentGameState = Play;
    std::array< std::array< squareType, columns >, rows > board;
public:
    Board()
    squareType getSquareType() const
    gameState getGameState() const
    //void swap(int row1, int col1, int row2, int col2)
    //bool crushFrom(int x, int y)

#endif //KANACRUSH_MBOARD_H
