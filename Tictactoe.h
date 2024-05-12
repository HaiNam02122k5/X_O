#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "defs.h"

#include <SDL.h>

struct Tictactoe
{
    int board[BOARD_SIZE][BOARD_SIZE]={};
    int nextMove = O_CELL;

    void init();
    void move(int ROWs, int COLs);
    //void print();
    int check(const int x, const int y);
};

#endif // TICTACTOE_H
