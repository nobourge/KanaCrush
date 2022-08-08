//
// Created by noe on 25.07.22.
//

#include "canvas.h"



Canvas::Canvas() {
  srand(time(NULL)); // serves to get every time random colors
  for (int x = 0; x<10; x++) {
    for (int y = 0; y<10; y++) {
      cells.emplace_back(
          std::make_shared<Bounce>(
              std::make_shared<Rectangle>(Point{x*50-25,
                                                y*50-25},
                                          50,
                                          50,
                                          FL_BLACK,
                                          (Fl_Color) Colors_codes[rand()%6])));
    }
  }
}

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