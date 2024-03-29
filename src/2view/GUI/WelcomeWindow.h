#ifndef KANACRUSH_SRC_2VIEW_GUI_WELCOMEWINDOW_H_
#define KANACRUSH_SRC_2VIEW_GUI_WELCOMEWINDOW_H_


#include "Window.h"
#include "FL_includes.h"
#include "Fl/Fl_Button.H"
#include "Fl/Fl_Box.H"
#include "srcCommon.h"
#include "src/1model/Welcome.h"

class WelcomeWindow : public Fl_Window {
  Welcome welcome_ = Welcome();
  //title
    Fl_Box *title_ = new Fl_Box(0
        , 0
        , windowWidth
        , windowHeight / 10
        , "Kana Crush"
        );
    std::string author1 = "Bourgeois Noe";
    std::string author2 = "Morari Augustin";

    Fl_Box *authors_ = new Fl_Box(0, windowHeight / 10, windowWidth, windowHeight / 10,
                                  "Created by Morari Augustin and Bourgeois Noe"
//        , "Created by : \n" + author2 + "\n & \n" + author1
        );
public:
    WelcomeWindow() :Fl_Window(3000, 300, windowWidth, windowHeight, "Kana Crush") {

        add(title_);
        add(authors_);
//      set_resizable((Fl_Widget &) this);

    };
    void run();

  static void close(void *w);
};

#endif //KANACRUSH_SRC_2VIEW_GUI_WELCOMEWINDOW_H_
