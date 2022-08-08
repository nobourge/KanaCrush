//
// Created by noe on 28.07.22.
//

#ifndef KANACRUSH_SRC_1MODEL_GAME_GAME_H_
#define KANACRUSH_SRC_1MODEL_GAME_GAME_H_

#include "board/Mboard.h"
#include "../MVCinclude.h"

class Game {
  std::shared_ptr<Board> board_;
    //state_ of the game
    std::string state;

    int score{};
    int nbCellsCrushed{};
    int nbCellsCrushedTotal{};
    int nbCellsCrushedTotalMax{};


 public:
//  Game(argc, argv);
  Game();
//  explicit Game(const std::string& parameter);

//  void boardInit(const std::string &parameter);
};
#endif //KANACRUSH_SRC_1MODEL_GAME_GAME_H_
