#include "parameters.h"
#include "canvas.h"
#include "Bounce.h"
#include "animation.h"

#include <utility>
#include "srcCommon.h"

Canvas::Canvas(std::shared_ptr<Board> board) {
  if (DEBUG) {
    std::cout << "Canvas::Canvas(std::shared_ptr<Board> board)" << std::endl;

  }

  board_ = std::move(board);
  board_->print();
  heads_orientation_ = board_->getCellsContainersHeadOrientation();

  bounce_ = std::make_shared<Bounce>();
  for (int i = 0; i < cells_containers_container_size_ ; i++) {
    std::shared_ptr<Node> temp_node = board_->get_cells(i)->get_head();
    for (int j = 0; j < cells_containers_size_; j++) {
      cells_.at(i).at(j) = std::make_shared<ClickableCell>(Point{j * 50 - 25
                                                                 , i * 50 - 25}
                                                                 , 50
                                                                 , 50
                                                                 , FL_BLACK
                                                                 ,(Fl_Color) Colors_codes[(temp_node->getValue())-1]);
      temp_node = temp_node->get_next();
    }
  }
  if (DEBUG_CANVAS) {
    debug();
  }
}
//terminal print
void Canvas::print(    const std::string& head_orientation
) {
  if (DEBUG_CANVAS) {
    std::cout << "Canvas::print() - " << head_orientation << std::endl;
  }
  for (int i = 0; i < cells_containers_container_size_ ; i++) {
    std::cout << "-";
  }
  std::cout<< std::endl;

  if (head_orientation == "down")
  {

      for (int j = cells_containers_size_ - 1; j >= 0; j--)
      {
        for (int row = 0; row < cells_containers_container_size_; row++)
        {
        std::cout << cells_.at(row).at(j)->getFillColor() << " ";
      }
      std::cout<< std::endl;
    }
  }
  else if (head_orientation == "left")
    for (int i = cells_containers_container_size_ - 1; i >= 0; i--) {
      for (int j = 0; j < cells_containers_size_; j++) {
        std::cout << cells_.at(i).at(j)->getFillColor() << " ";
      }
      std::cout<< std::endl;
    }

  else if (head_orientation == "right")
    for (int i = 0; i < cells_containers_container_size_; i++) {
      for (int j = 0; j < cells_containers_size_; j++) {
        std::cout << cells_.at(i).at(j)->getFillColor() << " ";
      }
      std::cout<< std::endl;

    }
  for (int i = 0; i < cells_containers_container_size_ ; i++) {
    std::cout << "-";
  }
  std::cout<< std::endl;
}
void Canvas::draw(

    const std::string& head_orientation
                  ) {
  if (DEBUG_CANVAS) {
    std::cout << "Canvas::draw()" << std::endl;
  }

  if (head_orientation == "up")
  {
    for (int i = 0; i < cells_containers_container_size_; i++)
    {
      for (int j = cells_containers_size_ - 1; j >= 0; j--)
      {
        cells_[i][j]->draw();
      }
    }
  }
  else if (head_orientation == "down"){
      int x = 0;
        int y = 1;
      for (int col = cells_containers_container_size_ - 1; col >= 0; col--) {
        x=1;
        for (int row = 0; row < cells_containers_size_; row++) {
          cells_[row][col]->drawAt((x++) * 50 - 25,
                               (y) * 50 - 25);
        }
        y++;
    }
  }
  else if (head_orientation == "left")

    for (int i = 0; i < cells_containers_container_size_; i++) {
      for (int j = 0; j < cells_containers_size_; j++) {
        cells_[i][j]->drawAt((i + 1) * 50 - 25, (j + 1) * 50 - 25);
      }
    }
  else if (head_orientation == "right")
    for (int i = 0; i < cells_containers_container_size_; i++) {
      for (int j = 0; j < cells_containers_size_; j++) {
        cells_[i][j]->draw();
      }
    }
}
void Canvas::redraw() {

  if(DEBUG_CANVAS_REDRAW) {
    std::cout << "Canvas::redraw()" << std::endl;
  }
  update();
  if (DEBUG_CANVAS_REDRAW) {
    print();
  }
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

    char direction = 'V';
    if (x > dx or x < dx)
        char direction = 'H';
    else if (y > dy or y < dy)
        char direction = 'V';
    cout << "--------------------------------------" << endl;
    Translation t1{Point{x, dx}, direction};
//    bounce_->draw();

}

void Canvas::mouseRelease(Point mouseLoc) {

    if (DEBUG_CANVAS) {
        std::cout << "Canvas::mouseRelease()" << std::endl;
    }
  mouse_release = Point{Fl::event_x(),Fl::event_y()};

      n_du_carre_1_x_ = trunc(mouse_click.x / 50);
      nDuCarre1Y = trunc(mouse_click.y / 50);
      nDuCarre2X = trunc(mouse_release.x / 50);
      nDuCarre2Y = trunc(mouse_release.y / 50);

  // testing if the second rectangle is adjacent to the first one
  AdjacentX = (abs(n_du_carre_1_x_-nDuCarre2X) == 0 && abs(nDuCarre1Y-nDuCarre2Y) == 1);
  AdjacentY = (abs(n_du_carre_1_x_-nDuCarre2X) == 1 && abs(nDuCarre1Y-nDuCarre2Y) == 0);

  if (AdjacentX || AdjacentY) {
    std::vector<shared_ptr<ClickableCell>> cells_swapped;
    cells_swapped.push_back(cells_[n_du_carre_1_x_][nDuCarre1Y]);
    cells_swapped.push_back(cells_[nDuCarre2X][nDuCarre2Y]);

    if (heads_orientation_ == "down") {

      board_->swap(cells_containers_size_-nDuCarre1Y-1
                   , n_du_carre_1_x_
                   , cells_containers_size_-nDuCarre2Y-1
                   , nDuCarre2X);
    }
    update();
    board_->searchCrushableCells();
    if (board_->isCrushable())
        board_->crushWhilePossible();
    else
        board_->swap(cells_containers_size_-nDuCarre1Y-1
                     , n_du_carre_1_x_
                     , cells_containers_size_-nDuCarre2Y-1
                     , nDuCarre2X);
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

void Canvas::debug() {
    std::cout << "Canvas::debug()" << std::endl;
  std::cout << "canvas.cells_.size() : " << cells_.size() << std::endl;
  print();

}

void Canvas::update() {
  if (DEBUG_CANVAS) {
      std::cout << "Canvas::update()" << std::endl;
  }
  for (int i = 0; i < cells_containers_container_size_ ; i++) {
    std::shared_ptr<Node> temp_node = board_->get_cells(i)->get_head();
    for (int j = 0; j < cells_containers_size_ ; j++) {
      cells_.at(i).at(j)->setFillColorFrom((temp_node->getValue()) - 1);
      temp_node = temp_node->get_next();
    }
  }
  if (DEBUG_CANVAS) {
    debug();
  }
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
  std::vector<std::shared_ptr<ClickableCell>> Canvas::getCrushables(int x, int y, Fl_Color color, char direction,
                                                                    std::vector<std::shared_ptr<ClickableCell>> crushables) {

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