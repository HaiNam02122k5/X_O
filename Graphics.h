#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL.h>
#include <SDL_image.h>

#include "defs.h"
#include "Tictactoe.h"

struct Graphics{
    SDL_Renderer *renderer;
    SDL_Window *window;
    SDL_Texture *cell, *cellX, *cellO;

    void logErrorAndExit(const char* mess, const char* error);
    void initSDL();
    void prepareScene(SDL_Texture * background);
    void presentScene();
    SDL_Texture* loadTexture(const char* filename);
    void renderTexture(SDL_Texture* texture, int x, int y);
    void quitSDL();
    void initTexture();
    void render(const Tictactoe& game);
};

#endif // GRAPHICS_H
