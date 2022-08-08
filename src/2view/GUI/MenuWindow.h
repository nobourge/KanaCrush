//
// Created by noe on 08.08.22.
//

#ifndef KANACRUSH_SRC_2VIEW_GUI_MENUWINDOW_H_
#define KANACRUSH_SRC_2VIEW_GUI_MENUWINDOW_H_

#include "Window.h"
#include "FL_includes.h"
#include "Fl/Fl_Button.H"
#include "Fl/Fl_Box.H"
#include "srcCommon.h"


class MenuWindow : public Fl_Window {
//class MenuWindow : public GUIWindow {

//  Fl_Box *title;
//buttons
  int buttons_quantity = 5;
  int button_width = windowWidth / 2;
    int button_height = windowHeight / buttons_quantity;
    Fl_Button *button_start_ = new Fl_Button(10, 0, button_width, button_height, "Start");
    Fl_Button *button_exit_ = new Fl_Button(10, button_height * 1, button_width, button_height, "Exit");
    Fl_Button *button_help_ = new Fl_Button(10, button_height *2, button_width, button_height, "Help");
    Fl_Button *button_about_ = new Fl_Button(10, button_height *3, button_width, button_height, "About");
    Fl_Button *button_settings_ = new Fl_Button(10, button_height *4, button_width, button_height, "Settings");
public:
    MenuWindow() :Fl_Window(3000,
                            300,
                            windowWidth,
                            windowHeight,
                            "Kana Crush") {
      Fl::add_timeout(1.0 / refreshPerSecond, Timer_CB, this);

      add(button_start_);
        add(button_exit_);
        add(button_help_);
        add(button_about_);
        add(button_settings_);
//      set_resizable((Fl_Widget &) this);

    }
    void run(){
      show();
      Fl::run();
    };

  static void Timer_CB(void *userdata) {
    MenuWindow *o = (MenuWindow*) userdata;
    o->redraw();
    Fl::repeat_timeout(1.0/refreshPerSecond, Timer_CB, userdata);
  }

  void draw() override {
    Fl_Window::draw();
  }

//set buttons
//    void set_button_start(Fl_Button *button_start) {
//        button_start_ = button_start;
//    }
    void set_button_exit(Fl_Button *button_exit) {
        button_exit_ = button_exit;
    }
    void set_button_help(Fl_Button *button_help) {
        button_help_ = button_help;
    }
    void set_button_about(Fl_Button *button_about) {
        button_about_ = button_about;
    }
    void set_button_settings(Fl_Button *button_settings) {
        button_settings_ = button_settings;
    }
//
//    void mouseClick(Point p)  {
//        if (button_start_->inside(p)) {
//            button_start_->do_callback();
//        }
//        if (button_exit_->inside(p.x, p.y)) {
//            button_exit_->do_callback();
//        }
//        if (button_help_->inside(p.x, p.y)) {
//            button_help_->do_callback();
//        }
//        if (button_about_->inside(p.x, p.y)) {
//            button_about_->do_callback();
//        }
//        if (button_settings_->inside(p.x, p.y)) {
//            button_settings_->do_callback();
//        }
//    }



};

#endif //KANACRUSH_SRC_2VIEW_GUI_MENUWINDOW_H_
