//
// Created by noe on 30.07.22.
//

#include "test.h"

//main test function
#include "main.h"

int testAuto();
void testManual();
void test(std::string mode="auto") {
  if (mode == "auto") {
    std::cout << "test auto" << std::endl;
    testAuto();
  } else if (mode == "manual") {
    std::cout << "test manual" << std::endl;
    testManual();
  } else {
    std::cout << "test unknown mode" << std::endl;
  }

}
void testManual() {
  std::cout << "test()" << std::endl;
  std::cout << "please, insert board init mode" << std::endl;
  std::string parameter;
  std::cin >> parameter;
  std::shared_ptr<Board> board = std::make_shared<Board>();
  //    board_ = std::make_shared<Board>(parameter);
  //state_ of the game
  std::string state = "Ready";
  std::cout << "Game state_: " << state << std::endl;

}
int testAuto() {
  //main() test;
    std::cout << "testAuto()" << std::endl;
  MainWindow window;
  window.show();
  std::cout << "testAuto() end" << std::endl;

  return Fl::run();

}
