//
// Created by noe on 27.07.22.
//

#ifndef KANACRUSH_SRC_2VIEW_SKETCHABLE_H_
#define KANACRUSH_SRC_2VIEW_SKETCHABLE_H_

#include "srcCommon.h"

class Sketchable {
 public:
  virtual void draw() =0;
  virtual bool contains(Point p) const =0;
  virtual Point getCenter() const =0;
  virtual Fl_Color getColor(Point mouseLoc) const =0;
  virtual void setFillColor(Fl_Color newFillColor) =0;
  virtual ~Sketchable() = default;;
};


//filled-in rectangle
//with different colors for the fill and the border
//displayed at a given location
class Rectangle: public Sketchable {
  Point center;
  int w, h;
  Fl_Color fillColor, frameColor;
 public:
  Rectangle(Point center, int w, int h,
            Fl_Color frameColor,
            Fl_Color fillColor);
  void draw() override;
  void setFillColor(Fl_Color newFillColor) override;
  Fl_Color getFillColor() const {
    return fillColor;
  }
  void setFrameColor(Fl_Color newFrameColor);
  Fl_Color getFrameColor() const {
    return frameColor;
  }
  void setWidth(int new_width) {
    w = new_width;
  }
  void setHeight(int new_height) {
    h = new_height;
  }
  int getWidth() const {
    return w;
  }
  int getHeight() const {
    return h;
  }
  bool contains(Point p) const override;
  Point getCenter() const override {
    return center;
  }
  Fl_Color getColor(Point mouseLoc) const override {
    return fillColor;
  }
};

#endif //KANACRUSH_SRC_2VIEW_SKETCHABLE_H_
