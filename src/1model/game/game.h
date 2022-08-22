#ifndef KANACRUSH_SRC_1MODEL_GAME_GAME_H_
#define KANACRUSH_SRC_1MODEL_GAME_GAME_H_

#include "board/Mboard.h"

class Game(size) {
  std::shared_ptr<Board(size)> board_;
//  std::shared_ptr<Board(size)> canvas_;
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
