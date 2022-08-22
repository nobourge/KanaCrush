#ifndef KANACRUSH_CBOARD_H
#define KANACRUSH_CBOARD_H

#include "cell/Mboard.h"
#include "cell/Ccell.h"
class ControlBoard {
    shared_ptr<Board> board;
    Point mouse_click, mouse_move;
    int nDuCarre1X, nDuCarre1Y, nDuCarre2X, nDuCarre2Y;
public:
    int processEvent(const int event)
};

#endif //KANACRUSH_CBOARD_H
