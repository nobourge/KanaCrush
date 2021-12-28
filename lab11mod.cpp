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
#include <tuple>
#include <stdlib.h>     /* srand, rand */
#include <optional>


//std::tuple<char, char, char, char> CARDINALS;
//CARDINALS = make_tuple("N", "E", "S", "W");

/**
pair<int, int> CARDINALS_PAIR_ARRAY[4] = {make_pair(1, 0),
                                          make_pair(1, 0),
                                          make_pair(1, 0),
                                          make_pair(1, 0)};
*/

//AUCUNE VARIABLE GLOBALE
std::pair<int, int> CARDINALS_PAIR_ARRAY[4] = {{1,0},
                                          {0,1},
                                          {-1,0},
                                          {0,-1}};
const int CARDINALS_LEN = 4;



using namespace std;

const int windowWidth = 3500;
const int windowHeight = 3500;
const double refreshPerSecond = 60;

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
    /**
    void crush(){
        //todo
    };

    ///
    /// \param square1
    /// \param origin_cardinal
    /// \param destination_column
    /// \param destination_row
    /// \return
    std::optional<std::vector<std::pair<int,int>>> search_crush(squareType origin_square_type,
                                                  std::pair <int,int> origin_cardinal,
                                                  int destination_column,
                                                  int destination_row) {
        std::optional<vector<std::pair<int,int>>> cardinal_and_crush_pair_vec;
        pair<int,int> N_E_potential_crush = make_pair(0, 0);

        for (int i = 0; i < CARDINALS_LEN; i++) {
            const int cardinal_direction_int = i;
            pair<int, int> cardinal;
            cardinal = CARDINALS_PAIR_ARRAY[i];
            if (cardinal != origin_cardinal) {
                int same_type_quantity = 0;
                while (getSquareType(destination_row + cardinal.first,
                destination_column + cardinal.second)
                == origin_square_type){
                    same_type_quantity++;
                }
                const int axis_first_direction = cardinal_direction_int % 2;
                int axis_first_direction_same_type_quantity = std::get<axis_first_direction>(N_E_potential_crush);

                if (toCrush <= (axis_first_direction_same_type_quantity + same_type_quantity)) {
                    cardinal_and_crush_pair_vec.push_back(std::make_pair(cardinal_direction_int, same_type_quantity));
                    //cardinal_and_crush_pair_vec.emplace_back(i,same_type_quantity);

                    if(0 < axis_first_direction_same_type_quantity){
                        cardinal_and_crush_pair_vec.push_back(std::make_pair(axis_first_direction, axis_first_direction_same_type_quantity));
                    }
                } else {
                    //not enough same_type_quantity to crush but
                    if (cardinal_direction_int < 2)
                    {
                        //memorize for same axis other cardinal direction
                        std::get<cardinal_direction_int>(N_E_potential_crush) = same_type_quantity;
                    }
                }
            }
        }
        //return b ? std::optional<std::string>{"Godzilla"} : std::nullopt;
        if (cardinal_and_crush_pair_vec){
            return cardinal_and_crush_pair_vec;
        }
        return {};
    }
    */

    ///
    /// \param column
    /// \param row
    /// \return True if it was a valid move
    bool move (int column1, int row1, int destination_column, int destination_row) {
        if (currentGameState == Win
            || currentGameState == Crush)
            return false; // Can not move
        squareType origin_square_type = getSquareType(row1, column1);

        std::pair <int, int> origin_cardinal;
        origin_cardinal = make_pair(row1 - destination_row,
                                    column1 - destination_column);

        /**
        std::optional<std::vector<std::pair<int,int>>> cardinal_and_crush_pair_vec = search_crush(origin_square_type,
                                                                                            origin_cardinal,
                                                                                            destination_column,
                                                                                            destination_row
                                                                                            );
        if (cardinal_and_crush_pair_vec){
            // Change currentGameState to crush
            currentGameState = Crush;
            return true;
            //crush(cardinals_and_crushes)
        }
        else{
         board->swap(col1, row1, destination_column, destination_row);
        }
        */
    }
    void newGame() {
        for (auto &c: board) for (auto &x: c) x = candy_types[rand() % candy_types_len] ;
        currentGameState = Play;
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
        fl_draw_box(FL_FLAT_BOX, 0, 50, 2000, 2000, FL_BLUE);
        for (int x=0; x<Board::columns; x++)
            for (int y=0; y<Board::rows; y++) {
                switch (board->getSquareType(y, x)) {
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
            case Board::Play:
                message="Play";
                fl_color(FL_RED);
                break;
            case Board::Crush:
                message="Crush";
                fl_color(FL_BLACK);
                break;

            case Board::Win:
                message="Win!";
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
    bool swapable;
    ControllBoard(shared_ptr<Board> board): board{board} {};
    bool processEvent(const int event) {
        //static int push[2] = { 0, 0 };
        int col1;
        int row1;
        int destination_column;
        int destination_row;
        switch (event) {
            case FL_PUSH: {
                col1 = Fl::event_x()/50;
                row1 = Fl::event_y()/50;
                if (col1 >= 0 && col1<=Board::columns &&
                    row1 >= 0 && row1<=Board::rows) {

                    //push[0] = col1;
                    //push[1] = row1;
                    swapable = true;
                }
                return 1;
            }
            case FL_RELEASE: {
                board->swap(col1, row1, destination_column, destination_row);
                //board->move(col1, row1, destination_column, destination_row);
                return 1;
            }
            case FL_DRAG: {
                //The mouse has moved with a button held down. The current button state is in Fl::event_state().
                // The mouse position is in Fl::event_x() and Fl::event_y().
                //
                //In order to receive FL_DRAG events, the widget must return non-zero when handling FL_PUSH.
                destination_column = Fl::event_x()/50;
                destination_row = Fl::event_y()/50;

                if (swapable){
                    //position(offset[0]+Fl::event_x(), offset[1]+Fl::event_y());     // handle dragging
                    //board->draw();
                }
                return 1;
            }
            case FL_KEYDOWN:{
                switch (Fl::event_key()) {
                    case ' ':
                        board->newGame();
                        return true;
                    case 'q':
                        exit(0);
                }
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
            //:Fl_Window(y, x, windowWidth, windowHeight, "Lab 11"),
            :Fl_Window(300, 300, windowWidth, windowHeight, "Lab 11"),
            //todo: window always centered
             board{make_shared<Board>()},
             displayBoard(board),
             controllBoard(board) {
        Fl::add_timeout(1.0/refreshPerSecond, Timer_CB, this);
        resizable(this);
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
