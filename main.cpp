#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>

#include "defs.h"
#include "Graphics.h"
#include "Tictactoe.h"
#include "click.h"

using namespace std;

Button PlayButton(PLAY_BUTTON_X, PLAY_BUTTON_Y, BUTTON_HE, BUTTON_W);
Button CreditButton(CREDIT_BUTTON_X, CREDIT_BUTTON_Y, BUTTON_HE, BUTTON_W);
Button SettingButton(SETTING_BUTTON_X, SETTING_BUTTON_Y, BUTTON_HE, BUTTON_W);
Button QuitButton(QUIT_BUTTON_X, QUIT_BUTTON_Y, BUTTON_HE, BUTTON_W);

Button BackButton(BACK_BUTTON_X, BACK_BUTTON_Y, BUTTON_HE, BUTTON_W);
Button AgainButton(AGAIN_BUTTON_X, AGAIN_BUTTON_Y, BUTTON_HE, BUTTON_W);

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
    //graphic.initSDL();

    bool quitGame = false;
    bool quitMenu = false;
    bool play = false;
    while(!quitGame){
        //quitGame = true;
        while(!quitMenu){
            graphic.menu(PlayButton, CreditButton, SettingButton, QuitButton);
            SDL_Event e;
            while(SDL_PollEvent(&e)!=0){
                switch(e.type){
                    case SDL_QUIT:
                        quitMenu=true;
                        exit(0);
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        if(PlayButton.Inside(&e)){
                            //cerr << "trong" << endl;
                            play=true;
                            quitMenu=true;
                            break;
                        }
                        if(CreditButton.Inside(&e)){

                        }
                        if(SettingButton.Inside(&e)){

                        }
                        if(QuitButton.Inside(&e)) exit(0);
                }

            }
        }

        while(play){
            int kq=0;
            Tictactoe game;
            game.init();
            graphic.backgroundGame(game);
            graphic.render(game);
            //game.print();

            clickMouse(game, graphic, kq);
            //cout << kq << endl;
            graphic.winGame(kq, AgainButton, BackButton);

            play=false;
            SDL_Event e;
            while(true){
                int x=0;
                SDL_PollEvent(&e);
                switch(e.type){
                    case SDL_QUIT:
                        exit(0);
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        if(BackButton.Inside(&e)){
                            //cerr << "trong" << endl;
                            quitMenu = false;
                            quitGame = false;
                            x=1;
                            break;
                        }
                        if(AgainButton.Inside(&e)){
                            play = true;
                            quitGame = true;
                            x=2;
                            break;
                        }
                }
                if(x==1) break;
                if(x==2) break;
            }
        }
    }


    waitPressed();

    graphic.quitSDL();


    return 0;
}
