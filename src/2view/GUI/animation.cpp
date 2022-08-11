

#include "animation.h"

#include <utility>

void Animation::start(){
  time_ = 0;
    animating_ = true;
//    std::shared_ptr<Animation> a = std::dynamic_pointer_cast<Animation>(to_animate_);
//    if (a) a->start(1
//                    , 'V'
//                    , FL_BLACK);

}
Animation::Animation() {
//  init(std::move(toAnimate), duration);

}
//init
//void Animation::init(std::shared_ptr<Sketchable> toAnimate, int duration) {
//  to_animate_ = std::move(toAnimate);
//  duration_ = duration;
//}
void Animation::setState() {
  if (animating_)
    ++time_;
  if (isComplete())
    animating_ = false;

}
void Animation::animate(std::shared_ptr<Sketchable> to_animate,
                        int duration,
                        int direction,
                        char directionText,
                        Fl_Color newFillColor) {
    to_animate_ = std::move(to_animate);
  duration_ = duration;
    direction_ = direction;
    direction_text_ = directionText;

  start();

}
