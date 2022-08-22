#ifndef KANACRUSH_CELL_H
#define KANACRUSH_CELL_H

#include "../../1model/cell/Mcell.h"

#include <stdlib.h>     /* srand, rand */


class VRectangle{
    const shared_ptr<const Rectangle> rectangle;
    center;
    int w,h;
    Fl_Color fillColor, frameColor;
public:
    VRectangle(const shared_ptr<const Rectangle> rectangle): rectangle{rectangle} {},
              Fl_Color frameColor=FL_BLACK,
              Fl_Color fillColor=FL_WHITE);
    void draw();
    void setFillColor(Fl_Color newFillColor);
    void setFrameColor(Fl_Color newFrameColor);
    bool contains(Point p);
    int getColor();
};

class VCell {
    vector<int> l{1, 91, 3, 2, 4, 232}; // voir fltk color map
    int index = rand() % l.size();
    int color = l[index];
public:
    VCell(Point center,int w, int h);
    void draw();
};

#endif //KANACRUSH_CELL_H
