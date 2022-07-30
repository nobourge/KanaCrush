//
// Created by bourg on 28-12-21.
//

#ifndef KANACRUSH_MBOARD_H
#define KANACRUSH_MBOARD_H

#include "../cell/Mcell.h"
//#include "candy/candy.h"

class Board {
  Board(const std::string &value_distribution, const std::string &cells_containers_head_orientation);
//cells_ containers size
  static const int rows_quantity = 9;
  //containers container size
  static const int columns_quantity = 9;
//  static const int toCrush = 3;


  //array of array of cells_

     std::array<std::array<Cell, columns_quantity>, rows_quantity> cells_;
//     std::shared_ptr<std::array<std::array<Cell, columns_quantity>, rows_quantity>> cells_;
//    static std::shared_ptr<std::array<std::array<Cell, columns_quantity>, rows_quantity>> cells_;

  std::string cells_value_distribution_;
  std::string cells_containers_head_orientation_;
  std::string state_;

 public:
  Board();

  explicit Board(const std::string& value_distribution);

  bool crushFrom(int x, int y);

  // cells_ init random
  void cellsInitRandom();
    void cellsInitValueAscent();

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
  void printBoard(const std::string &cells_containers_head_orientation);
  void setCellsContainersHeadOrientation();
  void setCellsValueDistribution();
  void setCellsContainersHeadOrientation(std::string cells_containers_head_orientation);
};

#endif //KANACRUSH_MBOARD_H
