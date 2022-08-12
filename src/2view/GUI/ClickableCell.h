//
// Created by noe on 08.08.22.
//

#ifndef KANACRUSH_SRC_2VIEW_GUI_CLICKABLECELL_H_
#define KANACRUSH_SRC_2VIEW_GUI_CLICKABLECELL_H_

//#include "animation.h"
//#include "Bounce.h"

#include "srcCommon.h"
#include "constants.h"
#include "Rectangle.h"

class ClickableCell :
    public Rectangle
//    public Sketchable
 {
 public:
  // Constructor
    explicit ClickableCell(
        Point center
                           , int w,
                           int h,
                            Fl_Color frameColor,
                            Fl_Color fillColor);
  // Methods that draw and handle events
//  void draw() override;
//  void animationV1(Point mouseLoc);
//  void animationV2(Point mouseLoc);
//  void animationH1(Point mouseLoc);
//  void animationH2(Point mouseLoc);
//  void bounce(Point mouseLoc,
//              int dir,
//              char direction,
//              Fl_Color newFillColor);
//  Fl_Color getColor(Point mouseLoc);
//  Fl_Color getFillColor();
//  void setFillColor(Fl_Color newFillColor);
//  bool isComplete();
//  void setFillColorFrom(int colorIndex);
//  void print();
};
#endif //KANACRUSH_SRC_2VIEW_GUI_CLICKABLECELL_H_
