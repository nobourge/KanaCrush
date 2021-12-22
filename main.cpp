
#include "main.h"

using namespace std;

const int windowWidth = 350;
const int windowHeight = 350;
const double refreshPerSecond = 60;

//class MainWindow : public Fl_Window {
    //shared_ptr<Board> board;
    //DisplayBoard displayBoard;
    //ControllBoard controllBoard;
//public:
MainWindow::MainWindow()
            :Fl_Window(500, 500, windowWidth, windowHeight, "Lab 11"),
             board{make_shared<Board>()},
             //view
             displayBoard(board),
             //control
             controllBoard(board) {
        Fl::add_timeout(1.0/refreshPerSecond, Timer_CB, this);
        resizable(this);
    }

void MainWindow::draw() override {
        Fl_Window::draw();
        displayBoard.draw();
    }
int MainWindow::handle(int event) override {
        return controllBoard.processEvent(event);
    }
static void MainWindow::Timer_CB(void *userdata) {
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

