//
// Created by noe on 25.07.22.
//

#ifndef KANACRUSH_SRC_2VIEW_CANVAS_H_
#define KANACRUSH_SRC_2VIEW_CANVAS_H_

#include "animation.h"
#include "constants.h"

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
  std::vector< ClickableCell > cells;
  Point mouse_click, mouse_release, mouse_hover;
  Fl_Color cellColor1, cellColor2;
  int n_du_carre_1_x_, nDuCarre1Y, nDuCarre2X, nDuCarre2Y;
  bool Test1, Test2, Test3, Test4;
  bool AdjacentX, AdjacentY;
 public:
  Canvas();
  void draw();
  void mouseClick(Point mouseLoc);
  void keyPressed(int keyCode);
  void mouseRelease(Point mouseLoc);
//  void changeColors(int concCarre1, int concCarre2);
};

#endif //KANACRUSH_SRC_2VIEW_CANVAS_H_
