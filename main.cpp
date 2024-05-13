#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "defs.h"
#include "Graphics.h"
#include "Tictactoe.h"
#include "click.h"
#include "Sound.h"
#include "XAndO.h"
#include "click1.h"

using namespace std;

Button PlayButton(PLAY_BUTTON_X, PLAY_BUTTON_Y, BUTTON_HE, BUTTON_W);
Button CreditButton(CREDIT_BUTTON_X, CREDIT_BUTTON_Y, BUTTON_HE, BUTTON_W);
Button SettingButton(SETTING_BUTTON_X, SETTING_BUTTON_Y, BUTTON_HE, BUTTON_W);
Button QuitButton(QUIT_BUTTON_X, QUIT_BUTTON_Y, BUTTON_HE, BUTTON_W);

Button BackButton(BACK_BUTTON_X, BACK_BUTTON_Y, BUTTON_HE, BUTTON_W);
Button AgainButton(AGAIN_BUTTON_X, AGAIN_BUTTON_Y, BUTTON_HE, BUTTON_W);

Button BackSetButton(10, 10, BUTTON_HE, BUTTON_W);
Button MusicButton(230, 320,SMALL_BUTTON_H, SMALL_BUTTON_W);
Button SoundButton(320, 320,SMALL_BUTTON_H, SMALL_BUTTON_W);
Button nMusicButton(230, 320,SMALL_BUTTON_H, SMALL_BUTTON_W);
Button nSoundButton(320, 320,SMALL_BUTTON_H, SMALL_BUTTON_W);
Button ChangeButton(255, 410, BUTTON_HE, BUTTON_W);
Button nChangeButton(255, 410, BUTTON_HE, BUTTON_W);

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

    Sound sGame;
    sGame.init();
    Mix_Music* gMusic = sGame.loadMusic("GameMusic.mp3");
    sGame.play(gMusic);

    bool quitGame = false;
    bool quitMenu = false;
    bool play = false;
    bool play1 = false;
    bool setting = false;
    bool hMusic = true;
    bool tmp=true;
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
                            if(tmp==true){
                                play=true;
                                play1=false;
                                quitMenu=true;
                            }else{
                                play=false;
                                play1 = true;
                                quitMenu=true;
                            }
                            break;
                        }
                        if(CreditButton.Inside(&e)){

                        }
                        if(SettingButton.Inside(&e)){
                            setting=true;
                            quitMenu=true;
                            play=false;
                            play1=false;
                            break;
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

            clickMouse(game, graphic, kq, BackSetButton);
            //cout << kq << endl;
            if(kq==3){
                quitMenu = false;
                quitGame = false;
                break;
            }else{
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

        while(play1){
            int kq=0;
            XAndO game;
            game.init();
            graphic.render1(game);
            graphic.renderTexture(graphic.BackSetBut, BackSetButton.posx, BackSetButton.posy);
            graphic.presentScene();
            //game.print();

            clickMouse1(game, graphic, kq, BackSetButton);
            //cout << kq << endl;
            if(kq==3){
                quitMenu = false;
                quitGame = false;
                break;
            }
        }

        if(setting){
            graphic.gSetting(BackSetButton,SoundButton,MusicButton, ChangeButton, nChangeButton, tmp);
            SDL_Event e;
            while(true){
                int x=0;
                SDL_PollEvent(&e);
                switch(e.type){
                    case SDL_QUIT:
                        exit(0);
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        if(BackSetButton.Inside(&e)){
                            //cerr << "trong" << endl;
                            quitMenu = false;
                            quitGame = false;
                            setting = false;
                            x=1;
                            break;
                        }
                        if(MusicButton.Inside(&e)){
                            if(hMusic==true){
                                graphic.renderTexture(graphic.nMusicBut, nMusicButton.posx, nMusicButton.posy);
                                graphic.presentScene();
                                Mix_PauseMusic();
                                hMusic = false;
                            }else{
                                graphic.renderTexture(graphic.MusicBut, MusicButton.posx, MusicButton.posy);
                                graphic.presentScene();
                                Mix_ResumeMusic();
                                hMusic = true;
                            }
                        }
                        if(ChangeButton.Inside(&e)){
                            if(tmp==true){
                                graphic.renderTexture(graphic.nChangeBut, nChangeButton.posx, nChangeButton.posy);
                                graphic.presentScene();
                                tmp = false;
                            }else if(tmp==false){
                                graphic.renderTexture(graphic.ChangeBut, ChangeButton.posx, ChangeButton.posy);
                                graphic.presentScene();
                                tmp = true;
                            }
                        }
                        break;
                }
                if(x==1) break;
            }
        }
    }

    if (gMusic != nullptr) Mix_FreeMusic( gMusic );
    sGame.quit();
    graphic.quitSDL();


    return 0;
}
