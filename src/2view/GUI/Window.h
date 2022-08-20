#ifndef KANACRUSH_SRC_2VIEW_GUI_WINDOW_H_
#define KANACRUSH_SRC_2VIEW_GUI_WINDOW_H_


#include "constants.h"
#include "FL_includes.h"

//todo make base for  Window classes
class GUIWindow : public Fl_Window{
public:
  GUIWindow(int x, int y, int w, int h, const char *l) : Fl_Window(x, y, w, h, l) {
//    Fl::add_timeout(1.0 / refreshPerSecond
//                    ,Timer_CB(this)
//                    ,this
//                    );
  }
  void run();

  static void Timer_CB(void *userdata
//                         ,class *window
                             ) {
//    this *o = (this*) userdata;
//    o->redraw();
//    Fl::repeat_timeout(1.0/refreshPerSecond, Timer_CB(), userdata);
  }

};

#endif //KANACRUSH_SRC_2VIEW_GUI_WINDOW_H_
