#include "srcCommon.h"
#include "GameWindow.h"

void GameWindow::draw()  {
  if(DEBUG_GAME_WINDOW) {
    std::cout << "GameWindow::draw()" << std::endl;
  }
  Fl_Window::draw();
  canvas_.draw();
}

// this runs the game window
void GameWindow::run(){
  if(DEBUG_GAME_WINDOW) {
    std::cout << "GameWindow::run()" << std::endl;
  }
    Fl::add_timeout(1.0 / refreshPerSecond, Timer_CB, this);
  show();

  game_.getBoard()->crushWhilePossible();

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

