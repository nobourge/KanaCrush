#include "Rectangle.h"

Rectangle::Rectangle(Point center_
                     , int w_1
                     , int h_1
                     , Fl_Color frame_color
                     , Fl_Color fill_color)
                   : Sketchable(center_
                                , w_1
                                , h_1
                                , frame_color
                                , fill_color) {}

void Rectangle::draw() {
  std::array<Point, 5> points{
      Point{center_.x-width_/2, center_.y-height_/2},
      Point{center_.x-width_/2, center_.y+height_/2},
      Point{center_.x+width_/2, center_.y+height_/2},
      Point{center_.x+width_/2, center_.y-height_/2},
      Point{center_.x-width_/2, center_.y-height_/2}};
  fl_color(fill_color_);
  fl_begin_polygon();
  for (auto& point : points) {
    fl_vertex(point.x, point.y);
  }
  fl_end_polygon();
  fl_color(frame_color_);
  fl_begin_line();
  for (auto& point : points) {
    fl_vertex(point.x, point.y);
  }
  fl_end_line();
}
void Rectangle::drawAt(int x, int y) {
  std::array<Point, 5> points{
      Point{x-width_/2, y-height_/2},
      Point{x-width_/2, y+height_/2},
      Point{x+width_/2, y+height_/2},
      Point{x+width_/2, y-height_/2},
      Point{x-width_/2, y-height_/2}};
  fl_color(fill_color_);
  fl_begin_polygon();
  for (auto& point : points) {
    fl_vertex(point.x, point.y);
  }
  fl_end_polygon();
  fl_color(frame_color_);
  fl_begin_line();
  for (auto& point : points) {
    fl_vertex(point.x, point.y);
  }
  fl_end_line();
}
void Rectangle::print(const std::string& attribute) const {
  std::cout << attribute << ": " << fill_color_ << std::endl;
  if (attribute == "fill_color_") {
    std::cout << attribute << ": " << fill_color_ << std::endl;
  } else if (attribute == "frame_color_") {
    std::cout << attribute << ": " << frame_color_ << std::endl;
  }

}
