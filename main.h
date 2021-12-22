//
// Created by bourg on 22-12-21.
//

#ifndef KANACRUSH_MAIN_H
#define KANACRUSH_MAIN_H

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

#include "src/model/cell/Mcell.cpp"
#include "src/control/cell/Ccell.cpp"
#include "src/view/cell/Vcell.cpp"

class MainWindow : public Fl_Window {
    //M
    shared_ptr<Board> board;
    //V
    DisplayBoard displayBoard;
    //C
    ControllBoard controllBoard;
public:
    MainWindow();
    void draw() {}
    //int handle(int event) override {}
    int handle() {return controllBoard.processEvent(event);}
    //static void Timer_CB(void *userdata) {}
    static void Timer_CB() {}
};

#endif //KANACRUSH_MAIN_H
