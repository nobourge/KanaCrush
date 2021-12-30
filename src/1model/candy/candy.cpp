//
// Created by bourg on 20-12-21.
//

#include "candy.h"

Candy::Candy(int i, int j) {
    type = rand() % 6 + 1;
    row = i;
    col = j;
}

Candy::Candy(int type) {
    this->type = type;
}

void Candy::setType(int type) {
    this->type = type;
}

int Candy::getType() {
    return type;
}

void Candy::setRow(int row) {
    this->row = row;
}

int Candy::getRow() {
    return row;
}

void Candy::setCol(int col) {
    this->col = col;
}

int Candy::getCol() {
    return col;
}