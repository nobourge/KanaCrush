#ifndef KANACRUSH_SRC_2VIEW_SKETCHABLE_H_
#define KANACRUSH_SRC_2VIEW_SKETCHABLE_H_

#include "srcCommon.h"
#include "constants.h"

class Sketchable {
  friend class Animation;
protected:
  Point center_{};
  int width_{};
  int height_{};
  Fl_Color fill_color_{};
  Fl_Color frame_color_{};

 public:
    Sketchable(Point center, int w, int h,
                 Fl_Color frameColor,
                 Fl_Color fillColor);
    void init(Point center, int w, int h,
                 Fl_Color frameColor,
                 Fl_Color fillColor);

    virtual void draw() = 0;
  [[nodiscard]] Fl_Color getFillColor() const;
  void setFillColor(Fl_Color newFillColor);
  virtual ~Sketchable() = default;;
  [[nodiscard]] Fl_Color getFrameColor() const;
  void setFrameColor(Fl_Color newFrameColor);
  void setFillColorFrom(int colorIndex);
  void setHeight(int new_height);
  [[nodiscard]] int getWidth() const;
  [[nodiscard]] int getHeight() const;
  void setWidth(int new_width);
  Point getCenter();
  [[nodiscard]] bool contains(Point p) const;
};



#endif //KANACRUSH_SRC_2VIEW_SKETCHABLE_H_
