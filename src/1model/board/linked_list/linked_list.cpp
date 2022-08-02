//
// Created by noe on 02.08.22.
//

#include "linked_list.h"
#include "src/1model/board/linked_list/node/Node.h"
linked_list::linked_list() {
    std::cout << "linked_list::linked_list()" << std::endl;
    head_ = nullptr;
    tail_ = nullptr;

}
////initialize the linked list with cells_container_size Nodes
//void linked_list::init() {
//    std::cout << "linked_list::init()" << std::endl;
//    //create a new node
//    std::shared_ptr<Node> node = std::make_shared<Node>();
//
//}

linked_list::~linked_list() {
    std::cout << "linked_list::~linked_list()" << std::endl;
    remove_all();

}
void linked_list::add(Node *node) {
    std::cout << "linked_list::add(Cell *cell)" << std::endl;
    if (head_ == nullptr) {
        head_ = std::make_shared<Node>(node);
        tail_ = head_;
    } else {
        tail_->set_next(node);
        cell->set_prev(tail_);
        tail_ = cell;
    }

}
void linked_list::remove(Cell *cell) {
    std::cout << "linked_list::remove(Cell *cell)" << std::endl;
    if (head_ == nullptr) {
        std::cout << "linked_list::remove(Cell *cell) - list is empty" << std::endl;
    } else {
        if (head_ == cell) {
            head_ = head_->get_next();
            head_->set_prev(nullptr);
        } else if (tail_ == cell) {
            tail_ = tail_->get_prev();
            tail_->set_next(nullptr);
        } else {
            cell->get_prev()->set_next(cell->get_next());
            cell->get_next()->set_prev(cell->get_prev());
        }
    }


}
void linked_list::set_next(Cell *cell) {
    std::cout << "linked_list::set_next(Cell *cell)" << std::endl;
    if (head_ == nullptr) {
        std::cout << "linked_list::set_next(Cell *cell) - list is empty" << std::endl;
    } else {
        tail_->set_next(cell);
        cell->set_prev(tail_);
        tail_ = cell;
    }


}
void linked_list::set_prev(Cell *cell) {
    std::cout << "linked_list::set_prev(Cell *cell)" << std::endl;
    if (head_ == nullptr) {
        std::cout << "linked_list::set_prev(Cell *cell) - list is empty" << std::endl;
    } else {
        head_->set_prev(cell);
        cell->set_next(head_);
        head_ = cell;
    }

}
std::shared_ptr<Cell> linked_list::get_head() {
    std::cout << "linked_list::get_head()" << std::endl;
    return head_;

}
std::shared_ptr<Cell> linked_list::get_tail() {
    std::cout << "linked_list::get_tail()" << std::endl;
    return tail_;

}
void linked_list::set_head(Cell *cell) {
    std::cout << "linked_list::set_head(Cell *cell)" << std::endl;
    head_ = std::make_shared<Cell>(cell);


}
void linked_list::set_tail(Cell *cell) {
    std::cout << "linked_list::set_tail(Cell *cell)" << std::endl;
    tail_ = std::make_shared<Cell>(cell);


}
void linked_list::set_size(int size) {
    std::cout << "linked_list::set_size(int size)" << std::endl;
    size_ = size;


}
Node *linked_list::get_next() {
    std::cout << "linked_list::get_next()" << std::endl;
    return head_->get_next();

}



