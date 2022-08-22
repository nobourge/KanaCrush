#include "ClickableCell.h"

ClickableCell::ClickableCell(Point center, int w, int h, Fl_Color frameColor, Fl_Color fillColor)
                             : Rectangle(center, w, h, frameColor, fillColor) {}