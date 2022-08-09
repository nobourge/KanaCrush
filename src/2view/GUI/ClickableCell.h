//
// Created by noe on 08.08.22.
//

#ifndef KANACRUSH_SRC_2VIEW_GUI_CLICKABLECELL_H_
#define KANACRUSH_SRC_2VIEW_GUI_CLICKABLECELL_H_

#include "animation.h"
#include "constants.h"

/*--------------------------------------------------
The Canvas class below will have ClickableCells as instance
variables and call the methods of ClickableCell
--------------------------------------------------*/
class ClickableCell {
  std::shared_ptr<Animation> animation_;
 public:
  // Constructor
  explicit ClickableCell(std::shared_ptr<Animation> animation);

  // Methods that draw and handle events
  void draw();
  void animationV1(Point mouseLoc);
  void animationV2(Point mouseLoc);
  void animationH1(Point mouseLoc);
  void animationH2(Point mouseLoc);
  void animationF(Point mouseLoc,
                  int dir,
                  char direction,
                  Fl_Color newFillColor);
  Fl_Color getColor(Point mouseLoc);
  Fl_Color getFillColor();
  void setFillColor(Fl_Color newFillColor);
  bool isComplete();
  void setFillColorFrom(int colorIndex);
  void print();
};


#endif //KANACRUSH_SRC_2VIEW_GUI_CLICKABLECELL_H_
