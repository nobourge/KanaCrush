//
// Created by noe on 25.07.22.
//

#ifndef KANACRUSH_SRC_2VIEW_ANIMATION_H_
#define KANACRUSH_SRC_2VIEW_ANIMATION_H_


#include "src/srcCommon.h"
#include "sketchable.h"
#include "srcCommon.h"
#include <math.h>
#include <time.h>
#include <array>
#include <memory>
#include <unistd.h>

#if __cplusplus >= 202002L
#include <numbers>
using std::numbers::pi;
#else
const double pi = 3.141592653589793238462643383279502884L;
#endif

using namespace std;

class Animation {
 protected:
  Animation();
  std::shared_ptr<Sketchable> to_animate_;
  bool animating_ = false;
  int duration_{};
  int time_{0};

  int direction_{};
  char direction_text_{} ;
//  Fl_Color color;
 public:
  virtual bool isComplete() =0;
  virtual void start() ;
  virtual void animate(std::shared_ptr<Sketchable> to_animate,
                       int duration,
                       int direction,
                       char directionText,
                       Fl_Color newFillColor);
  void setState();
};

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


#endif //KANACRUSH_SRC_2VIEW_ANIMATION_H_
