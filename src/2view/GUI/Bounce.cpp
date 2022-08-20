#include "Bounce.h"

#include <utility>

void Bounce::draw() {
//    if (bouncing)
//        ++time;
//    Translation t1{currentTranslation(), directionText};
//    to_animate_->draw();
//    if (isComplete())
//        bouncing = false;
}

Point Bounce::currentTranslation() {
  if (isComplete()) {
//    to_animate_->setFillColor(color);
    return {0, 0};
  }
  else {
    return {0, static_cast<int>(direction_*bounce_height_*time/duration_)};
  }

}

bool Bounce::isComplete() {
  return time_ > duration_;
}

Bounce::Bounce() : Animation() {
}

void Bounce::bounce(const shared_ptr<Sketchable>& sketchable, int duration, int bounceHeight, int dir,
                    char direction, Fl_Color newFillColor) {
  Translation t1{currentTranslation(), direction_text_};
  to_animate_->draw();
  setState();

}