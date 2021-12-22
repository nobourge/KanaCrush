//
// Created by bourg on 22-12-21.
//

#include "lab11mod.h"

// These should include everything you might use
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include <string>
#include <math.h>
#include <time.h>
#include <chrono>
#include <vector>
#include <iostream>
#include <array>
#include <memory>

#define CARDINALS ("N", "E", "S", "W");
#define CARDINALS_TUP ((1,0),(0,1),(-1,0),(0,-1));
#define CARDINALS_LEN 4;

using namespace std;

const int windowWidth = 350;
const int windowHeight = 350;
const double refreshPerSecond = 60;

class Board {
public:
    static const int rows = 9;
    static const int columns = 9;
    //static const int toWin = 3;
    static const int toCrush = 3;
    enum squareType {Empty, Red, Black};
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
    squareType getSquare(int row, int column) const {
        return board.at(row).at(column);
    }
    gameState getGameState() const {
        return currentGameState;
    }

    ///
    /// \param square1
    /// \param origin_cardinal
    /// \param destination_column
    /// \param destination_row
    /// \return
    tuple search_crush(squareType square1,
                      tuple origin_cardinal,
                      int destination_column,
                      int destination_row) {
        tuple <int, int> crush;
        cardinals_and_crushes_tup = make_tuple(0,0);

        int x;
        //for (auto const& i : CARDINALS)
        for (int i, i <= CARDINALS_LEN, i++)
            cardinal = get<i>(CARDINALS_TUP);
            if (cardinal == origin_cardinal){
                break;
            }
            else{
                int same_type_quantity = 0;
                while (getSquare(destination_row + get<0>(CARDINALS),
                                destination_column + get<1>(CARDINALS))
                                == square1){
                    same_type_quantity++;
                }
                if (toCrush <= same_type_quantity){
                    tuple <int, int> crush_card;
                    card_and_crush_tup = make_tuple(i, same_type_quantity);
                    auto cardinals_and_crushes = tuple_cat(cardinals_and_crushes,card_and_crush_tup);
                }
            }
        if (2 < tuple_size<decltype(cardinals_and_crushes_tup)>::value){
            return cardinals_and_crushes_tup;
        }
    }

    ///
    /// \param column
    /// \param row
    /// \return True if it was a valid move
    bool move (int column1, int row1, int destination_column, int destination_row) {
        if (currentGameState == Win
            || currentGameState == Crush)
            return false; // Can not move
        squareType square1 = getSquare(row1, column1);

        tuple <int, int> origin_cardinal;
        origin_cardinal = make_tuple(row1 - destination_row, column1 - destination_column);

        tuple cardinals_and_crushes_tup = search_crush(square1,
                                            origin_cardinal,
                                            destination_column,
                                            destination_row);
        //:todo:
        if (cardinals_and_crushes_tup){
            crush(cardinals_and_crushes_tup)
        }


        // Finds where the piece should go
        //int row = 0;
        //while (row <rows && getSquare(row, column) == Empty) row+=1;
        //if (row==0) return false; // Row full
        //board.at(row-1).at(column)=currentGameState==RedTurn?Red: Black; //make move


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
        // This checks for a tie (all top squares are occupoed)
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


/*--------------------------------------------------
DispalyBoard class.
--------------------------------------------------*/


class DisplayBoard {
    const shared_ptr<const Board> board;
public:
    DisplayBoard(const shared_ptr<const Board> board): board{board} {};
    void draw() const {
        fl_draw_box(FL_FLAT_BOX, 0, 50, 1000, 1000, FL_BLUE);
        for (int x=0; x<Board::columns; x++)
            for (int y=0; y<Board::rows; y++) {
                switch (board->getSquare(y, x)) {
                    case Board::Red:
                        fl_color(FL_RED);
                        break;
                    case Board::Black:
                        fl_color(FL_BLACK);
                        break;
                    default:
                        fl_color(FL_WHITE);
                        break;
                }
                fl_begin_polygon();
                fl_circle(50*x+25, 50*y+75, 21);
                fl_end_polygon();
            }

        string message;
        switch (board->getGameState()) {
            case Board::RedTurn:
                message="Red's Turn";
                fl_color(FL_RED);
                break;
            case Board::BlackTurn:
                message="Black's Turn";
                fl_color(FL_BLACK);
                break;
            case Board::Tie:
                message="Tie";
                fl_color(FL_BLUE);
                break;
            case Board::RedWins:
                message="Red Wins!";
                fl_color(FL_RED);
                break;
            case Board::BlackWins:
                message="Black Wins!";
                fl_color(FL_BLACK);
                break;
        }
        fl_font(FL_HELVETICA, 20);
        int width{0}, height{0};
        fl_measure(message.c_str(), width, height, false);
        fl_draw(message.c_str(), 175-width/2, 30);
    }
};

/*--------------------------------------------------
ControllBoard class.
--------------------------------------------------*/

class ControllBoard {
    shared_ptr<Board> board;
public:
    ControllBoard(shared_ptr<Board> board): board{board} {};
    bool processEvent(const int event) {
        switch (event) {
            case FL_PUSH: {
                int col = Fl::event_x()/50;
                if (col>=0 && col<=Board::columns) {
                    board->move(col);
                    return true;
                }
                break;
            }
            case FL_KEYDOWN:
                switch (Fl::event_key()) {
                    case ' ':
                        board->newGame();
                        return true;
                    case 'q':
                        exit(0);
                }
        }
        return false;
    }
};

/*--------------------------------------------------
MainWindow class.
--------------------------------------------------*/

class MainWindow : public Fl_Window {
    shared_ptr<Board> board;
    DisplayBoard displayBoard;
    ControllBoard controllBoard;
public:
    MainWindow()
            :Fl_Window(500, 500, windowWidth, windowHeight, "Lab 11"),
             board{make_shared<Board>()},
             displayBoard(board),
             controllBoard(board) {
        Fl::add_timeout(1.0/refreshPerSecond, Timer_CB, this);
        // resizable(this);
    }
    void draw() override {
        Fl_Window::draw();
        displayBoard.draw();
    }
    int handle(int event) override {
        return controllBoard.processEvent(event);
    }
    static void Timer_CB(void *userdata) {
        MainWindow *o = (MainWindow*) userdata;
        o->redraw();
        Fl::repeat_timeout(1.0/refreshPerSecond, Timer_CB, userdata);
    }
};

int main(int argc, char *argv[]) {
    MainWindow window;
    window.show(argc, argv);
    return Fl::run();
}
