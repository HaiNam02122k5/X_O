#include "Tictactoe.h"
#include "defs.h"

#include <bits/stdc++.h>

using namespace std;

void Tictactoe::init()
{
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++) board[i][j] = EMPTY_CELL;
}

void Tictactoe::move(int ROWs, int COLs)
{
    if (ROWs >= 0 && ROWs < BOARD_SIZE && COLs >= 0 && COLs < BOARD_SIZE)
        {
            board[ROWs][COLs] = nextMove;
            //if(nextMove==O_CELL)board[]
            nextMove = (nextMove == O_CELL) ? X_CELL : O_CELL;
        }
}

//void Tictactoe::print()
//    {
//        for(int i=0; i<BOARD_SIZE; i++){
//            for(int j=0; j<BOARD_SIZE; j++){
//                cout << board[i][j] << " ";
//            }
//            cout << endl;
//        }
//    }

int Tictactoe::check(const int x, const int y)
{
    int clc = (x - BOARD_X) / CELL_SIZE;
    int clr = (y - BOARD_Y) / CELL_SIZE;

//    for(int i=0; i<BOARD_SIZE; i++){
//        for(int j=0; j<BOARD_SIZE; j++){
//            cerr << board[i][j] << " ";
//        }
//        cerr << endl;
//    }
//    cerr << endl;

    // check cot
    if(clc>=0 and clc<3 and clr==0){
        if(board[clr][clc]==board[clr+1][clc] && board[clr][clc]==board[clr+2][clc]) return board[clr+1][clc];
    }
    if(clc>=0 and clc<3 and clr==1){
        if(board[clr][clc]==board[clr+1][clc] && board[clr][clc]==board[clr-1][clc]) return board[clr+1][clc];
    }
    if(clc>=0 and clc<3 and clr==2){
        if(board[clr][clc]==board[clr-1][clc] && board[clr][clc]==board[clr-2][clc]) return board[clr-1][clc];
    }

    //check hang
    if(clr>=0 and clr<3 and clc==0){
        if(board[clr][clc]==board[clr][clc+1] && board[clr][clc]==board[clr][clc+2]) return board[clr][clc];
    }
    if(clr>=0 and clr<3 and clc==1){
        if(board[clr][clc]==board[clr][clc+1] && board[clr][clc]==board[clr][clc-1]) return board[clr][clc];
    }
    if(clr>=0 and clr<3 and clc==2){
        if(board[clr][clc]==board[clr][clc-1] && board[clr][clc]==board[clr][clc-2]) return board[clr][clc];
    }

    // check cheo
    if(clr==0 and clc==0){
        if(board[clr][clc]==board[clr+1][clc+1] && board[clr][clc]==board[clr+2][clc+2]) return board[clr][clc];
    }
    if(clr==0 and clc==2){
        if(board[clr][clc]==board[clr+1][clc-1] && board[clr][clc]==board[clr+2][clc-2]) return board[clr][clc];
    }
    if(clr==1 and clc==1){
        if(board[clr][clc]==board[clr-1][clc-1] && board[clr][clc]==board[clr+1][clc+1]) return board[clr][clc];
        if(board[clr][clc]==board[clr-1][clc+1] && board[clr][clc]==board[clr+1][clc-1]) return board[clr][clc];
    }
    if(clr==2 and clc==0){
        if(board[clr][clc]==board[clr-1][clc+1] && board[clr][clc]==board[clr-2][clc+2]) return board[clr][clc];
    }
    if(clr==2 and clc==2){
        if(board[clr][clc]==board[clr-1][clc-1] && board[clr][clc]==board[clr-2][clc-2]) return board[clr][clc];
    }

    return 0;
}
