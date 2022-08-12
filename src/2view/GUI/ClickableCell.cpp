//
// Created by noe on 08.08.22.
//

#include "ClickableCell.h"
//
//void ClickableCell::draw() {
//  animation_->draw();
//}


ClickableCell::ClickableCell(Point center
                             , int w
                             , int h
                             , Fl_Color frameColor
                             , Fl_Color fillColor)
                             : Rectangle(center
                                                                ,w
                                                                ,h
                                                                ,frameColor
                                                                ,fillColor
                                                                )
                                                                {

}


