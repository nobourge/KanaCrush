//
// Created by bourg on 28-12-21.
//

#include "Mboard.h"

Board::Board() {
  if (DEBUG_BOARD){
    std::cout << "Board::Board()" << std::endl;
  }
  setDataStructure("linked_list");
  setCells();
  setCells("equal",1);
//  setCellsValueDistribution("ascent");
  setCellsContainersHeadOrientation("down");

  print();
}
void Board::newGame() {
//    int types_quantity = 6;
//    for (auto &c: cell_linked_list_array) for (auto &x: c) x = squareType[(rand() % types_quantity - 1) + 1] ;
//    currentGameState = Play;
}


//swap two cells values and types
void Board::swap(int row1, int col1, int row2, int col2) {
  if (DEBUG_BOARD){
    std::cout << "Board::swap(" << row1 << ", " << col1 << ", " << row2 << ", " << col2 << ")" << std::endl;
    print();
  }
  std::shared_ptr<Node> to_swap_node_1 = cell_linked_list_array[col1]->get_node(row1);
  std::shared_ptr<Node> to_swap_node_2 = cell_linked_list_array[col2]->get_node(row2);
  int to_swap_value_1 = to_swap_node_1->getValue();
    int to_swap_value_2 = to_swap_node_2->getValue();
    int to_swap_type_1 = to_swap_node_1->getType();
      int to_swap_type_2 = to_swap_node_2->getType();
    to_swap_node_1->setValue(to_swap_value_2);
      to_swap_node_1->setType(to_swap_type_2);
    to_swap_node_2->setValue(to_swap_value_1);
        to_swap_node_2->setType(to_swap_type_1);
        if (DEBUG_BOARD){
          std::cout << "Board::swap(" << row1 << ", " << col1 << ", " << row2 << ", " << col2 << ") done" << std::endl;
          print();
        }
}


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
//                        //memorize for same axis other cardinal direction_
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

void Board::print()
{
  if (DEBUG_BOARD) {
    std::cout << "Board::print()" << std::endl;
    std::cout << "cells_containers_head_orientation: " << cells_containers_head_orientation_ << std::endl;
  }

  for (int i = 0; i < cells_containers_container_size_ ; i++) {
    std::cout << "-";
  }
  std::cout<< std::endl;
    if (data_structure_ == "linked_list")
    {
      if (DEBUG)
      {
        std::cout << "Board::print() linked_list->print()" << std::endl;
        for (auto &linked_list : cell_linked_list_array) {
          linked_list->print();
        }
//        for (int i = 0; i < cells_containers_container_size_ ; i++) {
//          std::shared_ptr<Node> temp_node = get_cells(i)->get_head();
//
//          for (int j = 0; j < cells_containers_size_; j++) {
//            std::cout << "temp_node ->getValue() : " << temp_node->getValue() << std::endl;
////            std::cout << "temp_node ->getValue() : " << temp_node->get_cell()->getValue() << std::endl;
//          }
//        }
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
//        std::cout << "cells_ size: " << cell_linked_list_array.size() << std::endl;
        for (int i = 0; i < cell_linked_list_array.size(); i++)
        {
          for (auto &linked_list : cell_linked_list_array)
          {

            if (i == 0)
            {
              linked_list->end();
            }
            else
            {
              linked_list->previous();
            }
            std::cout << linked_list->get_iterator()->getValue() << " ";//*

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

  for (int i = 0; i < cells_containers_container_size_ ; i++) {
    std::cout << "-";
  }
  std::cout<< std::endl;
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

//set data_structure: Linked_list or array
void Board::setDataStructure(const std::string& data_structure) {
  if (DEBUG_BOARD){
    std::cout << "Board::setDataStructure()" << std::endl;

  }
  if (data_structure == "input") {
    std::cout << "please insert data_structure" << std::endl;
    std::cin >> data_structure_;
  }
  else {
    data_structure_ = data_structure;
  }
  if (DEBUG_BOARD){
    std::cout << "Board::setDataStructure()" << std::endl;
    std::cout << "data_structure_: " << data_structure_ << std::endl;

  }
}

void Board::setCells(const std::string& mode
                    ,int value
                        )
{
  if (DEBUG_BOARD){
    std::cout << "Board::setCells()" << std::endl;
    std::cout << "mode: " << mode << std::endl;
    std::cout << "value: " << value << std::endl;
  }
    if (data_structure_ == "array") {


    }

    else if (data_structure_ == "linked_list") {
      if (DEBUG_BOARD) {
        std::cout << "Board::setCells() linked_list" << std::endl;
      }

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

//cells_container move cells_
//void Board::moveCells(int row, int column, int direction_) {
//  if (direction_ == 0) {
//    for (int i = 0; i < cells_containers_container_size_-column-1; i++) {
//      replaceCellValue(row, i);
//    }
//  }
//  else if (direction_ == 1) {
//    for (int i = 0; i < cells_containers_container_size_-column-1; i++) {
//      replaceCellValue(row, cells_containers_container_size_-1-i);
//    }
//  }
//  else if (direction_ == 2) {
//    for (int i = 0; i < cells_containers_size_-row-1; i++) {
//      replaceCellValue(i, column);
//    }
//  }
//  else if (direction_ == 3) {
//    for (int i = 0; i < cells_containers_size_-row-1; i++) {
//      replaceCellValue(cells_containers_size_-1-i, column);
//    }
//  }
//}

//crushable_cells_ print
void Board::crushable_cells_Print() {
  if (DEBUG
  ||DEBUG_BOARD
  ||DEBUG_CRUSH) {
    std::cout << "Board::crushable_cells_Print()" << std::endl;
    std::cout << "crushable_cells_: " << std::endl;
  }
  int i = 0;
  for (auto &array_vector: crushable_cells_)
  {
//    get_cells(i)->print();
    std::cout << "array_vector column: " << i << " ";
    i++;
    if (array_vector.empty()) {
      std::cout << " empty" ;
    }
    else {
      for (auto &origin_node_quantity_bool : array_vector) {
        std::cout
        << origin_node_quantity_bool[0] << " "
        << origin_node_quantity_bool[1] << " "
        << origin_node_quantity_bool[2];

      }
    }
    std::cout << std::endl;
  }
}
//crushable cells at array (column) index at vector index push back new array
void Board::crushableCellsAddNewSerie(int column,
                                       int origin
                                       )
{
  if (DEBUG_CRUSH)
  {
    std::cout << "             vector empty or last serie ended" << std::endl;
    std::cout << "                        create new" << std::endl;
  }
  crushable_cells_.at(column).push_back({origin, 1,-1});
  if (DEBUG_CRUSH)
  {
    std::cout << "                        push_back" << std::endl;
    crushable_cells_Print();
  }
}
void Board::crushableCellsUpdate(int column
                                 ,int origin
                                 )
                                 {
  if (!crushable_cells_.at(column).empty()) {
//      std::array column_current_array = crushable_cells_.at(column).back();
//      std::shared_ptr<std::array> column_current_array = crushable_cells_.at(column).back();
    if (crushable_cells_.at(column).back().at(2) == -1){
      //column_current_array not closed
      if (origin==-1)
      {
        //close column_current_array
        crushable_cells_.at(column).back().at(2) = 1;
        if (DEBUG_CRUSH)
        {
          std::cout << "             vector not empty and last serie not ended" << std::endl;
          std::cout << "                        close last serie" << std::endl;
        }
      }
      else
      {
        crushable_cells_.at(column).back().at(1)++;
        if (DEBUG_CRUSH)
        {
          std::cout << "                        column_current_array not closed" << std::endl;
          std::cout << "                        column_current_array.at(1)++" << std::endl;
          std::cout << "                        column_current_array.at(1): " << crushable_cells_.at(column).back().at(1) << std::endl;
        }
      }
    }
  }
  else
  {
    if (DEBUG_CRUSH)
    {
      std::cout << "                        column_current_array empty" << std::endl;
    }
    if (origin!=-1)
    {
      crushableCellsAddNewSerie(column, origin);
    }
  }
}
//search crushable_cells_
//todo from the last crush zone +2
//todo array9 not resizable replace with vector
void Board::searchCrushableCells()
{
//std::array<std::vector<std::array<int, 3>>, 9> Board::searchCrushableCells() {
// 1 origin
// 2 nodes quantity
// 3 crushable bool

  if (DEBUG_CRUSH)
  {
    std::cout << "Board::searchCrushableCells()" << std::endl;
  }

  crushable_ = false;
  int current_value;

  bool adding_horizontal = false;
  bool adding_vertical[cells_containers_container_size_] = {false};
  if (DEBUG_CRUSH)
  {
    std::cout << "adding_vertical: " << std::endl;
    for (bool i : adding_vertical)
    {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }
  bool added = false;

  for (int i = 0; i < cells_containers_container_size_; i++)
  {
    int column = 0;
    adding_horizontal = false;
    if (DEBUG_CRUSH)
    {
      std::cout << "i row: " << i << std::endl;
    }
    for (auto &linked_list: cell_linked_list_array) {
      if (i == 0) {
        linked_list->begin();
      } else {
        linked_list->next();
      }
    }
    for (auto &linked_list: cell_linked_list_array)
    {
      added = false;
      if (DEBUG_CRUSH) {
        std::cout << "column: " << column << std::endl;
        crushable_cells_Print();
        std::cout << "adding_horizontal: " << adding_horizontal << std::endl;
        std::cout << "adding_vertical: " << std::endl;
        for (bool a : adding_vertical)
        {
          std::cout << a << " ";
        }
        std::cout << "adding_vertical current: " << adding_vertical[column] << std::endl;
      }

      current_value = linked_list->get_iterator()->getValue();
      if (DEBUG_CRUSH)
      {
        std::cout << "current_value: " << current_value << std::endl;
      }
      if (adding_vertical[column])
      {
        crushableCellsUpdate(column,
                             i)
            ;
        added = true;
        if (i < cells_containers_container_size_-1)
        {
          if (current_value != linked_list->get_iterator()->get_next()->getValue())
          {
            adding_vertical[column] = false;
          }
        }
      }
      else
      {
        if (i < cells_containers_container_size_-2)
        {
          //in range search
          if (current_value == linked_list->get_iterator()->get_next()->getValue())
          {
            if (DEBUG_CRUSH)
            {
              std::cout << "current = vertical next" << std::endl;
            }
            if (current_value == linked_list->get_iterator()->get_next()->get_next()->getValue())
            {

              if (DEBUG_CRUSH)
              {
                std::cout << "current = vertical next next" << std::endl;
                std::cout << "serie vertical start" << std::endl;
              }
              crushableCellsUpdate(column,
                                   i);
              adding_vertical[column] = true;
              added = true;
            }
          }
        }
      }
      if (adding_horizontal)
      {
        if (!added)
        {
          crushableCellsUpdate(column,
                               i);
          added = true;
        }
        if (column < cells_containers_container_size_-1)
        {
          if (current_value != cell_linked_list_array.at(column+1)->get_iterator()->getValue())
          {
            adding_horizontal = false;
          }
        }
      }
      else
      {
        if (column < cells_containers_container_size_-2)
        {
          if (current_value == cell_linked_list_array.at(column+1)->get_iterator()->getValue())
          {
            if (DEBUG_CRUSH) {
              std::cout << "current = horizontal next" << std::endl;
            }
            if (current_value == cell_linked_list_array.at(column+2)->get_iterator()->getValue())
            {
              adding_horizontal = true;

              if (DEBUG_CRUSH)
              {
                std::cout << "current = horizontal next next" << std::endl;
                std::cout << "serie adding_horizontal start" << std::endl;
                std::cout << "adding_horizontal: " << adding_horizontal << std::endl;
              }
              if (!added)
              {
                crushableCellsUpdate(column,
                                     i);
                added = true;
              }
            }
          }
        }
      }
      if (!added)
      {
        //if serie open, close serie
        crushableCellsUpdate(column);
      }
      else
      {
        if (DEBUG_CRUSH)
        {
          std::cout << "                        added" << std::endl;
        }
        crushable_ = true;
      }
      column++;
    }
  }
//  return crushable_cells_;
  if (DEBUG_CRUSH)
  {
    std::cout << "Board::searchCrushableCells() DONE" << std::endl;
    print();
    std::cout << "cells to crush: " << std::endl;
    crushable_cells_Print();
  }
}
//get crushable_cells_
// returns a vector of vectors of arrays of int
std::array<std::vector<std::array<int, 3>>, 9> Board::getCrushableCells()
{
  return crushable_cells_;
}

//crush column
void Board::crushColumn(int column,
                        std::vector<std::array<int,3>> &origins_and_nodes_quantities
                            ) {
  if (DEBUG_CRUSH){
    std::cout << "Board::crushColumn()" << std::endl;
    std::cout << "column: " << column << std::endl;
    for (auto &origin_and_nodes_quantity: origins_and_nodes_quantities)
    {
      std::cout << "origin: " << origin_and_nodes_quantity[0] << " nodes quantity: " << origin_and_nodes_quantity[1] << std::endl;
    }
    for (int i = origins_and_nodes_quantities.size()-1; 0 <= i ; i--) {
      std::cout
          << origins_and_nodes_quantities[i][0] << " "
          << origins_and_nodes_quantities[i][1] << " "
          << origins_and_nodes_quantities[i][2];
      std::cout << std::endl;
    }
  }
  get_cells(column)->crush(origins_and_nodes_quantities);
//  get_cells(column)->move(origin, destination, nodes_quantity);

    if (DEBUG_CRUSH){
        std::cout << "Board::crushColumn()" << std::endl;
        print();
    }
}
bool Board::crush() {
  if (DEBUG_CRUSH){
    std::cout << "Board::crush()" << std::endl;
  }
  if (crushable_cells_.empty())
  {
    return false;
  }
    if (DEBUG_CRUSH){
        print();
    }
    for (int i = 0; i < cells_containers_size_; i++) {
        if (!crushable_cells_.at(i).empty()) {
          crushColumn(i, crushable_cells_.at(i));
        }
    }
    if (DEBUG_CRUSH){
        std::cout << "Board::crush() DONE" << std::endl;
    }
    emptyCrushableCellsVectors();
  print();

}

int Board::get_cells_containers_size() {
    return cells_containers_size_;
}
int Board::get_cells_containers_container_size() {
    return cells_containers_container_size_;
}

//empties crushable_cells_ vectors
void Board::emptyCrushableCellsVectors() {
  for (int i = 0; i < cells_containers_container_size_; i++) {
    crushable_cells_.at(i).clear();
  }
}
bool Board::isCrushable() const {
  return crushable_;
}

//crush while possible
bool Board::crushWhilePossible() {
  if (DEBUG_CRUSH){
    std::cout << "Board::crushWhilePossible()" << std::endl;
  }
  searchCrushableCells();

    if (!crushable_) {
        return false;
    }
  while (crushable_) {
    crush();
    searchCrushableCells();
    if (DEBUG_CRUSH){
      std::cout << "cells to crush: " << std::endl;
      crushable_cells_Print();
    }
  }

  if (DEBUG_CRUSH){
    std::cout << "Board::crushWhilePossible() DONE" << std::endl;
  }
}
std::basic_string<char> Board::getCellsContainersHeadOrientation() {
  return cells_containers_head_orientation_;

}



