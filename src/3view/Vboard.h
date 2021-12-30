//
// Created by bourg on 28-12-21.
//

#ifndef KANACRUSH_VBOARD_H
#define KANACRUSH_VBOARD_H

#include "cell/Vcell.h"

class DisplayBoard {
    const shared_ptr<const Board> board;
public:
    DisplayBoard(const shared_ptr<const Board> board): board{board} {};
    void draw() const {}
};

#endif //KANACRUSH_VBOARD_H
