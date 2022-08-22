#ifndef KANACRUSH_SRC_2VIEW_GUI_CLICKABLECELL_H_
#define KANACRUSH_SRC_2VIEW_GUI_CLICKABLECELL_H_

#include "srcCommon.h"
#include "constants.h"
#include "Rectangle.h"

class ClickableCell :
        public Rectangle
 {
 public:
  // Constructor
    explicit ClickableCell(Point center
                           , int w
                           , int h
                           , Fl_Color frameColor
                           , Fl_Color fillColor);
};
#endif //KANACRUSH_SRC_2VIEW_GUI_CLICKABLECELL_H_
