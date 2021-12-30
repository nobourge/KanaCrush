//
// Created by bourg on 20-12-21.
//

#ifndef KANACRUSH_CELL_H
#define KANACRUSH_CELL_H


struct Point {
    int x,y;
};

class Rectangle{
    Point center;
    int w,h;
public:
    Rectangle(Point center,int w, int h);
};

class Cell {
public:
    Cell(Point center,int w, int h);
};
#endif //KANACRUSH_CELL_H
