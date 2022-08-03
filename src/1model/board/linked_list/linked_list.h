//
// Created by noe on 02.08.22.
//

#ifndef KANACRUSH_SRC_1MODEL_BOARD_LINKED_LIST_H_
#define KANACRUSH_SRC_1MODEL_BOARD_LINKED_LIST_H_

//linked_list.h
//#include <link.h>
//#include "linked_list.h"

//#include "src/1model/board/cell/Mcell.h"
#include "node/Node.h"
//#include "node/cell/Mcell.h"

//linked list of cells
class linked_list {
//head and tail of the list
    std::shared_ptr<Node> head_;
    std::shared_ptr<Node> tail_;
    int size_;

 public:
    linked_list();
    ~linked_list();
    void init(int size=10);
    void add(Node *node);
  void set_next(Node *node);
  void set_prev(Node *cell);
    void remove(Node *cell);
    void remove_all();
    void print();
  std::shared_ptr<Node> get_head();
  std::shared_ptr<Node> get_tail();
    int get_size();
    void set_head(Node *cell);
    void set_tail(Node *cell);
    void set_size(int size);

  Node *get_next();
  Node *get_prev();



};

#endif //KANACRUSH_SRC_1MODEL_BOARD_LINKED_LIST_H_
