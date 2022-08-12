//
// Created by noe on 27.07.22.
//

#include "sketchable.h"


void Sketchable::setWidth(int new_width) {
  width_ = new_width;
}
void Sketchable::setHeight(int new_height) {
  height_ = new_height;
}
int Sketchable::getWidth() const {
  return width_;
}
int Sketchable::getHeight() const {
  return height_;
}
//Point getCenter() {
//  return center_;
//}
void Sketchable::setFillColor(Fl_Color newFillColor) {
  fill_color_ = newFillColor;
}

void Sketchable::setFillColorFrom(int colorIndex) {
  setFillColor(Colors_codes[colorIndex]);
}
//Fl_Color Rectangle::getFillColor() const {
//    return fill_color_;
//}

void Sketchable::setFrameColor(Fl_Color newFrameColor) {
  frame_color_ = newFrameColor;
}


Fl_Color Sketchable::getFillColor() const {
  return fill_color_;

}
Fl_Color Sketchable::getFrameColor() const {
  return frame_color_;

}
Sketchable::Sketchable(Point center, int w, int h, Fl_Color frameColor, Fl_Color fillColor) {
  init(center, w, h, frameColor, fillColor);

}
void Sketchable::init(Point center, int w, int h, Fl_Color frameColor, Fl_Color fillColor) {
    center_ = center;
    width_ = w;
    height_ = h;
    fill_color_ = fillColor;
    frame_color_ = frameColor;

}
Point Sketchable::getCenter() {
    return center_;
}

bool Sketchable::contains(Point p) const  {
  return p.x>=center_.x-width_/2 &&
      p.x<center_.x+width_/2 &&
      p.y>=center_.y-height_/2 &&
      p.y<center_.y+height_/2;
}
