//
// Created by bourg on 28-12-21.
//

#include "Mboard.h"

Board::Board() {
  std::cout << "Board::Board()" << std::endl;
  std::cout << cells.at(0).at(0).getValue() << std::endl;

  printBoard();

}


void Board::newGame() {
//    int types_quantity = 6;
//    for (auto &c: cells) for (auto &x: c) x = squareType[(rand() % types_quantity - 1) + 1] ;
//    currentGameState = Play;
}

//squareType Board::getSquareType(int row, int column) const {
//    return cells.at(row).at(column);
//}
//gameState Board::getGameState() const {
//    return currentGameState;
//}

void Board::crush() {


}
void Board::swap(int row1, int col1, int row2, int col2){
//    squareType candy1square_type = getSquareType(row1, col1);

  int tmp = cells.at(row1).at(col1).getValue();
  cells.at(row1).at(col1).setValue(cells.at(row2).at(col2).getValue());

    cells.at(row2).at(col2).setValue(tmp);
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
//    return cells.at(row).at(column).getValue();
//}
//void Board::setCellValue(int row, int column, int value) {
//    cells.at(row).at(column).setValue(value);
//}
void Board::printBoard() {
    for (auto &c: cells) {
        for (auto &x: c) {
            std::cout << x.getValue() << " ";
        }
        std::cout << std::endl;
    }

}
void Board::cellsInitRandom() {
  //init random cells
    for (int i = 0; i < rows_quantity; i++) {
        for (int j = 0; j < columns_quantity; j++) {
//          cells.emplace_back(std::make_shared<Cell>());
//            cells.push_back() std::make_shared<Cell>(rand() % (5 + 1), rand() % (5 + 1));
//            cells[i][j] = std::make_shared<Cell>(rand() % (5 + 1), rand() % (5 + 1));
        }
    }
}
int Board::getCellType(int row, int column) const {
  return 0;
}
