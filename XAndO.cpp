#include "XAndO.h"
#include "defs.h"

#include <bits/stdc++.h>

using namespace std;

void XAndO::init()
{
    for (int i = 0; i < BOARD_SIZER; i++)
        for (int j = 0; j < BOARD_SIZEC; j++) board[i][j] = EMPTY_CELL;
}

void XAndO::move(int ROWs, int COLs)
{
    if (ROWs >= 0 && ROWs < BOARD_SIZER && COLs >= 0 && COLs < BOARD_SIZEC)
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

int XAndO::check(const int x, const int y)
{
    int clc = (x - BOARD_X1) / CELL_SIZE;
    int clr = (y - BOARD_Y1) / CELL_SIZE;

    // check cheo1
    int cntcheo1=1;
    for(int i=1; i<5; i++){
        if((clr+i>BOARD_SIZER) || (clc+i>BOARD_SIZEC) || (clr-i<0) || (clc-i<0)
            || board[clr][clc] != board[clr+i][clc+i]
            || cntcheo1>=5) break;
        else if(board[clr][clc]==board[clr+i][clc+i]){
            cntcheo1++;
        }
    }
    for(int i=1; i<5; i++){
        if((clr-i<0) || (clc-i<0) || (clr+i>BOARD_SIZER) || (clc+i>BOARD_SIZEC)) break;
        else if(board[clr][clc] != board[clr-i][clc-i]
            || cntcheo1>=5) break;
        else if(board[clr][clc]==board[clr-i][clc-i]){
            cntcheo1++;
        }
    }
    if(cntcheo1>=5) return board[clr][clc];

    // check cheo2
    int cntcheo2=1;
    for(int i=1; i<5; i++){
        if((clr-i<0) || (clc-i<0) || (clr+i>BOARD_SIZER) || (clc+i>BOARD_SIZEC)) break;
        else if(board[clr][clc] != board[clr-i][clc+i]
            || cntcheo2>=5) break;
        else if(board[clr][clc]==board[clr-i][clc+i]){
            cntcheo2++;
        }
    }
    for(int i=1; i<5; i++){
        if((clr-i<0) || (clc-i<0) || (clr+i>BOARD_SIZER) || (clc+i>BOARD_SIZEC)) break;
        else if(board[clr][clc] != board[clr+i][clc-i]
            || cntcheo2>=5) break;
        else if(board[clr][clc]==board[clr+i][clc-i]){
            cntcheo2++;
        }
    }
    if(cntcheo2>=5) return board[clr][clc];

    // check cot
    int cntcot=1;
    for(int i=1; i<5; i++){
        if((clr-i<0) || (clc-i<0) || (clr+i>BOARD_SIZER) || (clc+i>BOARD_SIZEC)) break;
        else if(board[clr][clc] != board[clr-i][clc]
            || cntcot>=5) break;
        else if(board[clr][clc]==board[clr-i][clc]){
            cntcot++;
        }
    }
    for(int i=1; i<5; i++){
        if((clr-i<0) || (clc-i<0) || (clr+i>BOARD_SIZER) || (clc+i>BOARD_SIZEC)) break;
        else if(board[clr][clc] != board[clr+i][clc]
            || cntcot>=5) break;
        else if(board[clr][clc]==board[clr+i][clc]){
            cntcot++;
        }
    }
    if(cntcot>=5) return board[clr][clc];

    //check hang
    int cnthang=1;
    for(int i=1; i<5; i++){
        if((clr-i<0) || (clc-i<0) || (clr+i>BOARD_SIZER) || (clc+i>BOARD_SIZEC)) break;
        else if(board[clr][clc] != board[clr][clc+i]
            || cnthang>=5) break;
        else if(board[clr][clc]==board[clr][clc+i]){
            cnthang++;
        }
    }
    for(int i=1; i<5; i++){
        if((clr-i<0) || (clc-i<0) || (clr+i>BOARD_SIZER) || (clc+i>BOARD_SIZEC)) break;
        else if(board[clr][clc] != board[clr][clc-i]
            || cnthang>=5) break;
        else if(board[clr][clc]==board[clr][clc-i]){
            cnthang++;
        }
    }
    if(cnthang>=5) return board[clr][clc];

    return 0;
}

