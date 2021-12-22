//
// Created by bourg on 20-12-21.
//

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

#include "src/control/cell/cell.cpp"
#include "C:/Users/Boss/Desktop/LdP2/KanaCrush/src/model/cell/Mcell.cpp"

const int windowWidth = 350;
const int windowHeight = 350;
const double refreshPerSecond = 60;

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