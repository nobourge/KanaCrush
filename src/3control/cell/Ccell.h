#ifndef KANACRUSH_CELL_H
#define KANACRUSH_CELL_H

#include "../../1model/cell/Mcell.h"

class CRectangle{
    const shared_ptr<const Rectangle> rectangle;
    center;
    int w,h;
public:
    CRectangle(const shared_ptr<const Rectangle> rectangle): rectangle{rectangle} {});
    bool contains(Point p);
};

class CCell {
    const shared_ptr<const Cell> cell;
public:
    CCell(Point center,int w, int h);
    void mouseMove(Point mouseLoc);
    void mouseClick(Point mouseLoc1, int colorID);
};

#endif //KANACRUSH_CELL_H
