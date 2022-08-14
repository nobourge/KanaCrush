//
// Created by noe on 25.07.22.
//
#include "parameters.h"
#include "canvas.h"
#include "Bounce.h"

#include <utility>
#include "srcCommon.h"


void Canvas::draw() {
  for (int i = 0; i < cells_containers_container_size_; i++) {
    for (int j = 0; j < cells_containers_size_; j++) {
      cells_[i][j]->draw();
    }
  }
//  for (auto &c: cells_) {
//    c.draw();
//  }

}
void Canvas::redraw() {

  update();
  draw();
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

//translates a cell
void Canvas::translateCell(int x, int y, int dx, int dy) {
//  todo
//   translate_.translate(x, y, dx, dy);
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
    std::vector<shared_ptr<ClickableCell>> cells_swapped;
    cells_swapped.push_back(cells_[n_du_carre_1_x_][nDuCarre1Y]);
    cells_swapped.push_back(cells_[nDuCarre2X][nDuCarre2Y]);
    // put the coordinates together to be able to access them through cell_linked_list_array
//    int concCarre1 = concatenate(n_du_carre_1_x_+1, nDuCarre1Y+1);
//    int concCarre2 = concatenate(nDuCarre2X+1, nDuCarre2Y+1);
    // getting the colors
//    cellColor1 = cells_[concCarre1].getFillColor();
  cellColor1 = cells_.at(n_du_carre_1_x_+1).at(nDuCarre1Y+1)->getFillColor();
//    cellColor2 = cells_[concCarre2].getFillColor();
  cellColor2 = cells_.at(nDuCarre2X+1).at(nDuCarre2Y+1)->getFillColor();

    // doing the animation always inwards for all the directions possible
    // and changing the colors accordingly right after the animation is ended
    fl_push_matrix();
    int click_cell_x = cells_.at(n_du_carre_1_x_+1).at(nDuCarre1Y+1)->getCenter().getX();
    int click_cell_y = cells_.at(n_du_carre_1_x_+1).at(nDuCarre1Y+1)->getCenter().getY();
    int release_cell_x = cells_.at(nDuCarre2X+1).at(nDuCarre2Y+1)->getCenter().getX();
    int release_cell_y = cells_.at(nDuCarre2X+1).at(nDuCarre2Y+1)->getCenter().getY();




    //game state : play (no potential possible crush)
//todo player swipe
// call translation function
// translateCell(n_du_carre_1_x_, nDuCarre1Y, nDuCarre2X, nDuCarre2Y);
// valid = getCrushables()
// if valid
// board_ matrix update
// else
// call translation function
// translateCell(nDuCarre2X, nDuCarre2Y, n_du_carre_1_x_, nDuCarre1Y);
//
//    if (nDuCarre2Y > nDuCarre1Y) {
//      auto crushables = getCrushables(cells_swapped,
//                                      'S');
//      if (crushables.size() > 0) {
//
//      fl_translate(click_cell_x, click_cell_y);
//
////
////      for (auto &c: cells_)
////        bounce_->bounce(c)
////        c.bounce(mouse_click, 1, 'V', cellColor2);
////      for (auto &c: cells_)
////        c.bounce(mouse_release, -1, 'V', cellColor1);
//    }

//    else if (nDuCarre2Y < nDuCarre1Y) {
//      bounce_->bounce(cells_[n_du_carre_1_x_][nDuCarre1Y],
//      for (auto &c: cells_)
//        c.bounce(mouse_release, 1, 'V', cellColor1);
//      for (auto &c: cells_)
//        c.bounce(mouse_click, -1, 'V', cellColor2);
//    }
//    else if (nDuCarre2X > n_du_carre_1_x_) {
//      for (auto &c: cells_)
//        c.bounce(mouse_click, 1, 'H', cellColor2);
//      for (auto &c: cells_)
//        c.bounce(mouse_release, -1, 'H', cellColor1);
//    }
//    else if (nDuCarre2X < n_du_carre_1_x_) {
//      for (auto &c: cells_)
//        c.bounce(mouse_release, 1, 'H', cellColor1);
//      for (auto &c: cells_)
//        c.bounce(mouse_click, -1, 'H', cellColor2);
//    }
//todo end
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

  }

  board_ = std::move(board);
  board_->print();
//
//  cells_containers_size_ = board_->get_cells_containers_size();
//  cells_containers_container_size_ = board_->get_cells_containers_container_size();

  bounce_ = std::make_shared<Bounce>();
//  update();
  for (int i = 0; i < cells_containers_container_size_ ; i++) {
    std::shared_ptr<Node> temp_node = board_->get_cells(i)->get_head();

    for (int j = 0; j < cells_containers_size_; j++) {
//      int temp_value = temp_node->getValue();
//      int temp_type = temp_node->getType();

      cells_.at(i).at(j) =
          std::make_shared<ClickableCell>(Point{i * 50 - 25,
                                                j * 50 - 25},
                                          50,
                                          50,
                                          FL_BLACK,
                                          (Fl_Color) Colors_codes[(temp_node->getValue())-1]//*

      );

      temp_node = temp_node->get_next();
    }
  }
  if (DEBUG_CANVAS) {
    debug();
  }
}
void Canvas::debug() {
    std::cout << "Canvas::debug()" << std::endl;
  std::cout << "canvas.cells_.size() : " << cells_.size() << std::endl;
  print();

}

void Canvas::update() {
  if (DEBUG_CANVAS) {
      std::cout << "Canvas::update()" << std::endl;
//      debug();
  }
  for (int i = 0; i < cells_containers_container_size_ ; i++) {
    std::shared_ptr<Node> temp_node = board_->get_cells(i)->get_head();
    for (int j = 0; j < cells_containers_size_ ; j++) {
//      int temp_value = temp_node->getValue();
//      int temp_type = temp_node->getType();
      cells_.at(i).at(j)->setFillColorFrom((temp_node->getValue()) - 1);
      temp_node = temp_node->get_next();
    }
  }
  if (DEBUG_CANVAS) {
    debug();
  }
}

//print
void Canvas::print() {
  for (int i = 0; i < cells_containers_container_size_ ; i++) {
    std::cout << "-";
  }
  std::cout<< std::endl;
  for (int i = 0; i < cells_containers_container_size_ ; i++) {
    for (int j = 0; j < cells_containers_size_ ; j++) {
      std::cout << cells_.at(i).at(j)->getFillColor() << " ";
    }
    std::cout << std::endl;
  }
  for (int i = 0; i < cells_containers_container_size_ ; i++) {
    std::cout << "-";
  }
  std::cout<< std::endl;
}


//
//get crushable cells from both sides of the cell
std::vector<std::shared_ptr<ClickableCell>> Canvas::getCrushablesFromDirectionXY(
    int current_x,
    int current_y,
    int direction_x,
    int direction_y,
    Fl_Color color,
    std::vector<std::shared_ptr<ClickableCell>> crushables
    ) {

  //for 2 cells
  while (cells_.at(current_x+=direction_x).at(current_y+=direction_y)->getFillColor() == color) {
    crushables.push_back(cells_.at(current_x).at(current_y));
  }
    return crushables;

}
  std::vector<std::shared_ptr<ClickableCell>> Canvas::getCrushables(
    int x,
    int y,
    Fl_Color color,
    char direction,
    std::vector<std::shared_ptr<ClickableCell>> crushables
    ) {

  switch (direction) {
    case 'N':getCrushablesFromDirectionXY(x, y, 0, -1, color, crushables);
      break;
    case 'S':
      getCrushablesFromDirectionXY(x, y, 0, 1, color, crushables);
        break;
    case 'E':
      getCrushablesFromDirectionXY(x, y, 1, 0, color, crushables);
        break;
    case 'W':
      getCrushablesFromDirectionXY(x, y, -1, 0, color, crushables);
        break;

  }
  return crushables;
}

//
////get crushable cells from the swapped cells
//std::vector<std::shared_ptr<ClickableCell>> Canvas::getCrushableCells(int cell_swapped_1_x,
//                                                                      char swap_direction) {
//  std::vector<std::shared_ptr<ClickableCell>> crushable_cells_;
//  switch (swap_direction) {
//    case 'N':
//        crushable_cells_ = getCrushables(cell_swapped_1_x, cell_swapped_1->getY(), cell_swapped_1->getFillColor(), 'N', crushable_cells_);
//        crushable_cells_ = getCrushables(cell_swapped_2->getX(), cell_swapped_2->getY(), cell_swapped_2->getFillColor(), 'S', crushable_cells_);
//        break;
//
//
//
//  }
//  return crushable_cells_;
//}