//
// Created by bourg on 20-12-21.
//

#include "../../src.h"

//#include "../../../src/model/cell/Mcell.cpp"

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
            //case FL_
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