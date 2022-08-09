

#include "main.h"
#include "2view/GUI/WelcomeWindow.h"
#include "2view/GUI/MenuWindow.h"

int main(int argc, char *argv[]) {
//  int test_number=1;
//  if (argc < 2) {
//    std::cout << "Usage: " << argv[0] << " <test_number>" << std::endl;
//  }
//  else {
//     test_number = atoi(argv[1]);
//
//  }
//    switch (test_number) {
//      case 1:
//        testAuto();
//        break;
//      case 2:
//        testManual();
//        break;
//
//      default:
//        std::cout << "Unknown test number" << std::endl;
//        break;
//    }

  WelcomeWindow welcome_window;
    welcome_window.run();

  MenuWindow menu_window;
    menu_window.run();

  GameWindow game_window;
  game_window.run();

  return Fl::run();
}