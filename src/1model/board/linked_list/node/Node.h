//
// Created by noe on 02.08.22.
//

#ifndef KANACRUSH_SRC_1MODEL_BOARD_NODE_H_
#define KANACRUSH_SRC_1MODEL_BOARD_NODE_H_

//#include "src/1model/board/cell/Mcell.h"
#include "../../cell/Mcell.h"

//Cell heritage
class Node : private Cell {
    std::shared_ptr<Cell> cell_;
    std::shared_ptr<Node> next_;
    std::shared_ptr<Node> prev_;


public:
//    explicit Node(Node *cell);
  Node();
    ~Node();
    void set_next(std::shared_ptr<Node> node);
    void set_prev(std::shared_ptr<Node> node);
  std::shared_ptr<Node> get_cell();
  std::shared_ptr<Node> get_next();
    std::shared_ptr<Node> get_prev();
    void print();
};


#endif //KANACRUSH_SRC_1MODEL_BOARD_NODE_H_
