//
// Created by bourg on 28-12-21.
//

#ifndef KANACRUSH_MAINWINDOW_H
#define KANACRUSH_MAINWINDOW_H
//

#include "constants.h"


#include "2view/canvas.h"
#include "1model/game/game.h"

class MainWindow : public Fl_Window {
  Game game;
  Canvas canvas;
 public:
  MainWindow() :Fl_Window(3000, 300, windowWidth, windowHeight, "Kana Crush") {
    Fl::add_timeout(1.0/refreshPerSecond, Timer_CB, this);
    // resizable(this);
  }
  void draw() override {
    Fl_Window::draw();
    canvas.draw();
  }
  int handle(int event) override {
    switch (event) {
      case FL_RELEASE:
        canvas.mouseRelease(Point{Fl::event_x(), Fl::event_y()});
        return 1;
      case FL_PUSH:
        canvas.mouseClick(Point{Fl::event_x(), Fl::event_y()});
        return 1;
      case FL_KEYDOWN:
        canvas.keyPressed(Fl::event_key());
        return 1;
    }
    return 0;
  }
  static void Timer_CB(void *userdata) {
    MainWindow *o = (MainWindow*) userdata;
    o->redraw();
    Fl::repeat_timeout(1.0/refreshPerSecond, Timer_CB, userdata);
  }
};

#endif //KANACRUSH_MAINWINDOW_H
