#include "click1.h"
#include "Graphics.h"
#include "defs.h"

#include <bits/stdc++.h>
#include <SDL.h>

using namespace std;

void processClick1(int x, int y, XAndO& game, int& count, Sound sGame, Mix_Chunk* gSound, bool hSound) {
    // chuyển tọa độ màn hình x, y thành tọa độ hàng cột của game
    int clickedCol = (x - BOARD_X1) / CELL_SIZE;
    int clickedRow = (y - BOARD_Y1) / CELL_SIZE;
    if(game.board[clickedRow][clickedCol]==0 and x>BOARD_X1 and y>BOARD_Y1 and (x<BOARD_X1+BOARD_SIZEC*CELL_SIZE) and (y<BOARD_Y1+BOARD_SIZER*CELL_SIZE)){
        game.move(clickedRow, clickedCol);
        sGame.playSound(gSound, hSound);
        count ++;
    }
}

void clickMouse1(XAndO& game, Graphics& graphic, int &kq, Button BackSet, Sound sGame, Mix_Chunk* gSound, bool hSound)
{
    int count=0;
    SDL_Event event;
    int x, y;
    while (true) {
        SDL_PollEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_MOUSEBUTTONDOWN:
                if(BackSet.Inside(&event)){
                    sGame.playSound(gSound, hSound);
                    count=1000;
                    break;
                }
                SDL_GetMouseState(&x, &y);
                //cerr << x << " " << y << endl;
                processClick1(x, y, game, count, sGame, gSound, hSound);
                graphic.render1(game);
                break;
        }
        if(game.check(x,y)==1){
            cout << "O Win" << endl;
            kq=1;
            break;
        }
        if(game.check(x,y)==2){
            cout << "X Win" << endl;
            kq=2;
            break;
        }
        if(count==BOARD_SIZEC*BOARD_SIZER){
            kq=0;
            cout << "Hoa" << endl;
            break;
        }
        if(count==1000){
            kq=3;
            break;
        }
        //SDL_Delay(50);
    }
}
