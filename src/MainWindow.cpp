//
// Created by bourg on 28-12-21.
//

#include "MainWindow.h"

class MainWindow : public Fl_Window {
    Canvas canvas;
    bool hmm = false;
    Point mouse_click, mouse_move;
    int cellColor1;
    int cellColor2;
    int nDuCarre1X, nDuCarre1Y, nDuCarre2X, nDuCarre2Y;
public:
    MainWindow() : Fl_Window(3000, 300, windowWidth, windowHeight, "Lab 2") {
        Fl::add_timeout(1.0/refreshPerSecond, Timer_CB, this);
        resizable(this);
    }
    void draw() override {
        Fl_Window::draw();
        canvas.draw();
    }
    int handle(int event) override {
        switch (event) {
            case FL_DRAG:

                return 1;

            case FL_RELEASE:
                cout << "ici release !" << endl;
                mouse_move = Point{Fl::event_x(),Fl::event_y()};
                //board->swap(col1, row1, destination_column, destination_row);
                //board->move(col1, row1, destination_column, destination_row);
                //                mouse_move = Point{Fl::event_x(),Fl::event_y()};
                nDuCarre1X = trunc(mouse_click.x/50);
                nDuCarre1Y = trunc(mouse_click.y/50);
                nDuCarre2X = trunc(mouse_move.x/50);
                nDuCarre2Y = trunc(mouse_move.y/50);
                if ((abs(nDuCarre1X-nDuCarre2X) == 0 && abs(nDuCarre1Y-nDuCarre2Y) == 1) ||
                    (abs(nDuCarre1X-nDuCarre2X) == 1 && abs(nDuCarre1Y-nDuCarre2Y) == 0)) {
                    cellColor2 = canvas.checkColors(mouse_move);
                    cout << "colors : " << cellColor1 << " : " << cellColor2 << endl;
                    cout << mouse_click.x << ":" << mouse_click.y << endl;
                    cout << mouse_move.x << "::" << mouse_move.y << endl;
                    canvas.mouseClick(mouse_click, cellColor2);
                    canvas.mouseClick(mouse_move, cellColor1);
                    cout << "----------" << endl;
                    canvas.checkIfThree();
                    cout << "----------" << endl;
                }
                return 1;

            case FL_MOVE:
                canvas.mouseMove(mouse_move);
                return 1;

            case FL_PUSH:
                cout << "ici drag !" << endl;
                mouse_click = Point{Fl::event_x(),Fl::event_y()};
                cellColor1 = canvas.checkColors(mouse_click);
                return 1;

            case FL_KEYDOWN:
                canvas.keyPressed(Fl::event_key());
                return 1;
        }
        return 0;
    }
    static void Timer_CB(void *userdata) {
        MainWindow *o = (MainWindow*) userdata;
        o->redraw();
        Fl::repeat_timeout(1.0/refreshPerSecond, Timer_CB, userdata);
    }
};
