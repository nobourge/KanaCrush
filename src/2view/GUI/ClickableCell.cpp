//
// Created by noe on 08.08.22.
//

#include "ClickableCell.h"

void ClickableCell::draw() {
  animation_->draw();
}

void ClickableCell::animationF(Point mouseLoc, int direction, char directionText, Fl_Color newFillColor) {
  if (animation_->contains(mouseLoc)) {
    animation_->start(direction, directionText, newFillColor);
  }
}

Fl_Color ClickableCell::getColor(Point mouseLoc) {
  return animation_->PointgetColor(mouseLoc);
}

bool ClickableCell::isComplete() {
  return animation_->isComplete();
}

void ClickableCell::setFillColor(Fl_Color newFillColor) {
  animation_->setFillColor(newFillColor);
}


void ClickableCell::setFillColorFrom(int colorIndex) {
  animation_->setFillColor(Colors_codes[colorIndex]);
}
ClickableCell::ClickableCell(std::shared_ptr<Animation> animation) {
    animation_ = animation;

}
void ClickableCell::print() {
  std::cout << animation_->getFillColor() << std::endl;


}
Fl_Color ClickableCell::getFillColor() {
    return animation_->getFillColor();
}
