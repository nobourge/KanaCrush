//
// Created by bourg on 20-12-21.
//
#include "../../src.h"

using namespace std;

class Board {
public:
    static const int rows = 6;
    static const int columns = 7;
    static const int toWin = 4;
    enum squareType {Empty, Red, Black};
    enum gameState {RedTurn, BlackTurn, RedWins, BlackWins, Tie};
private:
    gameState currentGameState = RedTurn;
    bool blackWentFirst = true;
    array< array< squareType, columns >, rows > board;
public:
    Board() {
        newGame();
    }
    squareType getSquare(int row, int column) const {
        return board.at(row).at(column);
    }
    gameState getGameState() const {
        return currentGameState;
    }
    bool move (int column) { // Returns True if it was a valid move
        if (currentGameState==RedWins
            || currentGameState == BlackWins
            || currentGameState == Tie)
            return false; // Can not move
        // Finds where the piece should go
        int row = 0;
        while (row <rows && getSquare(row, column) == Empty) row+=1;
        if (row==0) return false; // Row full
        board.at(row-1).at(column)=currentGameState==RedTurn?Red: Black; //make move

        //This code checks to see if there are four in a row
        //Starting in every square and going in four different directions
        //(Horizonal, vertical, two diagonals)
        int x;
        for (int row=0; row<rows; row++)
            for (int column=0; column<columns; column++)
                if (getSquare(row, column)!=Empty) {
                    squareType color = getSquare(row, column);

                    for (x=1; x<toWin; x++)
                        if (row+x>=rows || getSquare(row+x, column)!=color) break;
                    if (x==toWin) {
                        currentGameState=(color==Red)?RedWins: BlackWins;
                        return true;
                    }
                    for (x=1; x<toWin; x++)
                        if (column+x>=columns || getSquare(row, column+x)!=color) break;
                    if (x==toWin) {
                        currentGameState=(color==Red)?RedWins: BlackWins;
                        return true;
                    }
                    for (x=1; x<toWin; x++)
                        if (row+x>=rows || column+x>=columns || getSquare(row+x, column+x)!=color) break;
                    if (x==toWin) {
                        currentGameState=(color==Red)?RedWins: BlackWins;
                        return true;
                    }
                    for (x=1; x<toWin; x++)
                        if (row+x>=rows || column-x<0 || getSquare(row+x, column-x)!=color) break;
                    if (x==toWin) {
                        currentGameState=(color==Red)?RedWins: BlackWins;
                        return true;
                    }
                }
        // This checks for a tie (all top squares are occupied)
        for (x=0; x<columns; x++) if (getSquare(0, x)==Empty) break;
        if (x==columns) {
            currentGameState = Tie;
            return true;
        }
        // Change whose turn it is
        currentGameState = currentGameState==RedTurn?BlackTurn: RedTurn;
        return true;
    }
    void newGame() {
        for (auto &c: board) for (auto &x: c) x = Empty;
        blackWentFirst=!blackWentFirst;
        currentGameState = blackWentFirst?BlackTurn: RedTurn;
    }
};