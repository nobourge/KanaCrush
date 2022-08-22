#include "Vboard.h"

DisplayBoard::DisplayBoard(const shared_ptr<const Board> board): board{board} {};

void DisplayBoard::draw() const
{
    for (auto &c:cells) c.draw();
}

void VBoard::draw() {

}
