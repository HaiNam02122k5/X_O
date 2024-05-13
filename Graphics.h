#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL.h>
#include <SDL_image.h>

#include "defs.h"
#include "Tictactoe.h"
#include "Button.h"

struct Graphics{
    SDL_Renderer *renderer;
    SDL_Window *window;
    SDL_Texture *cell, *cellX, *cellO,
                *background1, *PlayBut, *CreditBut, *SettingBut, *QuitBut, *background2,
                *BackBut, *AgainBut, *OWin, *XWin, *Qual,
                *background3, *BackSetBut, *MusicBut, *SoundBut, *nMusicBut, *nSoundBut;

    void logErrorAndExit(const char* mess, const char* error);
    void initSDL();
    void prepareScene(SDL_Texture * background);
    void presentScene();
    SDL_Texture* loadTexture(const char* filename);
    void renderTexture(SDL_Texture* texture, int x, int y);
    void quitSDL();
    void initTexture();
    void menu(Button PlayButton, Button CreditButton, Button SettingButton, Button QuitButton);
    void render(const Tictactoe& game);
    void backgroundGame(const Tictactoe& game);
    void winGame(int kq, Button AgainButton, Button BackButton);
    void gSetting(Button BackSetButton, Button SoundButton, Button MusicButton);
};

#endif // GRAPHICS_H
