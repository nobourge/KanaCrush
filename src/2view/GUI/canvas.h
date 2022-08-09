//
// Created by noe on 25.07.22.
//

#ifndef KANACRUSH_SRC_2VIEW_CANVAS_H_
#define KANACRUSH_SRC_2VIEW_CANVAS_H_

//#include "animation.h"
#include "constants.h"
#include "ClickableCell.h"
#include "src/1model/game/board/Mboard.h"

/*--------------------------------------------------
One instance of the canvas class is made by the
GameWindow class.

The fltk system via GameWindow calls:

draw 60 times a second
mouseClick whenever the mouse is clicked
keyPressed whenever a key is pressed

Any drawing code should be called ONLY in draw
or methods called by draw. If you try to draw
elsewhere it will probably crash.
--------------------------------------------------*/
class Canvas {
  std::shared_ptr<Board> board_;
  int cells_containers_size_;
    int cells_containers_container_size_;
  std::vector< ClickableCell > cells;
  Point mouse_click{}, mouse_release{}, mouse_hover{};
  Fl_Color cellColor1{}, cellColor2{};
  int n_du_carre_1_x_{},nDuCarre1Y{}, nDuCarre2X{}, nDuCarre2Y{};
  bool Test1{}, Test2{}, Test3{}, Test4{};
  bool AdjacentX{}, AdjacentY{};
 public:
  explicit Canvas(std::shared_ptr<Board> board);
  void draw();
  void mouseClick(Point mouseLoc);
  void keyPressed(int keyCode);
  void mouseRelease(Point mouseLoc);
//  void changeColors(int concCarre1, int concCarre2);
//  std::vector<ClickableCell> getCells();
  void update();
  void print();
};

#endif //KANACRUSH_SRC_2VIEW_CANVAS_H_
