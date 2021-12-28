//
// Created by bourg on 20-12-21.
//

#ifndef KANACRUSH_CELL_H
#define KANACRUSH_CELL_H

class Rectangle{
    Point center;
    int w,h;
    Fl_Color fillColor, frameColor;
public:
    Rectangle(Point center,int w, int h,
              Fl_Color frameColor=FL_BLACK,
              Fl_Color fillColor=FL_WHITE);
    void draw();
    void setFillColor(Fl_Color newFillColor);
    void setFrameColor(Fl_Color newFrameColor);
    bool contains(Point p);
    int getColor();
};

class Cell {
    Rectangle r;
    vector<int> l{1, 91, 3, 2, 4, 232}; // voir fltk color map
    int index = rand() % l.size();
    int color = l[index];
    bool on=false;
public:
    Cell(Point center,int w, int h);
    void draw();
    void mouseMove(Point mouseLoc);
    void mouseClick(Point mouseLoc1, int colorID);
    int checkColors(Point mouseLoc);
    int retColor();
};
#endif //KANACRUSH_CELL_H
