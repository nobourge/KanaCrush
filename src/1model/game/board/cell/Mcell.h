#ifndef KANACRUSH_CELL_H
#define KANACRUSH_CELL_H

#include "srcCommon.h"

class Cell {
 protected:
  int value_;
  int type_;

 public:
    Cell();
    explicit Cell(int value);
    Cell(int value, int type);
    void setValue(int value);
    int getType() const;
    void setType(int type);
    void setRandom();
    void set(int value, int type);

  int getValue() const;
};
#endif //KANACRUSH_CELL_H
