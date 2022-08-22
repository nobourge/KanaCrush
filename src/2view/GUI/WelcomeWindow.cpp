#include "WelcomeWindow.h"
void WelcomeWindow::run() {
  show();
  Fl::add_timeout(1.0, close, this);

  Fl::run();

}

//close window
void WelcomeWindow::close(void *w) {
  WelcomeWindow *window = (WelcomeWindow *) w;
  window->hide();
}
