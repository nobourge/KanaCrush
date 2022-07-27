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
#include <unistd.h>

using namespace std;

const int windowWidth = 450;
const int windowHeight = 450;
const double refreshPerSecond = 60;
enum Colors{Red, Orange, Yellow, Green, Blue, Purple, White};
enum gameState {Ready, Crush, Win, Loss};

struct Point {
  int x,y;
};

class Board {
public:
  static const int rows = 9;
  static const int columns = 9;
  static const int toWin = 3;
private:
  gameState currentGameState = Ready;
  array< array< Colors, columns >, rows > board;
public:
  Board() {
    newGame();
    crush();
  }
  Colors getSquare(int row, int column) const {
    return board.at(row).at(column);
  }
  // A implementer plus tard pour ne pas laisser le joueur faire des moves lorsqu'un crush est anime
  // Ou ne plus laisser le joueur jouer s'il a gagne ou perdu
  gameState getGameState() const {
    return currentGameState;
  }
  // bool checkMove (int column, int row, Colors color, Point coeff) {
    // if (coeff.x == 0) {

    // }
    // else {

    // }
  //   for (int x = 0; x < 4; x++) {
  //     if (getColor(row, column) == getColor(row, column+1) && getColor(row, column+1) == getColor(row, column+2)) {
        
  //     }
  //   }
  // }
  bool move (int column, int row, Colors color) { // Returns True if it was a valid move
    if (currentGameState == Crush || currentGameState == Win || currentGameState == Loss)
      return false;
    board.at(row).at(column) = color; // make move
    return true;
  }
  bool crush() {
    // Re-do the crush till there're no crushes left
    bool canPlay = false;
    while (!canPlay) {
      canPlay = checkCrush();
    }
    return true;
  }
  // This code checks to see if there are three in a row or column
  // Starting in every square and going in two different directions
  // (Horizonal, vertical)
  // If crush found we restart the search
  bool checkCrush() {
    for (int row=0; row<rows; row++) {
      for (int column=0; column<columns; column++) {
        if (column < 7) {
          // Horizontal crush test
          if (getColor(row, column) == getColor(row, column+1)) {
            // If the third element is the same => crush
            if (getColor(row, column+1) == getColor(row, column+2)) {
              // not letting the player make a move while we crushing
              currentGameState = Crush;
              // crushing all the colors for a horizontal crush
              for (int crushcolumn = column; crushcolumn < column + 3; crushcolumn++) {
                  Colors color = static_cast<Colors>(6);
                  board.at(row).at(crushcolumn) = color; // make the colors fall
              }
              for (int hcrushrow = row; hcrushrow > 0; hcrushrow--) {
                for (int crushcolumn = column; crushcolumn < column + 3; crushcolumn++) {
                  board.at(hcrushrow).at(crushcolumn) = board.at(hcrushrow-1).at(crushcolumn); // make the colors fall
                }
              }
              // add colors to the upper row
              for (int i = 0; i<3; i++) {
                int index = rand()%6;
                Colors color = static_cast<Colors>(index);
                board.at(0).at(column+i) = color;
              }
              currentGameState = Ready;
              return false;
            }
            // If there's a possible move (aka the 4th element is the same as the first 2 ones) => we change the gameState
            else if (column < 6) {
              if (getColor(row, column+1) == getColor(row, column+3)) {
                currentGameState = Ready;
              }
            }
          }
          // Vertical crush test
          if (getColor(column, row) == getColor(column+1, row)) {
            if (getColor(column+1, row) == getColor(column+2, row)) {
              // not letting the player make a move while we crushing
              currentGameState = Crush;
              // crushing all the colors for a vertical crush
              for (int vcrushrow = column+2; vcrushrow >= 3; vcrushrow--) {
                board.at(vcrushrow).at(row) = board.at(vcrushrow-3).at(row); // make the colors fall
              }
              // add colors to the upper rows
              for (int i = 2; i>=0; i--) {
                int index = rand()%6;
                Colors color = static_cast<Colors>(index);
                board.at(i).at(row) = color;
              }
              currentGameState = Ready;
              return false;
            }
            else if (column < 6) {
              if (getColor(row, column+1) == getColor(row, column+3)) {
                currentGameState = Ready;
              }
            }
          }
        }
      }
    }
    return true;
  }
  // creates a new game
  void newGame() {
    for(int i=0; i<9;i++) {
      for (int j = 0; j<9; j++) {
          int index = rand()%6;
          Colors color = static_cast<Colors>(index);
          board.at(i).at(j) = color;
      }
    }
  }
  // returns the color
  Colors getColor(int row, int column) {
    return board.at(row).at(column);
  }
};

class DisplayBoard {
  const shared_ptr<const Board> board;
  int fillColor = 0;
public:
  DisplayBoard(const shared_ptr<const Board> board): board{board} {};
  void draw() const {
    fl_draw_box(FL_FLAT_BOX, 0, 0, 500, 500, FL_GRAY);
    for (int x=0; x<Board::columns; x++)
      for (int y=0; y<Board::rows; y++) {
        switch (board->getSquare(y, x)) {
          case Red:
            fl_color(1);
            break;
          case Orange:
            fl_color(91);
            break;
          case Yellow:
            fl_color(3);
            break;
          case Green:
            fl_color(2);
            break;
          case Blue:
            fl_color(4);
            break;
          case Purple:
            fl_color(232);
            break;
          default:
            fl_color(FL_WHITE);
            break;
        }

        /* It works with circles and rectangles */

        // fl_begin_polygon();
        // fl_circle(50*x+25, 50*y+25, 21);
        // fl_end_polygon();
        fl_draw_box(FL_FLAT_BOX,50*x,50*y,50,50, fl_color());
        fl_draw_box(FL_BORDER_FRAME,50*x,50*y,51,51,FL_BLACK);
      }
  }
};

class ControllBoard {
  shared_ptr<Board> board;
  Point mouse_click, mouse_release, mouse_hover;
  Colors cellColor1, cellColor2;
  int nDuCarre1X, nDuCarre1Y, nDuCarre2X, nDuCarre2Y;
  bool Test1, Test2, Test3, Test4;
  bool AdjacentX, AdjacentY;
public:
  ControllBoard(shared_ptr<Board> board): board{board} {};
  bool processEvent(const int event) {
    switch (event) {
      case FL_DRAG:
        return 1;
      case FL_RELEASE:
        mouse_release = Point{Fl::event_x(),Fl::event_y()};
        nDuCarre1X = trunc(mouse_click.x/50);
        nDuCarre1Y = trunc(mouse_click.y/50);
        nDuCarre2X = trunc(mouse_release.x/50);
        nDuCarre2Y = trunc(mouse_release.y/50);
        // testing for errors
        Test1 = nDuCarre1X >=0 && nDuCarre1X<=Board::columns;
        Test2 = nDuCarre1Y >=0 && nDuCarre1Y<=Board::rows;
        Test3 = nDuCarre2X >=0 && nDuCarre2X<=Board::columns;
        Test4 = nDuCarre2Y >=0 && nDuCarre2Y<=Board::rows;
        // testing if the second circle is adjacent to the first one
        AdjacentX = (abs(nDuCarre1X-nDuCarre2X) == 0 && abs(nDuCarre1Y-nDuCarre2Y) == 1);
        AdjacentY = (abs(nDuCarre1X-nDuCarre2X) == 1 && abs(nDuCarre1Y-nDuCarre2Y) == 0);        
        if (Test1 && Test2 && Test3 && Test4) {
          if (AdjacentX || AdjacentY) {
            cellColor1 = board->getColor(nDuCarre1Y, nDuCarre1X);
            cellColor2 = board->getColor(nDuCarre2Y, nDuCarre2X);
            // Point coeff = {nDuCarre1X-nDuCarre2X, nDuCarre1Y-nDuCarre2Y};
            // board->checkMove(nDuCarre2X, nDuCarre2Y, cellColor1, coeff);
            // board->checkMove(nDuCarre1X, nDuCarre1Y, cellColor2, coeff);
            board->move(nDuCarre2X, nDuCarre2Y, cellColor1);
            board->move(nDuCarre1X, nDuCarre1Y, cellColor2);
            board->crush();
            return true;
          }
        }
        return 1;
      case FL_MOVE:
        return 1;
      case FL_PUSH: {
        mouse_click = Point{Fl::event_x(),Fl::event_y()};
        return 1;
      }
      case FL_KEYDOWN:
        switch (Fl::event_key()) {
          case ' ':
            board->newGame();
            board->crush();
            return true;
          case 'q':
            exit(0);
        }
    }
    return false;
  }
};

class MainWindow : public Fl_Window {
  shared_ptr<Board> board;
  DisplayBoard displayBoard;
  ControllBoard controllBoard;
public:
  MainWindow()
      :Fl_Window(3000, 300, windowWidth, windowHeight, "Lab 11"),
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