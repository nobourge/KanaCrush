
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
#include <random>
#include <list>
#include <cstdlib>
#include <ctime>

using namespace std;

bool appuye=false;
const int carres_plateau=9;
const int windowWidth=450;
const int windowHeight=450;
const double refreshPerSecond=60;

struct Point {
    int x,y;
};

/*--------------------------------------------------
Rectangle class.
--------------------------------------------------*/

class Rectangle{
    Point center;
    int w,h;
    Fl_Color fillColor, frameColor;
public:
    Rectangle(Point center,int w, int h,
              Fl_Color frameColor=FL_BLACK,
              Fl_Color fillColor=FL_WHITE);
    void draw();
    void setFillColor(Fl_Color newFillColor);
    void setFrameColor(Fl_Color newFrameColor);
    bool contains(Point p);
    int getColor();
};

Rectangle::Rectangle(Point center,int w, int h,
                     Fl_Color frameColor,
                     Fl_Color fillColor):
        center{center},w{w},h{h},fillColor{fillColor},frameColor{frameColor}{}

void Rectangle::draw(){
    fl_draw_box(FL_FLAT_BOX,center.x-w/2,center.y-h/2,w,h,fillColor);
    fl_draw_box(FL_BORDER_FRAME,center.x-w/2,center.y-h/2,w,h,frameColor);
}

void Rectangle::setFillColor(Fl_Color newFillColor){
    fillColor=newFillColor;
}

void Rectangle::setFrameColor(Fl_Color newFrameColor){
    frameColor=newFrameColor;
}

bool Rectangle::contains(Point p){
    return p.x>=center.x-w/2 &&
           p.x<center.x+w/2 &&
           p.y>=center.y-h/2 &&
           p.y<center.y+h/2;
}
int Rectangle::getColor() {
    return fillColor;
}

/*--------------------------------------------------
Cell class.
--------------------------------------------------*/

class Cell {
    Rectangle r;
    vector<int> l{1, 91, 3, 2, 4, 232}; // voir fltk color map
    int index = rand() % l.size();
    int color = l[index];
    bool on=false;
public:
    Cell(Point center,int w, int h);
    void draw();
    void mouseMove(Point mouseLoc);
    void mouseClick(Point mouseLoc1, int colorID);
    int checkColors(Point mouseLoc);
    int retColor();
};

Cell::Cell(Point center,int w, int h):
        r(center,w,h,FL_BLACK, color){}
void Cell::draw(){
    r.draw();
}
void Cell::mouseMove(Point mouseLoc){
    if (r.contains(mouseLoc)){
        r.setFrameColor(FL_RED);
    }
    else {
        r.setFrameColor(FL_BLACK);
    }
}
void Cell::mouseClick(Point mouseLoc, int colorID){
    if (r.contains(mouseLoc)){
        r.setFillColor(colorID);
    }
}
int Cell::checkColors(Point mouseLoc) {
    if (r.contains(mouseLoc)) {
        return r.getColor();
    }
    return 0;
}
int Cell::retColor(){
    return r.getColor();
}

/*--------------------------------------------------
Canvas class.
--------------------------------------------------*/

class Canvas{
    vector<Cell> cells;
    vector<int> colors;
public:
    Canvas();
    void draw();
    void mouseMove(Point mouseLoc);
    void mouseClick(Point mouseLoc1, int colorID);
    void keyPressed(int /*keyCode*/) {exit(0);}
    int checkColors(Point mouseLoc);
    void checkIfThree();
};

Canvas::Canvas(){
    for (int i=0;i<90;i++)
        cells.push_back(Cell{Point{50*(i%9)+25,50*(i/10)+25},50,50});
// You could also write:
//        cells.push_back({Point{50*(i%10)+25,50*(i/10)+25},40,40});
}
void Canvas::draw() {
    for (auto &c:cells) c.draw();
}
void Canvas::mouseMove(Point mouseLoc){
    for (auto &c:cells) c.mouseMove(mouseLoc);
}
int Canvas::checkColors(Point mouseLoc){
    int cc;
    int finalcolor;
    //
    for (auto &c:cells) {
        cc = c.checkColors(mouseLoc);
        if (cc != 0)
            finalcolor = cc;
    }
    return finalcolor;
}
void Canvas::mouseClick(Point mouseLoc1, int colorID){
    for (auto &c:cells) c.mouseClick(mouseLoc1, colorID);
}
void Canvas::checkIfThree(){
    // 1 : red
    // 2 : green
    // 3 : yellow
    // 4 : blue
    // 91 : orange
    // 232 : purple
    cout << "inside chefIfThree" << sizeof(colors) << endl;
    for (auto &c:cells) {
        cout << "color is : " << c.retColor() << endl;
        colors.push_back(c.retColor());
    }
    int t = 0;
    for (auto const &i: colors) {
        if (t % 9 == 0)
            cout << "\n";
        cout << i << " ";
        t++;
    }
}

/*--------------------------------------------------
ControllBoard class.
--------------------------------------------------*/

class ControllBoard {
    Canvas canvas;
    Point mouse_click, mouse_move;
    int cellColor1;
    int cellColor2;
    int nDuCarre1X, nDuCarre1Y, nDuCarre2X, nDuCarre2Y;
public:
    int processEvent(const int event) {
        switch (event) {
            case FL_DRAG:
                return 1;
            case FL_RELEASE:
                cout << "ici release !" << endl;
                mouse_move = Point{Fl::event_x(),Fl::event_y()};
                //board->swap(col1, row1, destination_column, destination_row);
                //board->move(col1, row1, destination_column, destination_row);
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
                    // canvas.checkIfThree();
                    // cout << "----------" << endl;
                }
                return 1;

            case FL_MOVE:
                canvas.mouseMove(mouse_move);
                return 1;

            case FL_PUSH:
                cout << "ici drag !" << endl;
                mouse_click = Point{Fl::event_x(),Fl::event_y()};
                cellColor1 = canvas.checkColors(mouse_click);
                cout << "inside push : " << cellColor1 << endl;
                return 1;

            case FL_KEYDOWN:
                canvas.keyPressed(Fl::event_key());
                return 1;
        }
        return false;
    }
};

/*--------------------------------------------------
MainWindow class.
--------------------------------------------------*/

class MainWindow : public Fl_Window {
    Canvas canvas;
    ControllBoard controllBoard;
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
        // cout << "event = " << event << endl;
        return controllBoard.processEvent(event);
    }
    static void Timer_CB(void *userdata) {
        MainWindow *o = (MainWindow*) userdata;
        o->redraw();
        Fl::repeat_timeout(1.0/refreshPerSecond, Timer_CB, userdata);
    }
};

int main(int argc, char *argv[]) {
    // it changes the seed of the rand method
    srand(time(NULL));
    MainWindow window;
    window.show(argc, argv);
    return Fl::run();
}