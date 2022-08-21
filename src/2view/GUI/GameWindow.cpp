//
// Created by bourg on 28-12-21.
//

#include "srcCommon.h"
#include "GameWindow.h"



void GameWindow::draw()  {
  if(DEBUG_GAME_WINDOW) {
    std::cout << "GameWindow::draw()" << std::endl;
  }
  Fl_Window::draw();
  canvas_.draw();
}
void GameWindow::run(){
  if(DEBUG_GAME_WINDOW) {
    std::cout << "GameWindow::run()" << std::endl;
  }
    Fl::add_timeout(1.0 / refreshPerSecond, Timer_CB, this);
  show();
  if (DEBUG_GAME_WINDOW) {
    std::cout << "SLEEP" << std::endl;
  }
  unsigned int microsecond = 1000000;
//  usleep(3 * microsecond);//sleeps for 3 second
  game_.getBoard()->searchCrushableCells();
  usleep(3 * microsecond);//sleeps for 3 second

  while(game_.getBoard()->isCrushable()) {
    if (DEBUG_GAME_WINDOW) {
      std::cout << "GameWindow::run() - while" << std::endl;
      std::cout << "cells to crush: " << std::endl;
      game_.getBoard()->crushable_cells_Print();
    }
    game_.getBoard()->crush();
    game_.getBoard()->searchCrushableCells();
    usleep(3 * microsecond);//sleeps for 3 second
  }
  std::cout << " no more cells to crush" << std::endl;
};

int GameWindow::handle(int event) {
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
default:
return Fl_Window::handle(event);
}
}

