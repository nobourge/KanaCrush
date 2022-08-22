#ifndef KANACRUSH_SRC_2VIEW_GUI_RECTANGLE_H_
#define KANACRUSH_SRC_2VIEW_GUI_RECTANGLE_H_

#include "sketchable.h"

//filled-in rectangle
//with different colors for the fill and the border
//displayed at a given location
class Rectangle: public Sketchable {

 public:
  Rectangle(Point center_, int w_1, int h_1, Fl_Color frame_color, Fl_Color fill_color);
  void draw() override;
  void drawAt(int x
      , int y
  );

  void print(const std::string& attribute) const;

};
#endif //KANACRUSH_SRC_2VIEW_GUI_RECTANGLE_H_
