//
// Created by bourg on 20-12-21.
//
#include "Mcell.h"

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