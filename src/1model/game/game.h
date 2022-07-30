//
// Created by noe on 28.07.22.
//

#ifndef KANACRUSH_SRC_1MODEL_GAME_GAME_H_
#define KANACRUSH_SRC_1MODEL_GAME_GAME_H_

#include "../board/Mboard.h"

class Game {
  std::shared_ptr<Board> board_;
//  std::shared_ptr<Board> board_(nullptr);
//  std::shared_ptr<Board> board = std::make_shared<Board>("ascent");
//  auto board = std::make_shared<Board>("ascent"); //auto' not allowed in non-static class membe
//    std::shared_ptr<Board("ascent")> board; // Expected expression
//    std::shared_ptr<Board> board;
    //state_ of the game
    std::string state;

    int score{};
    int nbCellsCrushed{};
    int nbCellsCrushedTotal{};
    int nbCellsCrushedTotalMax{};


 public:
  Game();
//  explicit Game(const std::string& parameter);

//  void boardInit(const std::string &parameter);
};
#endif //KANACRUSH_SRC_1MODEL_GAME_GAME_H_
