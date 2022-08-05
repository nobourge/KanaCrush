//
// Created by bourg on 20-12-21.
//

#ifndef KANACRUSH_CELL_H
#define KANACRUSH_CELL_H

#include "srcCommon.h"

class Cell {
  int value_;
  int type_;

 public:

    Cell();

    explicit Cell(int value);
//    Cell(int type);
    Cell(int value, int type);
    void setValue(int value);
    int getType() const;
    void setType(int type);

  int getValue() const;
};
#endif //KANACRUSH_CELL_H
