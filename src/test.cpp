#include "test.h"

//main test function
#include "main.h"

int testAuto() {
  std::cout << "testAuto()" << std::endl;
  BOARD_SIZE = 9;

  CELLS_CONTAINERS_HEAD_ORIENTATION = "down";
  PARAMETRIZED = true;
  std::cout << "1: "  << std::endl;
  std::cout << "BOARD_SIZE: " << BOARD_SIZE << std::endl;
    std::cout << "CELLS_CONTAINERS_HEAD_ORIENTATION: " << CELLS_CONTAINERS_HEAD_ORIENTATION << std::endl;
    std::cout << "PARAMETRIZED: " << PARAMETRIZED << std::endl;

  return 0;
}

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
  std::string state = "Ready";
  std::cout << "Game state_: " << state << std::endl;

}


//parameters predefined test
void testAutoParameters() {
    std::cout << "testAutoParameters()" << std::endl;

  testAuto();
  std::cout << "testAutoParameters() end" << std::endl;


}
