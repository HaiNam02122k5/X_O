#include "click.h"
#include "Graphics.h"
#include "defs.h"

#include <bits/stdc++.h>
#include <SDL.h>

using namespace std;

void processClick(int x, int y, Tictactoe& game, int& count, Sound sGame, Mix_Chunk* gSound, bool hSound) {
    // chuyển tọa độ màn hình x, y thành tọa độ hàng cột của game
    int clickedCol = (x - BOARD_X) / CELL_SIZE;
    int clickedRow = (y - BOARD_Y) / CELL_SIZE;
    if(game.board[clickedRow][clickedCol]==0 and x>BOARD_X and y>BOARD_Y and x<BOARD_X+90 and y<BOARD_Y+90){
        game.move(clickedRow, clickedCol);
        sGame.playSound(gSound, hSound);
        count ++;
    }

}

void clickMouse(Tictactoe& game, Graphics& graphic, int &kq, Button BackSet, Sound sGame, Mix_Chunk* gSound, bool hSound)
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
                //sGame.playSound(gSound, hSound);
                if(BackSet.Inside(&event)){
                    sGame.playSound(gSound, hSound);
                    count=10;
                    break;
                }
                SDL_GetMouseState(&x, &y);
                //cerr << x << " " << y << endl;
                processClick(x, y, game, count, sGame, gSound, hSound);
                graphic.render(game);
//                cerr << count << endl;
//              game.check(x,y);
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
        if(count==9){
            kq=0;
            cout << "Hoa" << endl;
            break;
        }
        if(count==10){
            kq=3;
            break;
        }
        SDL_Delay(100);
    }
}
