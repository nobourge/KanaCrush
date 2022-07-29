//
// Created by bourg on 28-12-21.
//

#ifndef KANACRUSH_MBOARD_H
#define KANACRUSH_MBOARD_H

#include "../cell/Mcell.h"
//#include "candy/candy.h"

class Board {
  static const int rows_quantity = 9;
  static const int columns_quantity = 9;
//  static const int toCrush = 3;

//  std::vector<std::vector<Cell>> cells = {};
  std::array<std::array<Cell, columns_quantity>, rows_quantity> cells = {};

  //array of array of cells

//    std::shared_ptr<std::array<std::array<Cell, columns_quantity>, rows_quantity>> cells;

  std::string state;

 public:
  Board();

  bool crushFrom(int x, int y);

  // cells init random
    static void cellsInitRandom();

  //get cell value
  int getCellValue(int row, int column) const;
  //set cell value
  void setCellValue(int row, int column, int value);
  //get cell type
  int getCellType(int row, int column) const;
  //set cell type
  void setCellType(int row, int column, int type);

  //new game
    void newGame();
    //crush
    void crush();
    //swap
    void swap(int row1, int col1, int row2, int col2);

    // terminal print
    void printBoard();

//  void cellsValueSetRandom();
};

#endif //KANACRUSH_MBOARD_H
