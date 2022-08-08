//
// Created by bourg on 28-12-21.
//

#include "Vboard.h"

DisplayBoard::DisplayBoard(const shared_ptr<const Board> board): board{board} {};

void DisplayBoard::draw() const
{
    for (auto &c:cells) c.draw();
    /**
    fl_draw_box(FL_FLAT_BOX, 0, 50, 2000, 2000, FL_BLUE);
    for (int x=0; x<Board::columns; x++)
        for (int y=0; y<Board::rows; y++)
        {
            //Cell current_cell
            switch (board->getSquareType(y, x))
            {
                case Board::Red:
                    fl_color(FL_RED);
                    break;
                case Board::Black:
                    fl_color(FL_BLACK);
                    break;
                default:
                    fl_color(FL_WHITE);
                    break;
            }
            fl_begin_polygon();
            //fl_circle(50*x+25, 50*y+75, 21);
            current_cell.draw();
            fl_end_polygon();
        }

    string message;
    switch (board->getGameState())
    {
        case Board::Play:
            message="Play";
            fl_color(FL_RED);
            break;
        case Board::Crush:
            message="Crush";
            fl_color(FL_BLACK);
            break;

        case Board::Win:
            message="Win!";
            fl_color(FL_BLACK);
            break;
    }
    fl_font(FL_HELVETICA, 20);
    int width{0}, height{0};
    fl_measure(message.c_str(), width, height, false);
    fl_draw(message.c_str(), 175-width/2, 30);
    */
}

void VBoard::draw() {

}
