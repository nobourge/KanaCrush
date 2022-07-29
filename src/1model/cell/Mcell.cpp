//
// Created by bourg on 20-12-21.
//
#include "Mcell.h"
#include <random>

// Cell initialization with random value
Cell::Cell() {
  // value init random
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 6);
    value = dis(gen);
    // type init random
    std::uniform_int_distribution<> disType(1, 6);
    type = disType(gen);

}

Cell::Cell(int value) {
    this->value = value;
}

int Cell::getValue() const {
    return value;
}

void Cell::setValue(int value) {
    this->value = value;
}
int Cell::getType() const {
  return type;
}
void Cell::setType(int type) {
  this->type = type;

}
Cell::Cell(int value, int type) {
    this->value = value;
    this->type = type;

}
