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

#include "C:/Users/Boss/Desktop/LdP2/KanaCrush/src/model/cell/Mcell.cpp"
#include "C:/Users/Boss/Desktop/LdP2/KanaCrush/src/view/cell/Vcell.cpp"

const int windowWidth = 350;
const int windowHeight = 350;
const double refreshPerSecond = 60;

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