#ifndef KANACRUSH_SRC_2VIEW_GUI_WINDOW_H_
#define KANACRUSH_SRC_2VIEW_GUI_WINDOW_H_


#include "constants.h"
#include "FL_includes.h"

//todo make base for  Window classes
class GUIWindow : public Fl_Window{
public:
  GUIWindow(int x, int y, int w, int h, const char *l) : Fl_Window(x, y, w, h, l) {
  }
  void run();

  static void Timer_CB(void *userdata
//                         ,class *window
                             ) {
  }

};

#endif //KANACRUSH_SRC_2VIEW_GUI_WINDOW_H_
