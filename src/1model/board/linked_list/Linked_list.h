//
// Created by noe on 02.08.22.
//

#ifndef KANACRUSH_SRC_1MODEL_BOARD_LINKED_LIST_H_
#define KANACRUSH_SRC_1MODEL_BOARD_LINKED_LIST_H_

#include "node/Node.h"

class Linked_list {
//head and tail of the list
    std::shared_ptr<Node> head_;
    std::shared_ptr<Node> tail_;
    int size_{};

    //iterator_
    std::shared_ptr<Node> iterator_;

 public:
    Linked_list();
    ~Linked_list();
    void init(int size=9);
//    void add(Node *node);
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

//  std::shared_ptr<Node> get_next();
//  std::shared_ptr<Node> get_prev();

//iterator
  void begin();
  void end();
  void next();
  void previous();



  //set_iterator
    void set_iterator(Node *node);
//get_iterator
  std::shared_ptr<Node> get_iterator();
  bool is_begin();
  bool is_end();
  void reset();

//  void set_values();
//  void set_values(std::string mode="increment");
  void remove(std::shared_ptr<Node> node);
  void set_next(std::shared_ptr<Node> node);
  void set_prev(std::shared_ptr<Node> node);
  void set_tail(std::shared_ptr<Node> node);
  void set_head(std::shared_ptr<Node> node);
  void add(std::shared_ptr<Node> node);
  void set_values(std::string mode,
                  int head=0,
                  int tail=0);
  std::shared_ptr<Node> get_next(std::shared_ptr<Node> node);
  std::shared_ptr<Node> get_prev(std::shared_ptr<Node> node);
  std::shared_ptr<Node> get_node(int index);
  void crush(int origin_int,
             int nodes_quantity);
  void move(std::shared_ptr<Node> origin,
            std::shared_ptr<Node> destination,
            int nodes_quantity,
            std::string mode="after");
  void setRandom(const std::shared_ptr<Node>& start,
                 int nodes_quantity,
                 int direction=-1);
};

#endif //KANACRUSH_SRC_1MODEL_BOARD_LINKED_LIST_H_
