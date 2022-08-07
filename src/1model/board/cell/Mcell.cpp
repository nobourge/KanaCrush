//
// Created by bourg on 20-12-21.
//
#include "Mcell.h"
#include <random>

// Cell initialization with random value
Cell::Cell() {
  setRandom();
}

Cell::Cell(int value) {
    value_ = value;
}

int Cell::getValue() const {
    return value_;
}

void Cell::setValue(int value) {
    value_ = value;
}
int Cell::getType() const {
  return type_;
}
void Cell::setType(int type) {
  type_ = type;

}
Cell::Cell(int value, int type) {
    value_ = value;
    type_ = type;

}
void Cell::setRandom() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 6);
    value_ = dis(gen);
    std::uniform_int_distribution<> disType(1, 6);
    type_ = disType(gen);

}
