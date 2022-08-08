//
// Created by bourg on 28-12-21.
//

#ifndef KANACRUSH_MBOARD_H
#define KANACRUSH_MBOARD_H

#include "src/parameters.h"
#include "src/1model/MVCinclude.h"

#include "src/1model/game/board/linked_list/Linked_list.h"
#include "src/1model/game/board/cell/Mcell.h"


class Board {
  std::string data_structure_;
//cell_linked_list_array containers size
  static const int cells_containers_size = 9;
  //containers container size
  static const int cells_containers_container_size = 9;

//  https://www.javatpoint.com/difference-between-arraylist-and-linkedlist#:~:text=2)%20Manipulation%20with,required%20in%20memory.

// array of linked lists
// to crush
    std::array<std::shared_ptr<Linked_list>, cells_containers_size> cell_linked_list_array;

     //declaration of
     // array of array
     // without initialization
     // to random access search & comparison
      std::array<std::array<std::shared_ptr<Cell>, cells_containers_container_size>, cells_containers_size> cell_array_array;


  std::string cells_value_distribution_;
  std::string cells_containers_head_orientation_;
  std::string state_;

 public:
  Board();
//  Board(std::string data_structure="Linked_list");

//  explicit Board(const std::string& value_distribution="random");
//  Board(const std::string &value_distribution, const std::string &cells_containers_head_orientation);

  bool crushFrom(int x, int y);

  // cell_linked_list_array init
    void init(const std::string& data_structure="linked_list",
              const std::string& value_distribution="ascent",
              const std::string& cells_containers_head_orientation="down");
  void cellsInitRandom();
    void cellsInitValueAscent();

    //get_cells_
    std::shared_ptr<Linked_list> get_cells(int row);

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
  void setCellsValueDistribution(const std::string& value_distribution="random");


//  void printBoard(const std::string &cells_containers_head_orientation="down");
//  void setCellsContainersHeadOrientation();

  void setCellsContainersHeadOrientation(const std::string& cells_containers_head_orientation="down");
  void deleteCell(int row, int column);
  void addCell(int row, int column, int value);
  void replaceCellValue(int row, int column);
  void rain(int row, int column);
//  void printBoard(const std::string &data_structure="Linked_list", const std::string &cells_containers_head_orientation="down");
  void cellsInitValueAscent(std::string data_structure);
  void setDataStructure(const std::string &data_structure="linked_list");
  void setCells();
//  void crushColumn(int column, int origin, int destination, int nodes_quantity);
  void crushColumn(int column, int origin, int nodes_quantity);
  void updateCells();
};

#endif //KANACRUSH_MBOARD_H
