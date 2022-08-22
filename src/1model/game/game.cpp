#include "game.h"

Game::Game() {
    std::cout << "Game::Game()" << std::endl;

    board_ = std::make_shared<Board>();
    //state_ of the game
    state_ = "Ready";
    std::cout << "Game state_: " << state_ << std::endl;

  state_ = "Playing";
    std::cout << "Game state_: " << state_ << std::endl;
  board_->print();


}
std::shared_ptr<Board> Game::getBoard() {
  if (DEBUG_BOARD) {
    std::cout << "Game::getBoard()" << std::endl;
  }
  return board_;;
}


//crush column
void crushColumn(int column) {

}
