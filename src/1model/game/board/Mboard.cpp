//
// Created by bourg on 28-12-21.
//

#include "Mboard.h"

void Board::newGame() {
//    int types_quantity = 6;
//    for (auto &c: cell_linked_list_array) for (auto &x: c) x = squareType[(rand() % types_quantity - 1) + 1] ;
//    currentGameState = Play;
}

//squareType Board::getSquareType(int row, int column) const {
//    return cell_linked_list_array.at(row).at(column);
//}
//gameState Board::getGameState() const {
//    return currentGameState;
//}

void Board::swap(int row1, int col1, int row2, int col2){
//    squareType candy1square_type = getSquareType(row1, col1);
//
//  int tmp = cell_linked_list_array.at(row1).at(col1).getValue();
//  cell_linked_list_array.at(row1).at(col1).setValue(cell_linked_list_array.at(row2).at(col2).getValue());
//
//    cell_linked_list_array.at(row2).at(col2).setValue(tmp);

//    int tmp = cell_linked_list_array->at(row1).at(col1).getValue();
//  cell_linked_list_array->at(row1).at(col1).setValue(cell_linked_list_array->at(row2).at(col2).getValue());
//
//    cell_linked_list_array->at(row2).at(col2).setValue(tmp);
}

//
//void Board::swap(Candy *candy1, Candy *candy2) {
//    int type = candy1->getType();
//    candy1->setCandy(candy2->getType());
//    candy2->setCandy(type);
//}

    ///
    /// \param square1
    /// \param origin_cardinal
    /// \param destination_column
    /// \param destination_row
    /// \return
bool Board::crushFrom(int x, int y)
{
//    std::optional< std::vector< std::pair<int,int> > >
//        search_crush(squareType origin_square_type,
//
//                     std::pair <int,int> origin_cardinal,
//
//                     int destination_column,
//
//                     int destination_row)
////                     {
//    {
//        std::optional<vector<std::pair<int,int>>> cardinal_and_crush_pair_vec;
//        pair<int,int> N_E_potential_crush = make_pair(0, 0);
//
//        for (int i = 0; i < CARDINALS_LEN; i++)
//        {
//            const int cardinal_direction_int = i;
//            pair<int, int> cardinal;
//            cardinal = CARDINALS_PAIR_ARRAY[i];
//            if (cardinal != origin_cardinal)
//            {
//                int same_type_quantity = 0;
//                while (getSquareType(destination_row + cardinal.first,
//                                     destination_column + cardinal.second)
//                       == origin_square_type)
//                {
//                    same_type_quantity++;
//                }
//                const int axis_first_direction = cardinal_direction_int % 2;
//                int axis_first_direction_same_type_quantity = std::get<axis_first_direction>(N_E_potential_crush);
//
//                if (toCrush <= (axis_first_direction_same_type_quantity + same_type_quantity))
//                {
//                    cardinal_and_crush_pair_vec.push_back(std::make_pair(cardinal_direction_int, same_type_quantity));
//                    //cardinal_and_crush_pair_vec.emplace_back(i,same_type_quantity);
//
//                    if(0 < axis_first_direction_same_type_quantity)
//                    {
//                        cardinal_and_crush_pair_vec.push_back(std::make_pair(axis_first_direction, axis_first_direction_same_type_quantity));
//                    }
//                }
//
//                else
//                {
//                    //not enough same_type_quantity to crush but
//                    if (cardinal_direction_int < 2)
//                    {
//                        //memorize for same axis other cardinal direction
//                        std::get<cardinal_direction_int>(N_E_potential_crush) = same_type_quantity;
//                    }
//                }
//            }
//        }
//        //return b ? std::optional<std::string>{"Godzilla"} : std::nullopt;
//        if (cardinal_and_crush_pair_vec){
//            return cardinal_and_crush_pair_vec;
//        }
//        return {};
//    }
      return false;
}
//
//int Board::getCellValue(int row, int column) const {
//    return cell_linked_list_array.at(row).at(column).getValue();
//}
//void Board::setCellValue(int row, int column, int value) {
//    cell_linked_list_array.at(row).at(column).setValue(value);
//}
void Board::print()
{

    std::cout << "Board::print()" << std::endl;
    std::cout << "cells_containers_head_orientation: " << cells_containers_head_orientation_ << std::endl;


    if (data_structure_ == "linked_list")
    {
      if (DEBUG||DEBUG_CRUSH)
      {
        for (auto &linked_list : cell_linked_list_array) {
          linked_list->print();
        }
        for (int i = 0; i < cells_containers_container_size_ ; i++) {
          std::shared_ptr<Node> temp_node = get_cells(i)->get_head();

          for (int j = 0; j < cells_containers_size_; j++) {
            std::cout << "temp_node ->getValue() : " << temp_node->get_cell()->getValue() << std::endl;
          }
        }
      }

      if (cells_containers_head_orientation_ == "left")
      {
        for (auto &linked_list: cell_linked_list_array)
        {
            linked_list->print();
        }
      }

      else if (cells_containers_head_orientation_ == "down")
      {
//        std::cout << "printing cells_containers_head_orientation: " << cells_containers_head_orientation_ << std::endl;
//        std::cout << "cells size: " << cell_linked_list_array.size() << std::endl;
        for (int i = 0; i < cell_linked_list_array.size(); i++)
        {
          for (auto &linked_list : cell_linked_list_array)
          {
            if (DEBUG || DEBUG_BOARD)
            {
              linked_list->print();
              std::cout << "head: " << linked_list->get_head()->get_cell()->getValue() << std::endl;
              std::cout << "head next: " << linked_list->get_head()->get_next()->get_cell()->getValue() << std::endl;
              std::cout << "tail previous: " << linked_list->get_tail()->get_prev()->get_cell()->getValue() << std::endl;
              std::cout << "tail: " << linked_list->get_tail()->get_cell()->getValue() << std::endl;
            }
            if (i == 0)
            {
              linked_list->end();
            }
            else
            {
              linked_list->previous();
            }
            std::cout << linked_list->get_iterator()->get_cell()->getValue() << " ";

          }
          std::cout << std::endl;
        }
      }

    }
//    else if (data_structure == "array")
//    {
//      if (cells_containers_head_orientation == "left")
//      {
//        for (auto &c: cell_linked_list_array)
//        {
//          for (auto &x: c)
//          {
//            std::cout << x.getValue() << " ";
//          }
//          std::cout << std::endl;
//        }
//      }
//      else if (cells_containers_head_orientation == "right")
//      {
//        //print containers in reverse order
//        for (auto it = cell_linked_list_array.rbegin(); it != cell_linked_list_array.rend(); ++it)
//        {
//          for (auto &x: *it)
//          {
//            std::cout << x.getValue() << " ";
//          }
//          std::cout << std::endl;
//        }
//      }
//      else if (cells_containers_head_orientation == "up") {
//        //print containers heads on first line
//        for (int i = 0; i < cell_linked_list_array.size(); i++)
//        {
//          for (auto &c : cell_linked_list_array) {
//            std::cout << c.at(i).getValue() << " ";
//          }
//          std::cout << std::endl;
//        }
//      }
//
//      else if (cells_containers_head_orientation == "down")
//      {
//        //print containers heads on last line
//        for ( int i = cell_linked_list_array.size() - 1; i >= 0; i--)
//        {
//          for (auto &c : cell_linked_list_array) {
//            std::cout << c.at(i).getValue() << " ";
//          }
//          std::cout << std::endl;
//
//        }
//      }
//      else
//      {
//        std::cout << "Board::print() - invalid cells_containers_head_orientation" << std::endl;
//      }
//    }

}

//board linked list functions
//void Board::addNode(int row, int column, int value)
//{
//    Cell *cell = new Cell(row, column, value);
//    cell_linked_list_array.push_back(cell);
//}


void Board::cellsInitRandom() {
  //init random cell_linked_list_array
    for (int i = 0; i < cells_containers_size_; i++) {
        for (int j = 0; j < cells_containers_container_size_; j++) {
//          cell_linked_list_array.emplace_back(std::make_shared<Cell>());
//            cell_linked_list_array.push_back() std::make_shared<Cell>(rand() % (5 + 1), rand() % (5 + 1));
//            cell_linked_list_array[i][j] = std::make_shared<Cell>(rand() % (5 + 1), rand() % (5 + 1));
        }
    }
}

void Board::cellsInitValueAscent() {

  std::cout << "Board::cellsInitValueAscent()" << std::endl;
  std::cout << "cell_linked_list_array size: " << cell_linked_list_array.size() << std::endl;
//cell_linked_list_array set ascending value
int value = 1;
      if (data_structure_ == "linked_list")
      {
//        setCells();
        for (auto &linked_list: cell_linked_list_array) {
          linked_list->set_values("increment", value,0);
          value += cell_linked_list_array.size();

        }
      }

      else if (data_structure_ == "array")
      {
        for (int j = 0; j < cells_containers_container_size_; j++) {
//                cell_linked_list_array.at(i).at(j).setValue(i * cells_containers_container_size_ + j);
        }
      }
}

//set cells_container_head_orientation: left, right, up, down set
//void Board::setCellsValueDistribution() {
void Board::setCellsValueDistribution(const std::string& value_distribution) {

  if (PARAMETRIZED)
    {
    cells_value_distribution_ = CELLS_VALUES_DISTRIBUTION;
    }


  else if (value_distribution == "input"){
    std::cout << "please insert cells_value_distribution_ (random, ascent)" << std::endl;

    std::cin >> cells_value_distribution_;
  }

  else {
    cells_value_distribution_ = value_distribution;
  }

  if (cells_value_distribution_ == "random") {
    std::cout << "Board::Board(std::string value_distribution) random" << std::endl;
    cellsInitRandom();
  } else if (cells_value_distribution_ == "ascent") {
    std::cout << "Board::Board(std::string value_distribution) ascent" << std::endl;
    cellsInitValueAscent();
  } else {
    std::cout << "Board::Board(std::string value_distribution) : unknown value_distribution, cell_linked_list_array initialization: random" << std::endl;
//    cellsInitValue();
  }
}

void Board::setCellsContainersHeadOrientation(const std::string& cells_containers_head_orientation) {
//void Board::setCellsContainersHeadOrientation() {
//  std::cout << "Board::setCellsContainersHeadOrientation() - cells_containers_head_orientation_: " << cells_containers_head_orientation_ << std::endl;

  if (PARAMETRIZED){
    cells_containers_head_orientation_ = CELLS_CONTAINERS_HEAD_ORIENTATION;

    if (DEBUG)
      std::cout << "PARAMETRIZED Board::setCellsContainersHeadOrientation() - cells_containers_head_orientation_: " << cells_containers_head_orientation_ << std::endl;
  }

  else if (cells_containers_head_orientation == "input") {
    std::cout << "Board::setCellsContainersHeadOrientation()" << std::endl;
    std::cout << "please insertCellsContainersHeadOrientation" << std::endl;
    std::cout << "left, right, up, down" << std::endl;

    std::cin >> cells_containers_head_orientation_;
  }

  else {
    cells_containers_head_orientation_ = cells_containers_head_orientation;
  }
}

Board::Board() {
    std::cout << "Board::Board()" << std::endl;

  setDataStructure("linked_list");

    setCells();

  setCells("equal",1);
//  setCellsValueDistribution("ascent");
  setCellsContainersHeadOrientation("down");
//  rain(0,0);
  print();
//  updateCells("canvas");

}

//find groups of minimum 3 cells
// with same value
// in same row or column
// adjacents to each other


//
////crush
//void Board::crush(std::vector<std::pair<int, int>> crushable_cells_vec) {
//    for (auto &crushable_cell : crushable_cells_vec) {
//        deleteCell(crushable_cell.first, crushable_cell.second);
//    }
//}
//
//cell replace value with next cell value
void Board::replaceCellValue(int row, int column) {
//    cell_linked_list_array.at(row).at(column).setValue(cell_linked_list_array.at(row).at(column+1).getValue());
}

//cell rain
void Board::rain(int row, int column) {
    for (int i = 0; i < cells_containers_container_size_-column-1; i++) {
//        cell_linked_list_array.at(row).at(i).setValue(cell_linked_list_array.at(row).at(i+1).getValue());
      replaceCellValue(row, i);
      print();
    }
}

//set data_structure: Linked_list, array
void Board::setDataStructure(const std::string& data_structure) {
  std::cout << "Board::setDataStructure()" << std::endl;
  if (data_structure == "input") {
    std::cout << "please insert data_structure" << std::endl;
    std::cin >> data_structure_;
  }
  else {
    data_structure_ = data_structure;
  }
  std::cout << "data_structure_: " << data_structure_ << std::endl;

}

void Board::setCells(const std::string& mode
                    ,int value
                        )
{
    if (data_structure_ == "array") {
      std::cout << "Board::setCells() array" << std::endl;

    }

    else if (data_structure_ == "linked_list") {
        std::cout << "Board::setCells() linked_list" << std::endl;

      if (mode == "init"){
        for (int i = 0; i < cells_containers_size_; i++) {
          cell_linked_list_array.at(i) = std::make_shared<Linked_list>();
        }

      }
      else if (mode == "equal"){
        for (int i = 0; i < cells_containers_size_; i++) {
          cell_linked_list_array.at(i)->set_values(mode, value);

        }
      }
      else
      {
        for (int i = 0; i < cells_containers_size_; i++) {
          cell_linked_list_array.at(i) = std::make_shared<Linked_list>();
        }
      }

    }
    else {
        std::cout << "Board::setCells() : unknown data_structure_, cell_linked_list_array initialization: array" << std::endl;
    }


}
std::shared_ptr<Linked_list> Board::get_cells(int row) {
    return cell_linked_list_array.at(row);
}

//cells_container move cells
//void Board::moveCells(int row, int column, int direction) {
//  if (direction == 0) {
//    for (int i = 0; i < cells_containers_container_size_-column-1; i++) {
//      replaceCellValue(row, i);
//    }
//  }
//  else if (direction == 1) {
//    for (int i = 0; i < cells_containers_container_size_-column-1; i++) {
//      replaceCellValue(row, cells_containers_container_size_-1-i);
//    }
//  }
//  else if (direction == 2) {
//    for (int i = 0; i < cells_containers_size_-row-1; i++) {
//      replaceCellValue(i, column);
//    }
//  }
//  else if (direction == 3) {
//    for (int i = 0; i < cells_containers_size_-row-1; i++) {
//      replaceCellValue(cells_containers_size_-1-i, column);
//    }
//  }
//}

//crush column
void Board::crushColumn(int column,
                        int origin,
                        int nodes_quantity
                            ) {
  get_cells(column)->crush(origin,
                           nodes_quantity);
//  get_cells(column)->move(origin, destination, nodes_quantity);
}


void Board::crush() {

    for (int i = 0; i < cells_containers_size_; i++) {
        for (int j = 0; j < cells_containers_container_size_; j++) {
//        if (get_cells(i)->get_head()->getValue() == get_cells(i)->get_head()->getNext()->getValue()) {
//            crushColumn(i, j, 2);
//        }
        }
    }

}
//
////cell_linked_list_array update cell_array_array or Canvas->cells
//void Board::updateCells(std::string to_update) {
//  if (data_structure_ == "array") {
//    std::cout << "Board::updateCells() array" << std::endl;
//  }
//  else if (data_structure_ == "linked_list") {
//    std::cout << "Board::updateCells() linked_list" << std::endl;
//    for (int i = 0; i < cells_containers_container_size_ ; i++) {
//        std::shared_ptr<Node> temp_node = cell_linked_list_array.at(i)->get_head();
//
//      for (int j = 0; j < cells_containers_size_ ; j++) {
//
//        int temp_value = temp_node->getValue();
//        int temp_type = temp_node->getType();
//
//        if (to_update == "cell_array_array") {
//          cell_array_array.at(i).at(j)->set(temp_value
//                                            ,temp_type
//                                            );        }
//        else if (to_update == "canvas") {
//          canvas_.getCells().at(i*j).setFillColorFrom(temp_node->getValue());
//        }
//        else {
//          std::cout << "Board::updateCells() : unknown to_update, cell_array_array initialization: array" << std::endl;
//        }
//        temp_node = temp_node->get_next();
//      }
//    }
//  }
//  else {
//    std::cout << "Board::updateCells() : unknown data_structure_, cell_array_array initialization: array" << std::endl;
//  }
//}
int Board::get_cells_containers_size() {
    return cells_containers_size_;
}
int Board::get_cells_containers_container_size() {
    return cells_containers_container_size_;
}




