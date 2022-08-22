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
  std::array<std::vector<std::array<int, 3>>, cells_containers_container_size_> crushable_cells_;
  bool crushable_ = false;

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
    bool crush();
    //swap
    void swap(int row1, int col1, int row2, int col2);

    // terminal print
    void print();

//  void cellsValueSetRandom();
  void setCellsValueDistribution(const std::string& value_distribution="random");
  void setCellsContainersHeadOrientation(const std::string& cells_containers_head_orientation="down");
  std::basic_string<char> getCellsContainersHeadOrientation();

  void replaceCellValue(int row
                        , int column);
  void rain(int row
            , int column);
  void setDataStructure(const std::string &data_structure="linked_list");
  void setCells(const std::string& mode="random",
                int value=1);

  void crushColumn(int column, std::vector<std::array<int, 3>> &origins_and_nodes_quantities);
  void crushable_cells_Print();
  void crushableCellsUpdate(int column
                            , int origin=-1 //-1 close column current serie or do nothing
                                );
  void crushableCellsAddNewSerie(int column
                                 , int origin
                                 );
  void searchCrushableCells();
  std::array<std::vector<std::array<int, 3>>, 9> getCrushableCells();
  void emptyCrushableCellsVectors();
  bool isCrushable() const;
  bool crushWhilePossible();
//  void crushWhilePossible();

};

#endif //KANACRUSH_MBOARD_H
