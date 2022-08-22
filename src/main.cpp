

#include "main.h"
#include "2view/GUI/WelcomeWindow.h"
#include "2view/GUI/MenuWindow.h"

int main(int argc, char *argv[]) {

  WelcomeWindow welcome_window;
    welcome_window.run();

  MenuWindow menu_window;
    menu_window.run();

  GameWindow game_window;
  game_window.run();

  return Fl::run();
}