// These should include everything you might use
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include <string>
#include <math.h>
#include <time.h>
#include <chrono>
#include <vector>
#include <iostream>
#include <array>
#include <memory>

#include "src/control/cell/Ccell.cpp"
#include "src/model/cell/Mcell.cpp"
#include "src/view/cell/Vcell.cpp"


using namespace std;

const int windowWidth = 350;
const int windowHeight = 350;
const double refreshPerSecond = 60;

/*--------------------------------------------------
DispalyBoard class.
--------------------------------------------------*/



/*--------------------------------------------------
ControllBoard class.
--------------------------------------------------*/



/*--------------------------------------------------
MainWindow class.
--------------------------------------------------*/

class MainWindow : public Fl_Window {
    shared_ptr<Board> board;
    DisplayBoard displayBoard;
    ControllBoard controllBoard;
public:
    MainWindow()
            :Fl_Window(500, 500, windowWidth, windowHeight, "Lab 11"),
             board{make_shared<Board>()},
             displayBoard(board),
             controllBoard(board) {
        Fl::add_timeout(1.0/refreshPerSecond, Timer_CB, this);
        // resizable(this);
    }
    void draw() override {
        Fl_Window::draw();
        displayBoard.draw();
    }
    int handle(int event) override {
        return controllBoard.processEvent(event);
    }
    static void Timer_CB(void *userdata) {
        MainWindow *o = (MainWindow*) userdata;
        o->redraw();
        Fl::repeat_timeout(1.0/refreshPerSecond, Timer_CB, userdata);
    }
};

int main(int argc, char *argv[]) {
    MainWindow window;
    window.show(argc, argv);
    return Fl::run();
}

