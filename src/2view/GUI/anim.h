#ifndef SRC_ANIM_H
#define SRC_ANIM_H

/*--------------------------------------------------
Animation class
--------------------------------------------------*/
class Anim: public Sketchable {
protected:
    shared_ptr<Sketchable> toAnim;
public:
    Animation(shared_ptr<Sketchable> toAnim)
            : toAnim{toAnim} {}
    virtual bool isComplete() =0;
    virtual void start(int direction, char directionText, Fl_Color newFillColor) {
        shared_ptr<Anim> a = dynamic_pointer_cast<Anim>(toAnim);
        if (a) a->start(1, 'V', FL_BLACK);
    };
    bool contains(Point p);
    Point getCenter();
    Fl_Color getColor(Point mouseLoc);
    void setFillColor(Fl_Color newFillColor);
};

/*--------------------------------------------------
Translation Class
--------------------------------------------------*/
struct Translation {
    Translation(Point p, char directionText) {
        fl_push_matrix();
        if (directionText == 'V')
            fl_translate(p.x, p.y);
        else if (directionText == 'H')
            fl_translate(p.y, p.x);
    }
    ~Translation() {
        fl_pop_matrix();
    }
};

#endif //SRC_ANIM_H
