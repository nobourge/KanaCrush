//
// Created by noe on 10.08.22.
//

#ifndef KANACRUSH_SRC_2VIEW_GUI_BOUNCE_H_
#define KANACRUSH_SRC_2VIEW_GUI_BOUNCE_H_

#include "animation.h"
#include "ClickableCell.h"

class Bounce:
    public Animation
    {
  int bounce_height_;
  Point currentTranslation();
 public:
  Bounce();

  void draw();
  bool isComplete() override;

  void bounce(const shared_ptr<Sketchable>& sketchable,
              int duration,
              int bounceHeight,
              int dir,
              char direction,
              Fl_Color newFillColor);
};


#endif //KANACRUSH_SRC_2VIEW_GUI_BOUNCE_H_
