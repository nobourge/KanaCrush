//
// Created by noe on 02.08.22.
//

#include "Linked_list.h"

Linked_list::Linked_list(const std::string& mode, int value) {
    std::cout << "Linked_list::Linked_list()" << std::endl;
    head_ = nullptr;
    tail_ = nullptr;
  init();
}
//initialize the linked list with cells_containers_size_ Nodes
void Linked_list::init(int size) {
  if (DEBUG_LINKED_LIST) {
    std::cout << "Linked_list::init()" << std::endl;
  }

  for (int i = 0; i < size; i++)
  {
    std::shared_ptr<Node> node = std::make_shared<Node>();
    add(node);

  }
  if (DEBUG_LINKED_LIST) {
//      std::cout << "node value: " << node->getValue() << std::endl;
    debug();
  }
}
Linked_list::~Linked_list() {
    std::cout << "Linked_list::Linked_list()" << std::endl;
    remove_all();

}

void Linked_list::add( const std::shared_ptr<Node>& node) {
    //if the list is empty
    if (head_ == nullptr)
    {
        head_ = node;
        tail_ = head_;
    } else {
      //add the node to the end of the list
      node->set_prev(tail_);
      tail_->set_next(node);
      tail_ = tail_->get_next();
      if (DEBUG_LINKED_LIST) {

//        std::cout << "head next: " << get_head()->get_next()->getValue() << std::endl;
        std::cout << "tail previous: " << get_tail()->get_prev()->getValue() << std::endl;

      }
    }
    if (DEBUG_LINKED_LIST){
      std::cout << "head: " << get_head()->getValue() << std::endl;
      std::cout << "tail: " << get_tail()->getValue() << std::endl;
    }

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
void Linked_list::set_next(const std::shared_ptr<Node>& node) {
    std::cout << "Linked_list::set_next(Cell *cell)" << std::endl;
    if (head_ == nullptr) {
        std::cout << "Linked_list::set_next(Cell *cell) - list is empty" << std::endl;
    } else {
        tail_->set_next(node);
        node->set_prev(tail_);
        tail_ = node;
    }
}
void Linked_list::set_prev(const std::shared_ptr<Node>& node) {
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
  if (DEBUG_LINKED_LIST) {
    std::cout << "Linked_list::get_head()" << std::endl;
  }
    return head_;

}
std::shared_ptr<Node> Linked_list::get_tail() {
  if (DEBUG_LINKED_LIST) {
    std::cout << "Linked_list::get_tail()" << std::endl;
  }
    return tail_;

}
void Linked_list::set_head(std::shared_ptr<Node> node) {
  if (DEBUG_LINKED_LIST) {
    std::cout << "Linked_list::set_head(Cell *cell)" << std::endl;
    }
    head_ = node;

}

void Linked_list::set_tail(std::shared_ptr<Node> node) {
    if (DEBUG_LINKED_LIST) {
        std::cout << "Linked_list::set_tail(Cell *cell)" << std::endl;
    }
    tail_ = node;


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
    if (DEBUG_LINKED_LIST) {
      std::cout << "Linked_list::begin() - iterator_: " << iterator_->getValue() << std::endl;
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
    return iterator_ == head_;

}
std::shared_ptr<Node> Linked_list::get_iterator() {
  if (DEBUG) {
    std::cout << "Linked_list::get_iterator()" << std::endl;
  }
    return iterator_;

}
void Linked_list::debug() {
  print();
  std::cout << "head: " << get_head()->getValue() << std::endl;
  std::cout << "head next: " << get_head()->get_next()->getValue() << std::endl;
  std::cout << "tail previous: " << get_tail()->get_prev()->getValue() << std::endl;
  std::cout << "tail: " << get_tail()->getValue() << std::endl;
}
void Linked_list::print() {
  iterator_ = head_;
  for (int i = 0; i < size_; i++) {
    std::cout << iterator_->getValue() << " "; //@
    iterator_ = iterator_->get_next();
  }
    std::cout << std::endl;

}

//nodes set values incrementing by 1
void Linked_list::set_values(const std::string& mode
                             , int head
                             , int tail
                             ) {
    std::cout << "Linked_list::set_values()" << std::endl;
    if (mode == "increment"){
      iterator_ = head_;
      for (int i = 0; i < size_; i++) {
        iterator_->setValue(head++);//*
        iterator_ = iterator_->get_next();
      }
    }
    else if (mode == "decrement"){
      iterator_ = tail_;
      for (int i = 0; i < size_; i++) {
        iterator_->setValue(tail--);//*
        iterator_ = iterator_->get_prev();
      }
    }
    else if (mode == "equal"){
      iterator_ = head_;
      for (int i = 0; i < size_; i++) {
        iterator_->setValue(head);//*
        iterator_ = iterator_->get_next();
      }
    }
    else {
      std::cout << "Linked_list::set_values() - wrong mode" << std::endl;
    }
    if (DEBUG) {
        std::cout << "Linked_list::set_values() - iterator_: " << iterator_->getValue() << std::endl;
      debug();
    }


}

//move node(s) from origin to destination
void Linked_list::move(std::shared_ptr<Node> origin,
                       std::shared_ptr<Node> destination,
                       int nodes_quantity,
                       std::string mode) {
    std::cout << "Linked_list::move()" << std::endl;
    if (origin == destination) {
        std::cout << "Linked_list::move() - origin == destination" << std::endl;
    } else {

        std::shared_ptr<Node> temp;
        if (DEBUG_CRUSH) {
            std::cout << "Linked_list::move() - origin: " << origin->getValue() << std::endl;
            std::cout << "Linked_list::move() - destination: " << destination->getValue() << std::endl;
            std::cout << "Linked_list::move() - nodes_quantity: " << nodes_quantity << std::endl;
        }
        if (mode == "after") {
            std::cout << "Linked_list::move() - mode == after" << std::endl;
          if (nodes_quantity == 1) {
            temp = origin;
          }
          
          else if (1 < nodes_quantity) {
            temp = origin->get_next();
            for (int i = 0; i < nodes_quantity-2; i++) {
              temp = temp->get_next();
            }
          }
          else {
            std::cout << "Linked_list::move() - nodes_quantity < 1" << std::endl;
            throw std::invalid_argument("nodes_quantity < 1");
          }

          if (DEBUG_CRUSH) {
            std::cout << "Linked_list::move() - destination->get_next(): " << destination->get_next() << std::endl;
 }

          if (destination != tail_)
          {
            if (DEBUG_CRUSH) {
              std::cout << "Linked_list::move() " << std::endl;
              std::cout << "destination == tail" << std::endl;
              std::cout << "destination->get_next()->getValue(): " <<             destination->get_next()->getValue() << std::endl;
              std::cout << "destination->get_next()->get_prev()->getValue(): " << destination->get_next()->get_prev()->getValue() << std::endl;
              std::cout << "destination->get_next()->set_prev(temp): " <<                     destination->get_next()->getValue() << std::endl;
              std::cout << "destination->get_next()->get_prev()->getValue(): " << destination->get_next()->get_prev()->getValue() << std::endl;
              std::cout << "destination->get_next(): " <<                                     destination->get_next() << std::endl;
              std::cout << "destination->get_next->getValue(): " <<             destination->get_next()->getValue() << std::endl;
            }
            destination->get_next()->set_prev(temp);
          }
          else {
            tail_ = temp;
          }
          if (origin != head_)
          {
            temp->get_next()->set_prev(origin->get_prev());

            origin->get_prev()->set_next(temp->get_next());
          }
          else
          {
            head_ = temp->get_next();
          }
          if (temp != tail_)
          {
            temp->set_next(destination->get_next());
          }
          destination->set_next(origin);
          origin->set_prev(destination);
        }
        else if (mode == "before") {
            std::cout << "Linked_list::move() - mode == before" << std::endl;
//            destination->get_prev()->set_next(origin->get_next());
//            origin->get_next()->set_prev(destination->get_prev());
//            destination->set_prev(origin);
//            origin->set_next(destination);
        }
    }
    print();
}

//get node by index
std::shared_ptr<Node> Linked_list::get_node(int index) {
    std::cout << "Linked_list::get_node()" << std::endl;
    if (index < 0 || index >= size_) {
        std::cout << "Linked_list::get_node() - index < 0 || index >= size_" << std::endl;
        throw std::invalid_argument("index < 0 || index >= size_");
    }
    std::shared_ptr<Node> temp = head_;
    for (int i = 0; i < index; i++) {
        temp = temp->get_next();
    }
    return temp;
}

//crush
void Linked_list::crush(std::vector<std::array<int, 3>> crush_vector) {
    std::cout << "Linked_list::crush()" << std::endl;
    for (int i = crush_vector.size(); 0 < i ; i--) {
        std::shared_ptr<Node> origin = get_node(crush_vector[i].at(0));
        int nodes_quantity = crush_vector[i].at(1);
      move(origin,
           tail_,
           nodes_quantity
      );
      setRandom(tail_,
                nodes_quantity);
    }
}

//node(s) set random from origin to destination
void Linked_list::setRandom(const std::shared_ptr<Node>& start,
                             int nodes_quantity,
                            int direction
                            )
{
    std::cout << "Linked_list::set_random()" << std::endl;
    if (direction == 1) {
        std::cout << "Linked_list::set_random() - direction_ == 1" << std::endl;
        std::shared_ptr<Node> temp = start;
        for (int i = 0; i < nodes_quantity; i++) {
            temp->setRandom();//*
            temp = temp->get_next();
        }
    } else if (direction == -1) {
        std::cout << "Linked_list::set_random() - direction_ == -1" << std::endl;
        std::shared_ptr<Node> temp = start;
        for (int i = 0; i < nodes_quantity; i++) {
            temp->setRandom();//*
            temp = temp->get_prev();
        }
    } else {
        std::cout << "Linked_list::set_random() - direction_ != 1 || -1" << std::endl;
        throw std::invalid_argument("direction_ != 1 || -1");
    }
    if (DEBUG_LINKED_LIST) {
        print();
    }
}
int Linked_list::get_size() const {
    return size_;
}
