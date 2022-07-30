//
// Created by noe on 30.07.22.
//

#include "test.h"

//main test function
#include "main.h"
void test() {
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