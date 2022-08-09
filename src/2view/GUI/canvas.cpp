//
// Created by noe on 25.07.22.
//
#include "parameters.h"
#include "canvas.h"

#include <utility>


void Canvas::draw() {
  for (auto &c: cells) {
    c.draw();
  }
}

void Canvas::mouseClick(Point mouseLoc) {
  mouse_click = Point{Fl::event_x(),Fl::event_y()};
}


///concatenates 2 ints into 1
unsigned concatenate(unsigned x, unsigned y) {
  unsigned pow = 10;
  while(y >= pow)
    pow *= 10;
  return x * pow + y;
}

void Canvas::mouseRelease(Point mouseLoc) {
  mouse_release = Point{Fl::event_x(),Fl::event_y()};
  n_du_carre_1_x_ = trunc(mouse_click.x/50);
  nDuCarre1Y = trunc(mouse_click.y/50);
  nDuCarre2X = trunc(mouse_release.x/50);
  nDuCarre2Y = trunc(mouse_release.y/50);
  // testing if the second rectangle is adjacent to the first one
  AdjacentX = (abs(n_du_carre_1_x_-nDuCarre2X) == 0 && abs(nDuCarre1Y-nDuCarre2Y) == 1);
  AdjacentY = (abs(n_du_carre_1_x_-nDuCarre2X) == 1 && abs(nDuCarre1Y-nDuCarre2Y) == 0);
  if (AdjacentX || AdjacentY) {
    // put the coordinates together to be able to access them through cell_linked_list_array
    int concCarre1 = concatenate(n_du_carre_1_x_+1, nDuCarre1Y+1);
    int concCarre2 = concatenate(nDuCarre2X+1, nDuCarre2Y+1);
    // getting the colors
    cellColor1 = cells[concCarre1].getColor(mouseLoc);
    cellColor2 = cells[concCarre2].getColor(mouse_release);
    // doing the animation always inwards for all the directions possible
    // and changing the colors accordingly right after the animation is ended
    if (nDuCarre2Y > nDuCarre1Y) {
      for (auto &c: cells)
        c.animationF(mouse_click, 1, 'V', cellColor2);
      for (auto &c: cells)
        c.animationF(mouse_release, -1, 'V', cellColor1);
    }
    else if (nDuCarre2Y < nDuCarre1Y) {
      for (auto &c: cells)
        c.animationF(mouse_release, 1, 'V', cellColor1);
      for (auto &c: cells)
        c.animationF(mouse_click, -1, 'V', cellColor2);
    }
    else if (nDuCarre2X > n_du_carre_1_x_) {
      for (auto &c: cells)
        c.animationF(mouse_click, 1, 'H', cellColor2);
      for (auto &c: cells)
        c.animationF(mouse_release, -1, 'H', cellColor1);
    }
    else if (nDuCarre2X < n_du_carre_1_x_) {
      for (auto &c: cells)
        c.animationF(mouse_release, 1, 'H', cellColor1);
      for (auto &c: cells)
        c.animationF(mouse_click, -1, 'H', cellColor2);
    }
  }
}

void Canvas::keyPressed(int keyCode) {
  switch (keyCode) {
    case 'q':
      exit(0);
    case 32: // Space bar
      exit(0);
  }
}
Canvas::Canvas(std::shared_ptr<Board> board) {
  if (DEBUG) {
    std::cout << "Canvas::Canvas(std::shared_ptr<Board> board)" << std::endl;
    std::cout << "Canvas::Canvas(std::shared_ptr<Board> board)" << std::endl;

  }

  board_ = std::move(board);
  board_->print();

  cells_containers_size_ = board_->get_cells_containers_size();
  cells_containers_container_size_ = board_->get_cells_containers_container_size();

//  update();
  for (int i = 0; i < cells_containers_container_size_ ; i++) {
    std::shared_ptr<Node> temp_node = board_->get_cells(i)->get_head();

    for (int j = 0; j < cells_containers_size_; j++) {
//      int temp_value = temp_node->getValue();
//      int temp_type = temp_node->getType();

      cells.emplace_back(
          std::make_shared<Bounce>(
              std::make_shared<Rectangle>(Point{i * 50 - 25,
                                                j * 50 - 25},
                                          50,
                                          50,
                                          FL_BLACK,
                                          (Fl_Color) Colors_codes[(temp_node->get_cell()->getValue())-1]
              )
          )
      );
      if (DEBUG_CANVAS) {
        std::cout << "Canvas::Canvas(std::shared_ptr<Board> board)" << std::endl;
        std::cout << "temp_node ->getValue() : " << temp_node->get_cell()->getValue() << std::endl;

        std::cout << "canvas.cells.size() : " << cells.size() << std::endl;
        std::cout << "canvas.cells.at(i*j).getFillColor() : " << cells.at(i*j).getFillColor() << std::endl;
        std::cout << "cells.at(i*j).print() : " << std::endl;
        cells.at(i*j).print();


      }
//
      temp_node = temp_node->get_next();
    }
  }
}
//
////get cells
////std::shared_ptr<std::vector<ClickableCell>> Canvas::getCells() {
//std::vector<ClickableCell> Canvas::getCells() {
//  return cells;
////  return std::make_shared<cells>();
//}

void Canvas::update() {
  for (int i = 0; i < cells_containers_container_size_ ; i++) {
    std::shared_ptr<Node> temp_node = board_->get_cells(i)->get_head();
    for (int j = 0; j < cells_containers_size_ ; j++) {
//      int temp_value = temp_node->getValue();
//      int temp_type = temp_node->getType();
      cells.at(i*j).setFillColorFrom((temp_node->getValue()) - 1);
      temp_node = temp_node->get_next();
    }
  }
}

//print
void Canvas::print() {
  for (auto &c: cells) {
    c.print();
  }
}

//update Vboard

//update Canvas cells
//void Board::updateCanvas() {
//  if (data_structure_ == "array") {
//    std::cout << "Board::updateCanvas() array" << std::endl;
//  }
//  else if (data_structure_ == "linked_list") {
//    std::cout << "Board::updateCanvas() linked_list" << std::endl;
//    for (int i = 0; i < cells_containers_container_size_ ; i++) {
//      //temp_node
//        std::shared_ptr<Node> temp_node = cell_linked_list_array.at(i)->get_head();
//
//      for (int j = 0; j < cells_containers_size_ ; j++) {
//
//        //and update cell_array_array
//        //at i,j
//        cell_array_array.at(i).at(j)->set(temp_node->getValue(),
//                                          temp_node->getType());
//        //iterate through linked list
//        //temps node
//        temp_node = temp_node->get_next();
//      }
//    }
//  }
//  else {
//    std::cout << "Board::updateCanvas() : unknown data_structure_, cell_array_array initialization: array" << std::endl;
//  }
//}

