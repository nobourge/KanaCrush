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


