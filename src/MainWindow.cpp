//
// Created by bourg on 28-12-21.
//

#include "srcCommon.h"
#include "MainWindow.h"

MainWindow::MainWindow() : Fl_Window(300, 300, windowWidth, windowHeight, "Candy Crush")
{
    bool hmm = false;

    //board{make_shared<Board>()},
    //displayBoard(board),
    //controlBoard(board),

    board{make_shared<Board>()};
    DisplayBoard(board);
    ControlBoard(board);
    Fl::add_timeout(1.0/refreshPerSecond, Timer_CB, this);
    resizable(this);
}

void MainWindow::draw() override {
    Fl_Window::draw();
    displayBoard.draw();
}

int MainWindow::handle(int event) override {
    return controlBoard.processEvent(event);
}

static void MainWindow::Timer_CB(void *userdata) {
    MainWindow *o = (MainWindow*) userdata;
    o->redraw();
    Fl::repeat_timeout(1.0/refreshPerSecond, Timer_CB, userdata);
}
