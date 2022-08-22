#ifndef KANACRUSH_SRC_1MODEL_BOARD_NODE_H_
#define KANACRUSH_SRC_1MODEL_BOARD_NODE_H_

#include "src/parameters.h"
#include "src/1model/game/board/cell/Mcell.h"

class Node : public Cell {
    std::shared_ptr<Cell> cell_;
    std::shared_ptr<Node> next_;
    std::shared_ptr<Node> prev_; //todo remove


public:
  Node();
    ~Node();
    void set_next(std::shared_ptr<Node> node);
    void set_prev(std::shared_ptr<Node> node);
  std::shared_ptr<Cell> get_cell();
  std::shared_ptr<Node> get_next();
    std::shared_ptr<Node> get_prev();
    void print();
};


#endif //KANACRUSH_SRC_1MODEL_BOARD_NODE_H_
