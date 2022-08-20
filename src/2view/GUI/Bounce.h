#ifndef KANACRUSH_SRC_2VIEW_GUI_BOUNCE_H_
#define KANACRUSH_SRC_2VIEW_GUI_BOUNCE_H_

#include "animation.h"
#include "ClickableCell.h"
#include <time.h>

class Bounce: public Animation {
  int bounce_height_;
    int duration;
    int bounceHeight;
    bool bouncing = false;
    int time{0};
    int direction = -1;
    char directionText;
    Fl_Color color;
//    Point currentTranslation();
 public:
  Bounce();
  Point currentTranslation();
  void draw();
  bool isComplete() override;
  void start(int direction, char directionText, Fl_Color newFillColor) override {
//    Animation::start();
    time = 0;
    bouncing = true;
    this->direction = direction;
    this->directionText = directionText;
    this->color = newFillColor;
  }
  void bounce(const shared_ptr<Sketchable>& sketchable, int duration, int bounceHeight, int dir, char direction,
              Fl_Color newFillColor);
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

#endif //KANACRUSH_SRC_2VIEW_GUI_BOUNCE_H_
