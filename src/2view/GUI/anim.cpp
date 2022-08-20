#include "anim.h"

bool Anim::contains(Point p) const override {
return toAnimate->contains(p);
}
Point Anim::getCenter() const override {
return toAnimate->getCenter();
}
Fl_Color Anim::getColor(Point mouseLoc) const override {
return toAnimate->getColor(mouseLoc);
}
void Anim::setFillColor(Fl_Color newFillColor) {
    toAnimate->setFillColor(newFillColor);
}