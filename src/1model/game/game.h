//
// Created by noe on 28.07.22.
//

#ifndef KANACRUSH_SRC_1MODEL_GAME_GAME_H_
#define KANACRUSH_SRC_1MODEL_GAME_GAME_H_

#include "../board/Mboard.h"

class Game {

    std::shared_ptr<Board> board;
    //state of the game
    std::string state;

    int score{};
    int nbCellsCrushed{};
    int nbCellsCrushedTotal{};
    int nbCellsCrushedTotalMax{};


 public:
  Game();

};
#endif //KANACRUSH_SRC_1MODEL_GAME_GAME_H_
