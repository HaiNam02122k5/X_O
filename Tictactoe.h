#ifndef TICTACTOE_H
#define TICTACTOE_H

#define BOARD_SIZE 3
#define EMPTY_CELL 0
#define O_CELL 1
#define X_CELL 2

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
