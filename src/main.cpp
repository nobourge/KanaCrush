

#include "main.h"

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

  Menu menu;
    menu.run();
//MainMenu mainMenu;
  Game game;

  MainWindow window;
  window.show(argc, argv);

  return Fl::run();
}