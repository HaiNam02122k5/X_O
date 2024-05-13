#ifndef X_AND_O__H
#define X_AND_O__H

#include "defs.h"

#include <SDL.h>

struct XAndO
{
    int board[BOARD_SIZER][BOARD_SIZEC]={};
    int nextMove = O_CELL;

    void init();
    void move(int ROWs, int COLs);
    //void print();
    //int check(const int x, const int y);
};

#endif // TICTACTOE_H
