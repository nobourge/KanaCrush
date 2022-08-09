//
// Created by bourg on 28-12-21.
//

#ifndef KANACRUSH_MBOARD_H
#define KANACRUSH_MBOARD_H

#include "src/parameters.h"
#include "src/1model/game/board/linked_list/Linked_list.h"
#include "src/1model/game/board/cell/Mcell.h"


class Board {
  std::string data_structure_;
  //cell_linked_list_array containers size
  static const int cells_containers_size_ = 9;
  //containers container size
  static const int cells_containers_container_size_ = 9;

  //crush
  std::array<std::shared_ptr<Linked_list>, cells_containers_size_> cell_linked_list_array;
  //random access search & comparison
  std::array<std::array<std::shared_ptr<Cell>, cells_containers_container_size_>, cells_containers_size_> cell_array_array;
  std::string cells_value_distribution_;
  std::string cells_containers_head_orientation_;
  std::string state_;

 public:
  Board();
  static int get_cells_containers_size() ;
    static int get_cells_containers_container_size() ;
  bool crushFrom(int x, int y);
  void cellsInitRandom();
    void cellsInitValueAscent();

    //get_cells_
    std::shared_ptr<Linked_list> get_cells(int row);

  //new game
    void newGame();
    //crush
    void crush();
    //swap
    void swap(int row1, int col1, int row2, int col2);

    // terminal print
    void print();

//  void cellsValueSetRandom();
  void setCellsValueDistribution(const std::string& value_distribution="random");
  void setCellsContainersHeadOrientation(const std::string& cells_containers_head_orientation="down");
  void deleteCell(int row
                  , int column);
  void addCell(int row
               , int column
               , int value);
  void replaceCellValue(int row
                        , int column);
  void rain(int row
            , int column);
  void setDataStructure(const std::string &data_structure="linked_list");
  void crushColumn(int column
                   , int origin
                   , int nodes_quantity);
  void updateCells(std::string to_update);
  void setCells(const std::string& mode="random"
      , int value=1);
};

#endif //KANACRUSH_MBOARD_H
