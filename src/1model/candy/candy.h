//
// Created by bourg on 20-12-21.
//

#ifndef KANACRUSH_CANDY_H
#define KANACRUSH_CANDY_H

class Candy {

public:
    Candy(int i, int j);
    Candy(const Candy &other);
    Candy(int type);

    void setCandy(int type);
    int getCandy();
    void setRow(int row);
    int getRow();
    void setCol(int col);
    int getCol();

private:
    int row, col, type;

};
#endif //KANACRUSH_CANDY_H
