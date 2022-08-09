//
// Created by noe on 28.07.22.
//

#ifndef KANACRUSH_SRC_1MODEL_GAME_GAME_H_
#define KANACRUSH_SRC_1MODEL_GAME_GAME_H_

#include "board/Mboard.h"

class Game {
  std::shared_ptr<Board> board_;
  std::shared_ptr<Board> canvas_;
    std::string state_;
    int score_{};
    int nb_cells_crushed_{};

 public:
//  Game(argc, argv);
  Game();
//  explicit Game(const std::string& parameter);

//  void boardInit(const std::string &parameter);
  std::shared_ptr<Board> getBoard();
};
#endif //KANACRUSH_SRC_1MODEL_GAME_GAME_H_
