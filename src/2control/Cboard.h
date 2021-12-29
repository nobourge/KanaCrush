//
// Created by bourg on 28-12-21.
//

#ifndef KANACRUSH_CBOARD_H
#define KANACRUSH_CBOARD_H

class ControlBoard {
    shared_ptr<Board> board;
    Point mouse_click, mouse_move;
    int cellColor1;
    int cellColor2;
    int nDuCarre1X, nDuCarre1Y, nDuCarre2X, nDuCarre2Y;
public:
    int processEvent(const int event)
};

#endif //KANACRUSH_CBOARD_H
