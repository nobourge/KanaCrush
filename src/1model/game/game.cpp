//
// Created by noe on 28.07.22.
//

#include "game.h"

Game::Game() {

  //cells initialization
  std::make_shared<Board>();
  // cells print
//    cells->printBoard();

//    cells->newGame();
    state = "Ready";
    std::cout << "Game state: " << state << std::endl;


}
