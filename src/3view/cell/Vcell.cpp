//
// Created by bourg on 20-12-21.
//

#include "../../srcCommon.h"

//#include "../../../src/22control/cell/Ccell.cpp"
//#include "../../../src/1model/cell/Mcell.cpp"

//const int windowWidth = 350;
//const int windowHeight = 350;
//const double refreshPerSecond = 60;

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

Rectangle::Rectangle(Point center,int w, int h,
                     Fl_Color frameColor,
                     Fl_Color fillColor):
        center{center},w{w},h{h},fillColor{fillColor},frameColor{frameColor}{}

void Rectangle::draw(){
    fl_draw_box(FL_FLAT_BOX,center.x-w/2,center.y-h/2,w,h,fillColor);
    fl_draw_box(FL_BORDER_FRAME,center.x-w/2,center.y-h/2,w,h,frameColor);
}

void Rectangle::setFillColor(Fl_Color newFillColor){
    fillColor=newFillColor;
}

void Rectangle::setFrameColor(Fl_Color newFrameColor){
    frameColor=newFrameColor;
}

bool Rectangle::contains(Point p){
    return p.x>=center.x-w/2 &&
           p.x<center.x+w/2 &&
           p.y>=center.y-h/2 &&
           p.y<center.y+h/2;
}
int Rectangle::getColor() {
    return fillColor;
}

/*--------------------------------------------------
Cell class.
--------------------------------------------------*/

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

Cell::Cell(Point center,int w, int h):
        r(center,w,h,FL_BLACK, color){}
void Cell::draw(){
    r.draw();
}
void Cell::mouseMove(Point mouseLoc){
    if (r.contains(mouseLoc)){
        r.setFrameColor(FL_RED);
    }
    else {
        r.setFrameColor(FL_BLACK);
    }
}
void Cell::mouseClick(Point mouseLoc, int colorID){
    if (r.contains(mouseLoc)){
        r.setFillColor(colorID);
    }
}
int Cell::checkColors(Point mouseLoc) {
    if (r.contains(mouseLoc)) {
        return r.getColor();
    }
}
int Cell::retColor(){
    return r.getColor();
}

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