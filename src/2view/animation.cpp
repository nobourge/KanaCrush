// These should include everything you might use

//#include "constants.h"

#include "srcCommon.h"
#include <math.h>
#include <time.h>

#include <array>
#include <memory>
#include <unistd.h>

#include "animation.h"


#if __cplusplus >= 202002L
#include <numbers>
using std::numbers::pi;
#else
const double pi = 3.141592653589793238462643383279502884L;
#endif

using namespace std;





//
///*--------------------------------------------------
//Point structure.
//--------------------------------------------------*/
//struct Point {
//  int x,y;
//};
//
///*--------------------------------------------------
//Sketchable class.
//--------------------------------------------------*/
//class Sketchable {
// public:
//  virtual void draw() =0;
//  virtual bool contains(Point p) const =0;
//  virtual Point getCenter() const =0;
//  virtual Fl_Color getColor(Point mouseLoc) const =0;
//  virtual void setFillColor(Fl_Color newFillColor) =0;
//  virtual ~Sketchable() = default;;
//};

Rectangle::Rectangle(Point center, int w, int h,
                     Fl_Color frameColor,
                     Fl_Color fillColor)
    : center{center}, w{w}, h{h}, fillColor{fillColor},
      frameColor{frameColor} {}

void Rectangle::draw() {
  array<Point, 5> points{
    Point{center.x-w/2, center.y-h/2},
    Point{center.x-w/2, center.y+h/2},
    Point{center.x+w/2, center.y+h/2},
    Point{center.x+w/2, center.y-h/2},
    Point{center.x-w/2, center.y-h/2}};
  fl_color(fillColor);
  fl_begin_polygon();
  for (auto& point : points) {
    fl_vertex(point.x, point.y);
  }
  fl_end_polygon();
  fl_color(frameColor);
  fl_begin_line();
  for (auto& point : points) {
    fl_vertex(point.x, point.y);
  }
  fl_end_line();
}

void Rectangle::setFillColor(Fl_Color newFillColor) {
  fillColor = newFillColor;
}

void Rectangle::setFrameColor(Fl_Color newFrameColor) {
  frameColor = newFrameColor;
}

bool Rectangle::contains(Point p) const {
  return p.x>=center.x-w/2 &&
         p.x<center.x+w/2 &&
         p.y>=center.y-h/2 &&
         p.y<center.y+h/2;
}
//
///*--------------------------------------------------
//Animation class
//--------------------------------------------------*/
//class Animation: public Sketchable {
// protected:
//  shared_ptr<Sketchable> toAnimate;
// public:
//  Animation(shared_ptr<Sketchable> toAnimate)
//      : toAnimate{toAnimate} {}
//  virtual bool isComplete() =0;
//  virtual void start(int direction,
//                     char directionText,
//                     Fl_Color newFillColor) {
//    shared_ptr<Animation> a = dynamic_pointer_cast<Animation>(toAnimate);
//    if (a) a->start(1, 'V', FL_BLACK);
//  };
//  bool contains(Point p) const override {
//    return toAnimate->contains(p);
//  }
//  Point getCenter() const override {
//    return toAnimate->getCenter();
//  }
//  Fl_Color getColor(Point mouseLoc) const override {
//    return toAnimate->getColor(mouseLoc);
//  }
//  void setFillColor(Fl_Color newFillColor) override {
//    toAnimate->setFillColor(newFillColor);
//  }
//};

/*--------------------------------------------------
Translation Class
--------------------------------------------------*/
struct Translation {
  Translation(Point p, char directionText) {
    fl_push_matrix();
    if (directionText == 'V')
      fl_translate(p.x, p.y);
    else if (directionText == 'H')
      fl_translate(p.y, p.x);
  }
  ~Translation() {
    fl_pop_matrix();
  }
};



void Bounce::draw() {
  if (bouncing)
    ++time;
  Translation t1{currentTranslation(), directionText};
  toAnimate->draw();
  if (isComplete())
    bouncing = false;
}

Point Bounce::currentTranslation() {
  if (isComplete()) {
    toAnimate->setFillColor(color);
    return {0, 0};
  }
  else
    return {0, static_cast<int>(direction*bounceHeight*time/duration)};

}

bool Bounce::isComplete() {
  return time > duration;
}
//
///*--------------------------------------------------
//ClickableCell class
//
//The Canvas class below will have ClickableCells as instance
//variables and call the methods of ClickableCell
//--------------------------------------------------*/
//class ClickableCell {
//  shared_ptr<Animation> animation;
// public:
//  // Constructor
//  ClickableCell(shared_ptr<Animation> animation);
//
//  // Methods that draw and handle events
//  void draw();
//  void animationV1(Point mouseLoc);
//  void animationV2(Point mouseLoc);
//  void animationH1(Point mouseLoc);
//  void animationH2(Point mouseLoc);
//  void animationF(Point mouseLoc, int dir, char direction, Fl_Color newFillColor);
//  Fl_Color getColor(Point mouseLoc);
//  void setFillColor(Fl_Color newFillColor);
//  bool isComplete();
//};

ClickableCell::ClickableCell(shared_ptr<Animation> animation):
  animation{animation} {}

void ClickableCell::draw() {
  animation->draw();
}

void ClickableCell::animationF(Point mouseLoc, int direction, char directionText, Fl_Color newFillColor) {
  if (animation->contains(mouseLoc)) {
    animation->start(direction, directionText, newFillColor);
  }
}

Fl_Color ClickableCell::getColor(Point mouseLoc) {
  return animation->getColor(mouseLoc);
}

bool ClickableCell::isComplete() {
  return animation->isComplete();
}

void ClickableCell::setFillColor(Fl_Color newFillColor) {
  animation->setFillColor(newFillColor);
}
//
///*--------------------------------------------------
//Canvas class.
//
//One instance of the canvas class is made by the
//MainWindow class.
//
//The fltk system via MainWindow calls:
//
//draw 60 times a second
//mouseClick whenever the mouse is clicked
//keyPressed whenever a key is pressed
//
//Any drawing code should be called ONLY in draw
//or methods called by draw. If you try to draw
//elsewhere it will probably crash.
//--------------------------------------------------*/
//class Canvas {
//  vector< ClickableCell > cells;
//  Point mouse_click, mouse_release, mouse_hover;
//  Fl_Color cellColor1, cellColor2;
//  int n_du_carre_1_x_, nDuCarre1Y, nDuCarre2X, nDuCarre2Y;
//  bool Test1, Test2, Test3, Test4;
//  bool AdjacentX, AdjacentY;
// public:
//  Canvas();
//  void draw();
//  void mouseClick(Point mouseLoc);
//  void keyPressed(int keyCode);
//  void mouseRelease(Point mouseLoc);
//  void changeColors(int concCarre1, int concCarre2);
//};



