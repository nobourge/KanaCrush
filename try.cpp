// Note : to be able to restart the game we should create
// another file that's gonna launch this one
// prolly will work easily when we'll do the mvc
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include <string>
#include <cmath>
#include <ctime>
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
            Fl_Color frameColor = FL_BLACK,
            Fl_Color fillColor = FL_WHITE);
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
Translation Class
--------------------------------------------------*/
struct Translation {
  Translation(Point p) {
    fl_push_matrix();
    fl_translate(p.x, p.y);
  }
  ~Translation() {
    fl_pop_matrix();
  }
};


/*--------------------------------------------------
Rotation Class
--------------------------------------------------*/
struct Rotation {
  Rotation(Point center, double angle) {
    fl_push_matrix();
    fl_translate(center.x, center.y);
    fl_rotate(angle);
    fl_translate(-1*center.x, -1*center.y);
  }
  ~Rotation() {
    fl_pop_matrix();
  }
};


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
  virtual void start() {
    shared_ptr<Animation> a = dynamic_pointer_cast<Animation>(toAnimate);
    if (a) a->start();
  };
  bool contains(Point p) const override {
    return toAnimate->contains(p);
  }
  Point getCenter() const override {
    return toAnimate->getCenter();
  }
};


/*--------------------------------------------------
Spin Class
--------------------------------------------------*/
class Spin: public Animation {
  int duration;
  bool spinning{false};
  int time{0};
  double currentRotation();
 public:
  Spin(shared_ptr<Sketchable> toAnimate, int duration = 100)
      : Animation{toAnimate}, duration{duration} {}
  void draw() override;
  bool isComplete() override;
  void start() override {
    Animation::start();
    spinning = true;
    time = 0;
  }
};

void Spin::draw() {
  if (spinning)
    ++time;
  Rotation r{toAnimate->getCenter(), currentRotation()};
  toAnimate->draw();
  if (isComplete())
    spinning = false;
}

double Spin::currentRotation() {
  if (!isComplete())
    return time*360.0/duration;
  else
    return 0;
}

bool Spin::isComplete() {
  return time > duration;
}


/*--------------------------------------------------
Bounce Class
--------------------------------------------------*/
class Bounce: public Animation {
  int duration;
  int bounceHeight;
  bool bouncing = false;
  int time{0};
  Point currentTranslation();
 public:
  Bounce(shared_ptr<Sketchable> toAnimate,
         int duration = 100, int bounceHeight = 100)
      : Animation{toAnimate},
        duration{duration},
        bounceHeight{bounceHeight} {}
  void draw() override;
  bool isComplete() override;
  void start() override {
    Animation::start();
    bouncing = true;
    time = 0;
  }
};

void Bounce::draw() {
  if (bouncing)
    ++time;
  Translation t3{currentTranslation()};
  toAnimate->draw();
  if (isComplete())
    bouncing = false;
}

Point Bounce::currentTranslation() {
  if (isComplete())
    return {0, 0};
  else
    return {0, static_cast<int>(-1*bounceHeight*sin(pi*time/duration))};
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
  void animationF(Point mouseLoc, int dir, char direction, Fl_Color newFillColor);
  void animationG(Point mouseLoc);
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

void ClickableCell::animationG(Point mouseLoc) {
  if (animation->contains(mouseLoc)) {
    animation->start(-1, 'D', FL_WHITE);
    // animation->setFillColor(FL_WHITE);
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
  Point firstMouseLoc, secondMouseLoc, thirdMouseLoc;
  Fl_Color cellColor1, cellColor2;
  Fl_Color firstColor, secondColor, thirdColor;
  int nDuCarre1X, nDuCarre1Y, nDuCarre2X, nDuCarre2Y;
  int concCarre1, concCarre2, concCarre3;
  bool Test1, Test2, Test3, Test4;
  bool AdjacentX, AdjacentY;
  static const int rows = 9;
  static const int columns = 9;
  static const int toWin = 3;
 public:
  Canvas();
  bool crush();
  bool checkCrush();
  void draw();
  void mouseClick(Point mouseLoc);
  void keyPressed(int keyCode);
  void mouseRelease(Point mouseLoc);
  void changeColors(int concCarre1, int concCarre2);
  bool crushTest();
};

Canvas::Canvas() {
  srand(time(NULL)); // serves to get every time random colors
  for (int x = 0; x<rows+1; x++) {
    for (int y = 0; y<columns+1; y++) {
    cells.emplace_back(
        make_shared<Bounce>(
          make_shared<Spin>(
            make_shared<Rectangle>(Point{x*50-25, y*50-25}, 50, 50,
            FL_BLACK, (Fl_Color) Cols[rand()%6]))));
    }
  }
}

void Canvas::draw() {
  for (auto &c: cells) {
    c.draw();
  }
}

bool Canvas::crush() {
  bool canPlay = false;
  while (!canPlay) {
    canPlay = checkCrush();
  }
  return true;
}

bool Canvas::checkCrush() {
  for (int row = 0; row < rows; row++) {
    for (int column = 0; column < columns; column++) {
      if (column < columns-2) {
        concCarre1 = concatenate(column+1, row+1);
        concCarre2 = concatenate(column+2, row+1);
        concCarre3 = concatenate(column+3, row+1);
        firstMouseLoc = {column*50+25, row*50+25};
        secondMouseLoc = {(column+1)*50+25, row*50+25};
        thirdMouseLoc = {(column+2)*50+25, row*50+25};
        firstColor = cells[concCarre1].getColor(firstMouseLoc);
        secondColor = cells[concCarre2].getColor(secondMouseLoc);
        // cout << firstColor << " - " << secondColor << " - " << thirdColor << endl;
        // Horizontal crush test
        if (firstColor == secondColor && firstColor != FL_WHITE) {
          // If the third element is the same => crush
          if (secondColor == thirdColor) {
            cout << thirdColor << endl;
            // currentGameState = Crush;
            // crushing all the colors for a horizontal crush
            for (int crushcolumn = column; crushcolumn < column + 3; crushcolumn++) {
              int thisConcat = concatenate(crushcolumn+1, row+1);
              Point thisMouseLoc = {crushcolumn*50+25, row*50+25};
              cells[thisConcat].animationG(thisMouseLoc);
            }
            // for (auto &c: cells)
            //   c.animationF(firstMouseLoc, 1, 'D', FL_WHITE);
            // for (auto &c: cells)
            //   c.animationF(secondMouseLoc, 1, 'D', FL_WHITE);
            // for (auto &c: cells)
            //   c.animationF(thirdMouseLoc, 1, 'D', FL_WHITE);
            for (int hcrushrow = row; hcrushrow > 0; hcrushrow--) {
              for (int crushcolumn = column; crushcolumn < column + 3; crushcolumn++) {
                // board.at(hcrushrow).at(crushcolumn) = board.at(hcrushrow-1).at(crushcolumn); // make the colors fall
                int thisConcat = concatenate(crushcolumn+1, hcrushrow+1);
                Point thisMouseLoc = {crushcolumn*50+25, hcrushrow*50+25};
                Fl_Color newFillColor = cells[thisConcat].getColor(thisMouseLoc);
                cells[thisConcat].animationF(thisMouseLoc, 1, 'V', newFillColor);
              }
            }

          }
        }
      }
    }
  }
  return true;
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
    int cCarre1 = concatenate(nDuCarre1X+1, nDuCarre1Y+1);
    int cCarre2 = concatenate(nDuCarre2X+1, nDuCarre2Y+1);
    // getting the colors
    cellColor1 = cells[cCarre1].getColor(mouseLoc);
    cellColor2 = cells[cCarre2].getColor(mouse_release);
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
    crush();
  }
}

void Canvas::keyPressed(int keyCode) {
  switch (keyCode) {
    case 'q':
      exit(0);
    case ' ':
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