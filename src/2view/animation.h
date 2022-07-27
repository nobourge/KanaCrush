//
// Created by noe on 25.07.22.
//

#ifndef KANACRUSH_SRC_2VIEW_ANIMATION_H_
#define KANACRUSH_SRC_2VIEW_ANIMATION_H_


#include <srcCommon.h>
//#include <src/2view/Vboard.h>
//#include "Vboard.h"

//class Canvas {
// public:
//  Canvas(const shared_ptr<const Board> board);
//  void draw() const;
//  void update();
//  bool isFinished() const;
//  void setFinished(bool finished);
// private:
//  const shared_ptr<const Board> board;
//  bool finished;
//};


/*--------------------------------------------------
Sketchable class.
--------------------------------------------------*/
class Sketchable {
 public:
  virtual void draw() =0;
  virtual bool contains(Point p) const =0;
  virtual Point getCenter() const =0;
  virtual Fl_Color getColor(Point mouseLoc) const =0;
  virtual void setFillColor(Fl_Color newFillColor) =0;
  virtual ~Sketchable() = default;;
};


/*--------------------------------------------------
Rectangle class.

Use to display a filled-in rectangle on the screen
with different colors for the fill and the border
--------------------------------------------------*/
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

/*--------------------------------------------------
Animation class
--------------------------------------------------*/
class Animation: public Sketchable {
 protected:
  std::shared_ptr<Sketchable> toAnimate;
 public:
  Animation(std::shared_ptr<Sketchable> toAnimate)
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
  Fl_Color getColor(Point mouseLoc) const override {
    return toAnimate->getColor(mouseLoc);
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
  void start(int dir, char dirText, Fl_Color newFillColor) override {
    Animation::start(dir, dirText, newFillColor);
    bouncing = true;
    time = 0;
    direction = dir;
    directionText = dirText;
    color = newFillColor;
  }
};

/*--------------------------------------------------
ClickableCell class

The Canvas class below will have ClickableCells as instance
variables and call the methods of ClickableCell
--------------------------------------------------*/
class ClickableCell {
  std::shared_ptr<Animation> animation;
 public:
  // Constructor
  ClickableCell(std::shared_ptr<Animation> animation);

  // Methods that draw and handle events
  void draw();
  void animationV1(Point mouseLoc);
  void animationV2(Point mouseLoc);
  void animationH1(Point mouseLoc);
  void animationH2(Point mouseLoc);
  void animationF(Point mouseLoc, int dir, char direction, Fl_Color newFillColor);
  Fl_Color getColor(Point mouseLoc);
  void setFillColor(Fl_Color newFillColor);
  bool isComplete();
};


#endif //KANACRUSH_SRC_2VIEW_ANIMATION_H_
