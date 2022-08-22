#include "Vcell.h"

VRectangle::VRectangle(const shared_ptr<const Rectangle> model_rectangle): model_rectangle{model_rectangle} {},
                     Fl_Color frameColor,
                     Fl_Color fillColor):
        center{model_rectangle->center},
        w{model_rectangle->w},
        h{model_rectangle->h},
        fillColor{model_rectangle->fillColor},
        frameColor{model_rectangle->frameColor}{}

void VRectangle::draw(){
    fl_draw_box(FL_FLAT_BOX,center.x-w/2,center.y-h/2,w,h,fillColor);
    fl_draw_box(FL_BORDER_FRAME,center.x-w/2,center.y-h/2,w,h,frameColor);
}

void VRectangle::setFillColor(Fl_Color newFillColor){
    fillColor=newFillColor;
}

void VRectangle::setFrameColor(Fl_Color newFrameColor){
    frameColor=newFrameColor;
}

int VRectangle::getColor() {
    return fillColor;
}

VCell::VCell(const shared_ptr<const Cell> cell):
        r(center,w,h,FL_BLACK, color){}

void VCell::draw(){
    r.draw();
}