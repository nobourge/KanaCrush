//
// Created by noe on 11.08.22.
//

#ifndef KANACRUSH_SRC_2VIEW_GUI_RECTANGLE_H_
#define KANACRUSH_SRC_2VIEW_GUI_RECTANGLE_H_

#include "sketchable.h"

//filled-in rectangle
//with different colors for the fill and the border
//displayed at a given location
class Rectangle: public Sketchable {

 public:
  Rectangle(Point center_1, int w_1, int h_1, Fl_Color frame_color, Fl_Color fill_color);
//  void draw() override;
  void draw() override;

  //print
  void print(const std::string& attribute) const;
};
#endif //KANACRUSH_SRC_2VIEW_GUI_RECTANGLE_H_
