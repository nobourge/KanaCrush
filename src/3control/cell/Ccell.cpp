#include "Ccell.h"

CRectangle::CRectangle(const shared_ptr<const Rectangle> model_rectangle): model_rectangle{model_rectangle} {}):
        center{model_rectangle->center},
        w{model_rectangle->w},
        h{model_rectangle->h}

bool CRectangle::contains(Point p){
    return p.x>=center.x-w/2 &&
           p.x<center.x+w/2 &&
           p.y>=center.y-h/2 &&
           p.y<center.y+h/2;
}

CCell::CCell(Point center,int w, int h):
        r(center,w,h,FL_BLACK, color){}

void CCell::mouseMove(Point mouseLoc){
    if (r.contains(mouseLoc)){
        //r.setFrameColor(FL_RED);
        r.setFrameColor(FL_RED);
    }
    else {
        r.setFrameColor(FL_BLACK);
    }
}
void CCell::mouseClick(Point mouseLoc, int colorID){
    if (r.contains(mouseLoc)){
        r.setFillColor(colorID);
    }
}

int Cell::checkColors(Point mouseLoc) {
    if (r.contains(mouseLoc)) {
        return r.getColor();
    }
}
