//
// Created by noe on 02.08.22.
//

#include "Node.h"

#include <utility>
Node::Node(Node *cell) {
    std::cout << "Node::Node(std::shared_ptr<Cell> cell)" << std::endl;
    cell_ = std::move(cell);
    next_ = nullptr;
    prev_ = nullptr;

}
Node::~Node() {
    std::cout << "Node::~Node()" << std::endl;
    next_ = nullptr;
    prev_ = nullptr;


}
void Node::set_next(std::shared_ptr<Node> node) {
    std::cout << "Node::set_next(std::shared_ptr<Node> node)" << std::endl;
    next_ = std::move(node);


}
void Node::set_prev(std::shared_ptr<Node> node) {
    std::cout << "Node::set_prev(std::shared_ptr<Node> node)" << std::endl;
    prev_ = std::move(node);

}
std::shared_ptr<Node> Node::get_next() {
    std::cout << "Node::get_next()" << std::endl;
    return next_

}
