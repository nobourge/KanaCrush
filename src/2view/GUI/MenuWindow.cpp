//
// Created by noe on 08.08.22.
//

#include "MenuWindow.h"

//buttons
//close window
void MenuWindow::close(void *w) {
  MenuWindow *window = (MenuWindow *) w;
  window->hide();
}
void MenuWindow::run() {
  show();
  Fl::add_timeout(1.0, close, this);

  Fl::run();

}
