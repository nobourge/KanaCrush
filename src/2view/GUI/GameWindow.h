//
// Created by bourg on 28-12-21.
//

#ifndef KANACRUSH_MAINWINDOW_H
#define KANACRUSH_MAINWINDOW_H

#include<unistd.h>

#include "constants.h"
#include "canvas.h"
#include "1model/game/game.h"

class GameWindow : public Fl_Window {
  Game game_ = Game();
  Canvas canvas_ = Canvas(game_.getBoard());
 public:
  GameWindow() : Fl_Window(3000,
                           300,
                           windowWidth,
                           windowHeight,
                           "Game") {
    Fl::add_timeout(1.0/refreshPerSecond, Timer_CB, this);
    // resizable(this);
  }
  void draw() override {
    Fl_Window::draw();
    canvas_.draw();
  }
  void run(){

    show();
    canvas_.draw();

    unsigned int microsecond = 1000000;
    usleep(3 * microsecond);//sleeps for 3 second
    game_.getBoard()->crush();

    canvas_.redraw();


        Fl::run();
  };
  int handle(int event) override {
    switch (event) {
      case FL_RELEASE:
        canvas_.mouseRelease(Point{Fl::event_x(), Fl::event_y()});
        return 1;
      case FL_PUSH:
        canvas_.mouseClick(Point{Fl::event_x(), Fl::event_y()});
        return 1;
      case FL_KEYDOWN:
        canvas_.keyPressed(Fl::event_key());
        return 1;
    }
    return 0;
  }
  static void Timer_CB(void *userdata) {
    GameWindow *o = (GameWindow*) userdata;
    o->redraw();
    Fl::repeat_timeout(1.0/refreshPerSecond, Timer_CB, userdata);
  }
};

#endif //KANACRUSH_MAINWINDOW_H
