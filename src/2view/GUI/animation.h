//
// Created by noe on 25.07.22.
//

#ifndef KANACRUSH_SRC_2VIEW_ANIMATION_H_
#define KANACRUSH_SRC_2VIEW_ANIMATION_H_


#include "src/srcCommon.h"
#include "sketchable.h"

class Animation: public Sketchable {
 protected:
  std::shared_ptr<Sketchable> toAnimate;
 public:
  explicit Animation(std::shared_ptr<Sketchable> toAnimate)
      : toAnimate{toAnimate} {}
  virtual bool isComplete() =0;
  virtual void start(int direction,
                     char directionText,
                     Fl_Color newFillColor) {
    std::shared_ptr<Animation> a = std::dynamic_pointer_cast<Animation>(toAnimate);
    if (a) a->start(1, 'V', FL_BLACK);
  };
  bool contains(Point p) const override {
    return toAnimate->contains(p);
  }
  Point getCenter() const override {
    return toAnimate->getCenter();
  }
  Fl_Color PointgetColor(Point mouseLoc) const override {
    return toAnimate->PointgetColor(mouseLoc);
  }
  Fl_Color getFillColor() const  {
    return toAnimate->getFillColor();
  }

  void setFillColor(Fl_Color newFillColor) override {
    toAnimate->setFillColor(newFillColor);
  }
};


class Bounce: public Animation {
  int duration;
  int bounceHeight;
  bool bouncing = false;
  int time{0};
  int direction = -1;
  char directionText;
  Fl_Color color;
  Point currentTranslation();
 public:
  Bounce(std::shared_ptr<Sketchable> toAnimate,
         int duration = 50, int bounceHeight = 50)
      : Animation{toAnimate},
        duration{duration},
        bounceHeight{bounceHeight},
        direction{direction} {}
  void draw() override;
  bool isComplete() override;
  void start(int dir,
             char dirText,
             Fl_Color newFillColor) override {
    Animation::start(dir, dirText, newFillColor);
    bouncing = true;
    time = 0;
    direction = dir;
    directionText = dirText;
    color = newFillColor;
  }
};


#endif //KANACRUSH_SRC_2VIEW_ANIMATION_H_
