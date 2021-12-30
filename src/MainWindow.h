//
// Created by bourg on 28-12-21.
//

#ifndef KANACRUSH_MAINWINDOW_H
#define KANACRUSH_MAINWINDOW_H

#include "1model/Mboard.h"
#include "2control/Cboard.h"
#include "3view/Vboard.h"
//#include "candy.h"
//#include "observer.h"


const int windowWidth = 3500;
const int windowHeight = 3500;
const double refreshPerSecond = 60;

class MainWindow : public Fl_Window {
    //M
    shared_ptr<Board> board;
    //V
    DisplayBoard displayBoard;
    //C
    ControlBoard controlBoard;
public:
    MainWindow();
    void draw() {}
    //int handle(int event) override {}
    int handle() {return controlBoard.processEvent(event);}
    //static void Timer_CB(void *userdata) {}
    static void Timer_CB() {}
};

#endif //KANACRUSH_MAINWINDOW_H
