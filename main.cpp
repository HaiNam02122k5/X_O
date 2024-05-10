#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>

#include "defs.h"
#include "Graphics.h"
#include "Tictactoe.h"
#include "click.h"

using namespace std;

void waitPressed()
{
    SDL_Event e;
    while(true){
        if(SDL_PollEvent(&e) and (e.type == SDL_KEYDOWN or e.type == SDL_QUIT)) return;
        SDL_Delay(100);
    }
}

int main(int argc, char* argv[])
{
    Graphics graphic;
    graphic.initTexture();

    Tictactoe game;
    game.init();
    graphic.render(game);
    //game.print();

    clickMouse(game, graphic);

    waitPressed();

    graphic.quitSDL();


    return 0;
}
