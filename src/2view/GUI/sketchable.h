//
// Created by noe on 27.07.22.
//

#ifndef KANACRUSH_SRC_2VIEW_SKETCHABLE_H_
#define KANACRUSH_SRC_2VIEW_SKETCHABLE_H_

#include "srcCommon.h"
#include "constants.h"

class Sketchable {
  friend class Animation;
protected:
  Point center_{};
  int width_;
  int height_;
  Fl_Color fill_color_;
  Fl_Color frame_color_;

 public:
    Sketchable(Point center, int w, int h,
                 Fl_Color frameColor,
                 Fl_Color fillColor);
    void init(Point center, int w, int h,
                 Fl_Color frameColor,
                 Fl_Color fillColor);

    virtual void draw() = 0;
//  bool contains(Point p) const =0;
//  virtual bool contains(Point p) const =0;
//  Point getCenter() const;
//  [[nodiscard]] virtual Fl_Color PointgetColor(Point mouseLoc) const =0;
  Fl_Color getFillColor() const;
  void setFillColor(Fl_Color newFillColor);
//  virtual void setFillColor(Fl_Color newFillColor) =0;
  virtual ~Sketchable() = default;;
  [[nodiscard]] Fl_Color getFrameColor() const;
  void setFrameColor(Fl_Color newFrameColor);
  void setFillColorFrom(int colorIndex);
  void setHeight(int new_height);
  [[nodiscard]] int getWidth() const;
  [[nodiscard]] int getHeight() const;
  void setWidth(int new_width);
  Point getCenter();
};



#endif //KANACRUSH_SRC_2VIEW_SKETCHABLE_H_
