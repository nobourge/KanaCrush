//
// Created by noe on 28.07.22.
//

#include "game.h"


//board constructor parameter = ascent
//Game::Game(const std::string& parameter) {
//  std::cout << "Game::Game(std::string parameter)" << std::endl;
//  if (parameter == "random") {
//    std::cout << "Game::Game(std::string parameter) random" << std::endl;
//    board_ = std::make_shared<Board>("random");
//  } else if (parameter == "ascent") {
//    std::cout << "Game::Game(std::string parameter) ascent" << std::endl;
//    board_ = std::make_shared<Board>("ascent");
//  } else {
//    std::cout << "Game::Game(std::string parameter) : unknown parameter, board initialization: random" << std::endl;
//    board_ = std::make_shared<Board>("random");
//  }
//  //state_ of the game
//  state_ = "Ready";
//  std::cout << "Game state_: " << state_ << std::endl;
//}
//
////board init mode set
//void Game::boardInit(const std::string& parameter) {
//  std::cout << "Game::boardInit(std::string parameter)" << std::endl;
//  if (parameter == "random") {
//    std::cout << "Game::boardInit(std::string parameter) random" << std::endl;
//    board_->cellsInitRandom();
//  } else if (parameter == "ascent") {
//    std::cout << "Game::boardInit(std::string parameter) ascent" << std::endl;
//    board_->cellsInitValueAscent();
//  } else {
//    std::cout << "Game::boardInit(std::string parameter) : unknown parameter, board initialization: random" << std::endl;
//    board_->cellsInitRandom();
//  }
//}

Game::Game() {
    std::cout << "Game::Game()" << std::endl;

//    std::cout << "please, insert board init mode" << std::endl;
//    std::string parameter;
//    std::cin >> parameter;
    board_ = std::make_shared<Board>();
//    board_ = std::make_shared<Board>(parameter);
    //state_ of the game
    state = "Ready";
    std::cout << "Game state_: " << state << std::endl;



    state = "Playing";
    std::cout << "Game state_: " << state << std::endl;
    board_->crushColumn(0,2,2);
    board_->get_cells(0)->print();
    board_->printBoard();
//    board_->get_cells(0)->move(board_->get_cells(0)->get_head(), board_->get_cells(0)->get_tail(), 3);


}

//Game::Game(int argc, char argv) {
//  std::cout << "Game::Game()" << std::endl;
//
////    std::cout << "please, insert board init mode" << std::endl;
////    std::string parameter;
////    std::cin >> parameter;
//  board_ = std::make_shared<Board>();
////    board_ = std::make_shared<Board>(parameter);
//  //state_ of the game
//  state = "Ready";
//  std::cout << "Game state_: " << state << std::endl;
//
//
//
//
//  state = "Playing";
//  std::cout << "Game state_: " << state << std::endl;
//  board_->crushColumn(0,2,2);
//  board_->get_cells(0)->print();
//  board_->printBoard();
////    board_->get_cells(0)->move(board_->get_cells(0)->get_head(), board_->get_cells(0)->get_tail(), 3);
//
//
//}

