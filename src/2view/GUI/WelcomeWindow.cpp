#include "WelcomeWindow.h"
void WelcomeWindow::run() {
  show();
  Fl::add_timeout(1.0, close, this);

  Fl::run();

//  Fl_Window::show();
//  Fl::wait(3,hide());


//  hide();
}

//close window
void WelcomeWindow::close(void *w) {
  WelcomeWindow *window = (WelcomeWindow *) w;
  window->hide();
}
