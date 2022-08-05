//
// Created by noe on 02.08.22.
//

#include "Linked_list.h"
#include "src/1model/board/linked_list/node/Node.h"
#include "constants.h"


Linked_list::Linked_list() {
    std::cout << "Linked_list::Linked_list()" << std::endl;
    head_ = nullptr;
    tail_ = nullptr;
  init();

  print();
}
//initialize the linked list with rows_quantity Nodes
void Linked_list::init(int size) {
    std::cout << "Linked_list::init()" << std::endl;
    //create a new node
//    std::shared_ptr<Node> node = std::make_shared<Node>();

  for (int i = 0; i < size; i++)
  {
    std::shared_ptr<Node> node = std::make_shared<Node>();
    std::cout << "node value: " << node->get_cell()->getValue() << std::endl;
    //add the node to the linked list
    add(node);

  }

  if (DEBUG) {
    std::cout << "Linked_list::init()" << std::endl;
    std::cout << "head: " << get_head()->get_cell()->getValue() << std::endl;
    std::cout << "head next: " << get_head()->get_next()->get_cell()->getValue() << std::endl;
    std::cout << "tail previous: " << get_tail()->get_prev()->get_cell()->getValue() << std::endl;
    std::cout << "tail: " << get_tail()->get_cell()->getValue() << std::endl;
  }

  print();
}

Linked_list::~Linked_list() {
    std::cout << "Linked_list::Linked_list()" << std::endl;
    remove_all();

}

void Linked_list::add( std::shared_ptr<Node> node) {
//void Linked_list::add(Node *node) {
//    std::cout << "Linked_list::add(Node *node)" << std::endl;
    //if the list is empty
    if (head_ == nullptr)
    {
        head_ = node;
//        head_ = std::make_shared<Node>(*node);
        tail_ = head_;
    } else {
        //add the node to the end of the list
        node->set_prev(tail_);
        tail_->set_next(node);
        tail_ = tail_->get_next();
      std::cout << "head: " << get_head()->get_cell()->getValue() << std::endl;

      std::cout << "head next: " << get_head()->get_next()->get_cell()->getValue() << std::endl;
      std::cout << "tail: " << get_tail()->get_cell()->getValue() << std::endl;

      std::cout << "tail previous: " << get_tail()->get_prev()->get_cell()->getValue() << std::endl;


    }
    std::cout << "head: " << get_head()->get_cell()->getValue() << std::endl;
    std::cout << "tail: " << get_tail()->get_cell()->getValue() << std::endl;
    size_++;
}


void Linked_list::remove(std::shared_ptr<Node> node) {
    std::cout << "Linked_list::remove(Cell *cell)" << std::endl;
    if (head_ == nullptr) {
        std::cout << "Linked_list::remove(Cell *cell) - list is empty" << std::endl;
    }
    else {
        if (head_ == node) {
            head_ = head_->get_next();
            head_->set_prev(nullptr);
        } else if (tail_ == node) {
            tail_ = tail_->get_prev();
            tail_->set_next(nullptr);
        } else {
            node->get_prev()->set_next(node->get_next());
            node->get_next()->set_prev(node->get_prev());
        }
    }


}
//remove all nodes from the list
void Linked_list::remove_all() {
    std::cout << "Linked_list::remove_all()" << std::endl;
    if (head_ == nullptr) {
        std::cout << "Linked_list::remove_all() - list is empty" << std::endl;
    } else {
        std::shared_ptr<Node> node = head_;
        while (node != nullptr) {
            head_ = head_->get_next();
            node->set_next(nullptr);
            node->set_prev(nullptr);
            node = head_;
        }
        tail_ = nullptr;
        size_ = 0;
    }
}
void Linked_list::set_next(std::shared_ptr<Node> node) {
    std::cout << "Linked_list::set_next(Cell *cell)" << std::endl;
    if (head_ == nullptr) {
        std::cout << "Linked_list::set_next(Cell *cell) - list is empty" << std::endl;
    } else {
        tail_->set_next(node);
        node->set_prev(tail_);
        tail_ = node;
    }


}

void Linked_list::set_prev(std::shared_ptr<Node> node) {
    std::cout << "Linked_list::set_prev(Cell *cell)" << std::endl;
    if (head_ == nullptr) {
        std::cout << "Linked_list::set_prev(Cell *cell) - list is empty" << std::endl;
    } else {
        head_->set_prev(node);
      node->set_next(head_);
        head_ = node;
    }

}
std::shared_ptr<Node> Linked_list::get_head() {
    std::cout << "Linked_list::get_head()" << std::endl;
    return head_;

}
std::shared_ptr<Node> Linked_list::get_tail() {
    std::cout << "Linked_list::get_tail()" << std::endl;
    return tail_;

}
void Linked_list::set_head(std::shared_ptr<Node> node) {
    std::cout << "Linked_list::set_head(Cell *cell)" << std::endl;
    head_ = node;

}

void Linked_list::set_tail(std::shared_ptr<Node> node) {
    std::cout << "Linked_list::set_tail(Cell *cell)" << std::endl;
    tail_ = node;


}
void Linked_list::set_size(int size) {
    std::cout << "Linked_list::set_size(int size)" << std::endl;
    size_ = size;


}
std::shared_ptr<Node> Linked_list::get_next(std::shared_ptr<Node> node) {
  if (DEBUG) {
    std::cout << "Linked_list::get_next()" << std::endl;
  }
  return node->get_next();

}
std::shared_ptr<Node> Linked_list::get_prev(std::shared_ptr<Node> node) {
  if (DEBUG) {
    std::cout << "Linked_list::get_prev()" << std::endl;
  }
  return node->get_prev();

}

//iterator
void Linked_list::begin() {
//    std::cout << "Linked_list::begin()" << std::endl;
    iterator_ = head_;
    if (DEBUG) {
      std::cout << "Linked_list::begin() - iterator_: " << iterator_->get_cell()->getValue() << std::endl;
    }

}
void Linked_list::end() {
  if (DEBUG) {
    std::cout << "Linked_list::end()" << std::endl;
  }
  iterator_ = tail_;

}
void Linked_list::next() {
//    std::cout << "Linked_list::next()" << std::endl;
    iterator_ = iterator_->get_next();

}
void Linked_list::previous() {
  if (DEBUG) {
    std::cout << "Linked_list::previous()" << std::endl;
  }
    iterator_ = iterator_->get_prev();

}
bool Linked_list::is_end() {
  if (DEBUG) {
    std::cout << "Linked_list::is_end()" << std::endl;
    }
    return iterator_ == tail_;

}
bool Linked_list::is_begin() {
    if (DEBUG) {
        std::cout << "Linked_list::is_begin()" << std::endl;
    }
    std::cout << "Linked_list::is_begin()" << std::endl;
    return iterator_ == head_;

}
std::shared_ptr<Node> Linked_list::get_iterator() {
  if (DEBUG) {
    std::cout << "Linked_list::get_iterator()" << std::endl;
  }
    return iterator_;

}
void Linked_list::print() {

//    std::cout << "Linked_list::print()" << std::endl;
//    begin();
//    while (!is_end()) {
//        std::cout << iterator_->get_cell()->getValue() << " ";
//        next();
//    }

  iterator_ = head_;
  for (int i = 0; i < size_; i++) {
    std::cout << iterator_->get_cell()->getValue() << " ";
    iterator_ = iterator_->get_next();
  }
    std::cout << std::endl;

}
//void Linked_list::set_iterator(Node *node) {
//    std::cout << "Linked_list::set_iterator(Node *node)" << std::endl;
//    iterator_ = node;
//
//}

//nodes set values in values incrementing by 1
void Linked_list::set_values(std::string mode="increment", int head=0, int tail=0) {
    std::cout << "Linked_list::set_values()" << std::endl;
//    begin();
//    while (!is_end()) {
//        if (mode == "increment") {
//            iterator_->get_cell()->setValue(head++);
//        } else if (mode == "decrement") {
//            iterator_->get_cell()->setValue(iterator_->get_cell()->getValue() - 1);
//        }
//        next();
//    }
    iterator_ = head_;
    for (int i = 0; i < size_; i++) {
        iterator_->get_cell()->setValue(head++);
        iterator_ = iterator_->get_next();
    }
    print();
    std::cout << "head: " << get_head()->get_cell()->getValue() << std::endl;
    std::cout << "head next: " << get_head()->get_next()->get_cell()->getValue() << std::endl;
    std::cout << "tail previous: " << get_tail()->get_prev()->get_cell()->getValue() << std::endl;
    std::cout << "tail: " << get_tail()->get_cell()->getValue() << std::endl;

}




