#include "Node.h"

//#include <utility>
#include "constants.h"

Node::Node()
//Node::Node():private Cell()
{
  if (DEBUG_NODE){
    std::cout <<
              "Node::Node()" <<
              std::endl;
  }

//    cell_ = std::make_shared<Cell>();

    setRandom();
    next_ = nullptr;
    prev_ = nullptr;
  if (DEBUG_NODE){
    std::cout << "next_ : " << next_ << std::endl;
    std::cout << "prev_ : " << prev_ << std::endl;
    std::cout << "value : " << getValue() << std::endl;
//    std::cout << "value : " << cell_->getValue() << std::endl;
//    std::cout << value_ << std::endl;
  }


}
Node::~Node() {
    std::cout << "Node::~Node()" << std::endl;
    next_ = nullptr;
    prev_ = nullptr;


}
void Node::set_next(std::shared_ptr<Node> node) {
  if (DEBUG) {
    std::cout << "Node::set_next(std::shared_ptr<Node> node)" << std::endl;
  }
  next_ = std::move(node);


}
void Node::set_prev(std::shared_ptr<Node> node) {
  if (DEBUG) {
    std::cout << "Node::set_prev(std::shared_ptr<Node> node)" << std::endl;
  }
  prev_ = std::move(node);

}
std::shared_ptr<Node> Node::get_next() {
    if (DEBUG) {
        std::cout << "Node::get_next()" << std::endl;
    }
    return next_;

}

std::shared_ptr<Node> Node::get_prev() {
    if (DEBUG) {
        std::cout << "Node::get_prev()" << std::endl;
    }
    return prev_;

}
std::shared_ptr<Cell> Node::get_cell() {
    if (DEBUG) {
        std::cout << "Node::get_cell()" << std::endl;
    }
    return static_cast<const std::shared_ptr<Cell> &>(cell_);

}

//