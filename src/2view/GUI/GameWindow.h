#ifndef KANACRUSH_MAINWINDOW_H
#define KANACRUSH_MAINWINDOW_H

#include<unistd.h>

#include "constants.h"
#include "canvas.h"
#include "1model/game/game.h"


class GameWindow : public Fl_Window
    {
  Game game_ = Game();
  Canvas canvas_ = Canvas(game_.getBoard());
 public:

    GameWindow() :Fl_Window(
        3000,
        300,
        windowWidth,
        windowHeight,
        "Game") {
        Fl::add_timeout(1.0 / refreshPerSecond, Timer_CB, this);

    };

  void draw() override;
  void run();
  int handle(int event) override;

  static void Timer_CB(void *userdata) {
    if (DEBUG_GAME_WINDOW) {
      std::cout << "Timer_CB" << std::endl;
    }
    auto *gameWindow = static_cast<GameWindow *>(userdata);
    gameWindow->redraw();
    gameWindow->canvas_.redraw();
    Fl::repeat_timeout(1.0 / refreshPerSecond, Timer_CB, userdata);
  }
};
#endif //KANACRUSH_MAINWINDOW_H
