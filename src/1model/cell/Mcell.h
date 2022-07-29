//
// Created by bourg on 20-12-21.
//

#ifndef KANACRUSH_CELL_H
#define KANACRUSH_CELL_H

#include "srcCommon.h"

class Cell {
  int value;
  int type;

 public:
    Cell();
    explicit Cell(int value);
//    Cell(int type);
    Cell(int value, int type);

    int getValue() const;
    void setValue(int value);
    int getType() const;
    void setType(int type);

};
#endif //KANACRUSH_CELL_H
