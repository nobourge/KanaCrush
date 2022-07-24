// These should include everything you might use
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include <string>
#include <math.h>
#include <time.h>
#include <chrono>
#include <vector>
#include <iostream>
#include <array>
#include <memory>
#include <unistd.h>
#include <random>

#if __cplusplus >= 202002L
#include <numbers>
using std::numbers::pi;
#else
const double pi = 3.141592653589793238462643383279502884L;
#endif

using namespace std;

const int windowWidth = 450;
const int windowHeight = 450;
const double refreshPerSecond = 60;
enum gameState {Ready, Crush, Win, Loss};
int Cols[6] {1, 2, 3, 4, 91, 232};


/*--------------------------------------------------
concatenate method.

Used to concatenate 2 ints into 1.
--------------------------------------------------*/
unsigned concatenate(unsigned x, unsigned y) {
    unsigned pow = 10;
    while(y >= pow)
        pow *= 10;
    return x * pow + y;        
}

/*--------------------------------------------------
Point structure.
--------------------------------------------------*/
struct Point {
  int x,y;
};

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
  virtual ~Sketchable() {};
};

/*--------------------------------------------------
Rectangle class.

Use to display a fillend-in rectangle on the screen
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
  void setFillColor(Fl_Color newFillColor);
  Fl_Color getFillColor() {
    return fillColor;
  }
  void setFrameColor(Fl_Color newFrameColor);
  Fl_Color getFrameColor() {
    return frameColor;
  }
  void setWidth(int neww) {
    w = neww;
  }
  void setHeight(int newh) {
    h = newh;
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

/*--------------------------------------------------
Animation class
--------------------------------------------------*/
class Animation: public Sketchable {
 protected:
  shared_ptr<Sketchable> toAnimate;
 public:
  Animation(shared_ptr<Sketchable> toAnimate)
      : toAnimate{toAnimate} {}
  virtual bool isComplete() =0;
  virtual void start(int direction, char directionText, Fl_Color newFillColor) {
    shared_ptr<Animation> a = dynamic_pointer_cast<Animation>(toAnimate);
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
  void setFillColor(Fl_Color newFillColor) {
    toAnimate->setFillColor(newFillColor);
  }
};

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

/*--------------------------------------------------
Bounce Class
--------------------------------------------------*/
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
  Bounce(shared_ptr<Sketchable> toAnimate,
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

/*--------------------------------------------------
ClickableCell class

The Canvas class below will have ClickableCells as instance
variables and call the methods of ClickableCell
--------------------------------------------------*/
class ClickableCell {
  shared_ptr<Animation> animation;
 public:
  // Constructor
  ClickableCell(shared_ptr<Animation> animation);

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

/*--------------------------------------------------
Canvas class.

One instance of the canvas class is made by the
MainWindow class.

The fltk system via MainWindow calls:

draw 60 times a second
mouseClick whenever the mouse is clicked
keyPressed whenever a key is pressed

Any drawing code should be called ONLY in draw
or methods called by draw. If you try to draw
elsewhere it will probably crash.
--------------------------------------------------*/
class Canvas {
  vector< ClickableCell > cells;
  Point mouse_click, mouse_release, mouse_hover;
  Fl_Color cellColor1, cellColor2;
  int nDuCarre1X, nDuCarre1Y, nDuCarre2X, nDuCarre2Y;
  bool Test1, Test2, Test3, Test4;
  bool AdjacentX, AdjacentY;
 public:
  Canvas();
  void draw();
  void mouseClick(Point mouseLoc);
  void keyPressed(int keyCode);
  void mouseRelease(Point mouseLoc);
  void changeColors(int concCarre1, int concCarre2);
};

Canvas::Canvas() {
  srand(time(NULL)); // serves to get every time random colors
  for (int x = 0; x<10; x++) {
    for (int y = 0; y<10; y++) {
    cells.emplace_back(
        make_shared<Bounce>(
            make_shared<Rectangle>(Point{x*50-25, y*50-25}, 50, 50,
            FL_BLACK, (Fl_Color) Cols[rand()%6])));
    }
  }
}

void Canvas::draw() {
  for (auto &c: cells) {
    c.draw();
  }
}

void Canvas::mouseClick(Point mouseLoc) {
  mouse_click = Point{Fl::event_x(),Fl::event_y()};
}

void Canvas::mouseRelease(Point mouseLoc) {
  mouse_release = Point{Fl::event_x(),Fl::event_y()};
  nDuCarre1X = trunc(mouse_click.x/50);
  nDuCarre1Y = trunc(mouse_click.y/50);
  nDuCarre2X = trunc(mouse_release.x/50); 
  nDuCarre2Y = trunc(mouse_release.y/50);
  // testing if the second rectangle is adjacent to the first one
  AdjacentX = (abs(nDuCarre1X-nDuCarre2X) == 0 && abs(nDuCarre1Y-nDuCarre2Y) == 1);
  AdjacentY = (abs(nDuCarre1X-nDuCarre2X) == 1 && abs(nDuCarre1Y-nDuCarre2Y) == 0);
  if (AdjacentX || AdjacentY) {
    // put the coordinates together to be able to access them through cells
    int concCarre1 = concatenate(nDuCarre1X+1, nDuCarre1Y+1);
    int concCarre2 = concatenate(nDuCarre2X+1, nDuCarre2Y+1);
    // getting the colors
    cellColor1 = cells[concCarre1].getColor(mouseLoc);
    cellColor2 = cells[concCarre2].getColor(mouse_release);
    // doing the animation always inwards for all the directions possible
    // and changing the colors accordingly right after the animation is ended
    if (nDuCarre2Y > nDuCarre1Y) {
      for (auto &c: cells)
        c.animationF(mouse_click, 1, 'V', cellColor2);
      for (auto &c: cells)
        c.animationF(mouse_release, -1, 'V', cellColor1);
    }
    else if (nDuCarre2Y < nDuCarre1Y) {
      for (auto &c: cells)
        c.animationF(mouse_release, 1, 'V', cellColor1);
      for (auto &c: cells)
        c.animationF(mouse_click, -1, 'V', cellColor2);
    }
    else if (nDuCarre2X > nDuCarre1X) {
      for (auto &c: cells)
        c.animationF(mouse_click, 1, 'H', cellColor2);
      for (auto &c: cells)
        c.animationF(mouse_release, -1, 'H', cellColor1);
    }
    else if (nDuCarre2X < nDuCarre1X) {
      for (auto &c: cells)
        c.animationF(mouse_release, 1, 'H', cellColor1);
      for (auto &c: cells)
        c.animationF(mouse_click, -1, 'H', cellColor2);
    }
  }
}

void Canvas::keyPressed(int keyCode) {
  switch (keyCode) {
    case 'q':
      exit(0);
    case 32: // Space bar
      exit(0);
  }

}

/*--------------------------------------------------
MainWindow class.
--------------------------------------------------*/

class MainWindow : public Fl_Window {
  Canvas canvas;
public:
  MainWindow() :Fl_Window(3000, 300, windowWidth, windowHeight, "Kana Crush") {
    Fl::add_timeout(1.0/refreshPerSecond, Timer_CB, this);
    // resizable(this);
  }
  void draw() override {
    Fl_Window::draw();
    canvas.draw();
  }
  int handle(int event) override {
    switch (event) {
      case FL_RELEASE:
        canvas.mouseRelease(Point{Fl::event_x(), Fl::event_y()});
        return 1;
      case FL_PUSH:
        canvas.mouseClick(Point{Fl::event_x(), Fl::event_y()});
        return 1;
      case FL_KEYDOWN:
        canvas.keyPressed(Fl::event_key());
        return 1;
    }
    return 0;
  }
  static void Timer_CB(void *userdata) {
    MainWindow *o = (MainWindow*) userdata;
    o->redraw();
    Fl::repeat_timeout(1.0/refreshPerSecond, Timer_CB, userdata);
  }
};

/*--------------------------------------------------
main
--------------------------------------------------*/

int main(int argc, char *argv[]) {
  MainWindow window;
  window.show(argc, argv);
  return Fl::run();
}