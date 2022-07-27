//
// Created by bourg on 20-12-21.
//
#include "Mcell.h"

Cell::Cell(int value) {
    this->value = value;
}

int Cell::getValue() {
    return value;
}

void Cell::setValue(int value) {
    this->value = value;
}
