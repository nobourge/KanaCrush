//
// Created by bourg on 28-12-21.
//

#include "Mboard.h"

#include <utility>


void Board::newGame() {
//    int types_quantity = 6;
//    for (auto &c: cells_) for (auto &x: c) x = squareType[(rand() % types_quantity - 1) + 1] ;
//    currentGameState = Play;
}

//squareType Board::getSquareType(int row, int column) const {
//    return cells_.at(row).at(column);
//}
//gameState Board::getGameState() const {
//    return currentGameState;
//}

void Board::crush() {


}
void Board::swap(int row1, int col1, int row2, int col2){
//    squareType candy1square_type = getSquareType(row1, col1);

  int tmp = cells_.at(row1).at(col1).getValue();
  cells_.at(row1).at(col1).setValue(cells_.at(row2).at(col2).getValue());

    cells_.at(row2).at(col2).setValue(tmp);

//    int tmp = cells_->at(row1).at(col1).getValue();
//  cells_->at(row1).at(col1).setValue(cells_->at(row2).at(col2).getValue());
//
//    cells_->at(row2).at(col2).setValue(tmp);
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
//    return cells_.at(row).at(column).getValue();
//}
//void Board::setCellValue(int row, int column, int value) {
//    cells_.at(row).at(column).setValue(value);
//}
void Board::printBoard(const std::string& cells_containers_head_orientation) {
    std::cout << "Board::printBoard()" << std::endl;
    if (cells_containers_head_orientation == "left")
    {
        for (auto &c: cells_)
        {
            for (auto &x: c)
            {
                std::cout << x.getValue() << " ";
            }
            std::cout << std::endl;
        }
    }
    else if (cells_containers_head_orientation == "right")
    {
      //print containers in reverse order
        for (auto it = cells_.rbegin(); it != cells_.rend(); ++it)
        {
            for (auto &x: *it)
            {
                std::cout << x.getValue() << " ";
            }
            std::cout << std::endl;
        }
    }
    else if (cells_containers_head_orientation == "up") {
      //print containers heads on first line
      for (int i = 0; i < cells_.size(); i++)
        {
        for (auto &c : cells_) {
          std::cout << c.at(i).getValue() << " ";
        }
      std::cout << std::endl;
      }
    }

    else if (cells_containers_head_orientation == "down")
      {
        //print containers heads on last line
        for ( int i = cells_.size() - 1; i >= 0; i--)
        {
          for (auto &c : cells_) {
            std::cout << c.at(i).getValue() << " ";
          }
          std::cout << std::endl;

        }
      }
    else
    {
        std::cout << "Board::printBoard() - invalid cells_containers_head_orientation" << std::endl;
    }
}
void Board::cellsInitRandom() {
  //init random cells_
    for (int i = 0; i < rows_quantity; i++) {
        for (int j = 0; j < columns_quantity; j++) {
//          cells_.emplace_back(std::make_shared<Cell>());
//            cells_.push_back() std::make_shared<Cell>(rand() % (5 + 1), rand() % (5 + 1));
//            cells_[i][j] = std::make_shared<Cell>(rand() % (5 + 1), rand() % (5 + 1));
        }
    }
}
int Board::getCellType(int row, int column) const {
  return 0;
}
void Board::cellsInitValueAscent() {

  std::cout << "cells_ size: " << cells_.size() << std::endl;
//cells_ set ascending value
    for (int i = 0; i < rows_quantity; i++) {
        for (int j = 0; j < columns_quantity; j++) {
            cells_.at(i).at(j).setValue(i * columns_quantity + j);
        }
    }

//  std::vector<std::vector<Cell>> cells_ = {};
//  auto cells_ = std::array<std::array<Cell("ascent"), columns_quantity>, rows_quantity>;
//  cells_ = {};
//  std::array<std::array<Cell(), columns_quantity>, rows_quantity> cells_ = {};
}

//set cells_container_head_orientation: left, right, up, down set
//void Board::setCellsValueDistribution() {
void Board::setCellsValueDistribution(const std::string& value_distribution) {

  if (value_distribution == "input"){
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
    std::cout << "Board::Board(std::string value_distribution) : unknown value_distribution, cells_ initialization: random" << std::endl;
    cellsInitRandom();
  }
}

void Board::setCellsContainersHeadOrientation(const std::string& cells_containers_head_orientation="down") {
//void Board::setCellsContainersHeadOrientation() {

  if (cells_containers_head_orientation == "input") {
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
    setCellsValueDistribution();
    setCellsContainersHeadOrientation();
//
//  deleteCell(0, 0);
//    deleteCell(0, 1);
//    deleteCell(0, 2);
  rain(0,0);
  printBoard(cells_containers_head_orientation_);

}
//Board::Board(const std::string &value_distribution, const std::string &cells_containers_head_orientation) {
//
//    std::cout << "Board::Board(std::string value_distribution, std::string cells_containers_head_orientation)" << std::endl;
//    cells_value_distribution_ = value_distribution;
//    cells_containers_head_orientation_ = cells_containers_head_orientation;
//    setCellsValueDistribution();
//    setCellsContainersHeadOrientation();
//    printBoard(cells_containers_head_orientation_);
//}

//delete cell
void Board::deleteCell(int row, int column) {
    cells_.at(row).at(column).setValue(0);

}


//add cell
void Board::addCell(int row, int column, int value) {
    cells_.at(row).at(column).setValue(value);
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
    cells_.at(row).at(column).setValue(cells_.at(row).at(column+1).getValue());
}



//cell rain
void Board::rain(int row, int column) {
    for (int i = 0; i < columns_quantity-column-1; i++) {
//        cells_.at(row).at(i).setValue(cells_.at(row).at(i+1).getValue());
      replaceCellValue(row, i);
      printBoard();
    }
}