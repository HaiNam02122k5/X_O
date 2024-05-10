#include "click.h"
#include "Graphics.h"

#include <bits/stdc++.h>
#include <SDL.h>

using namespace std;

void processClick(int x, int y, Tictactoe& game) {
    // chuyển tọa độ màn hình x, y thành tọa độ hàng cột của game
    int clickedCol = (x - BOARD_X) / CELL_SIZE;
    int clickedRow = (y - BOARD_Y) / CELL_SIZE;
    if(game.board[clickedRow][clickedCol]==0)
        game.move(clickedRow, clickedCol);
}

void clickMouse(Tictactoe& game, Graphics& graphic)
{
    SDL_Event event;
    int x, y;
    while (true) {
        SDL_PollEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_MOUSEBUTTONDOWN:
                SDL_GetMouseState(&x, &y);
                cerr << x << " " << y << endl;
                processClick(x, y, game);
                graphic.render(game);
//              game.check(x,y);
                break;
        }
        if(game.check(x,y)==1){
            cout << "O Win" << endl;
            break;
        }
        if(game.check(x,y)==2){
            cout << "X Win" << endl;
            break;
        }
        SDL_Delay(100);
    }
}
