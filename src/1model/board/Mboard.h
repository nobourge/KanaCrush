//
// Created by bourg on 28-12-21.
//

#ifndef KANACRUSH_MBOARD_H
#define KANACRUSH_MBOARD_H

//#include "linked_list/node/cell/li"
//#include "candy/candy.h"
#include "cell/Mcell.h"

class Board {
//cells_ containers size
  static const int rows_quantity = 9;
  //containers container size
  static const int columns_quantity = 9;

// todo https://www.javatpoint.com/difference-between-arraylist-and-linkedlist#:~:text=2)%20Manipulation%20with,required%20in%20memory.
//     std::array<std::linked_list<Cell, columns_quantity>, rows_quantity> cells_;

     //declaration of cells_ container without initialization
        std::array<std::array<std::shared_ptr<Cell>, columns_quantity>, rows_quantity> cells_;

//     std::array<std::array<Cell, columns_quantity>, rows_quantity> cells_;
//     std::shared_ptr<std::array<std::array<Cell, columns_quantity>, rows_quantity>> cells_;
//    static std::shared_ptr<std::array<std::array<Cell, columns_quantity>, rows_quantity>> cells_;

  std::string cells_value_distribution_;
  std::string cells_containers_head_orientation_;
  std::string state_;

 public:
  Board();
  Board(std::string data_structure);//todo

//  explicit Board(const std::string& value_distribution="random");
//  Board(const std::string &value_distribution, const std::string &cells_containers_head_orientation);

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
//    void printBoard();

//  void cellsValueSetRandom();
  void setCellsValueDistribution(const std::string& value_distribution="random");


  void printBoard(const std::string &cells_containers_head_orientation="down");
//  void setCellsContainersHeadOrientation();

  void setCellsContainersHeadOrientation(const std::string& cells_containers_head_orientation);
  void deleteCell(int row, int column);
  void addCell(int row, int column, int value);
  void replaceCellValue(int row, int column);
  void rain(int row, int column);
};

#endif //KANACRUSH_MBOARD_H
