#include "Graphics.h"

#include <SDL.h>
#include <SDL_image.h>

void Graphics::logErrorAndExit(const char* mess, const char* error)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", mess, error);
    SDL_Quit();
}

void Graphics::initSDL()
{
    if(SDL_Init(SDL_INIT_EVERYTHING)!=0) logErrorAndExit("SDL_Init", SDL_GetError());
    window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

    if(window == nullptr) logErrorAndExit("CreateWindow", SDL_GetError());
    if(!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG)) logErrorAndExit("IMG_Init", SDL_GetError());


    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(renderer == nullptr) logErrorAndExit("CreateRenderer", SDL_GetError());
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, WIDTH, HEIGHT);
}

 void Graphics::prepareScene(SDL_Texture * background)
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy( renderer, background, NULL, NULL);
}

void Graphics::presentScene()
{
    SDL_RenderPresent(renderer);
}


SDL_Texture* Graphics::loadTexture(const char* filename)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

    SDL_Texture* texture = IMG_LoadTexture(renderer, filename);
    if(texture == NULL){
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Loading texture %s", IMG_GetError());
    }

    return texture;
}

void Graphics::renderTexture(SDL_Texture* texture, int x, int y)
{
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(renderer, texture, NULL, &dest);
}

void Graphics::quitSDL()
{
    SDL_DestroyTexture(cell);
    cell = nullptr;
    SDL_DestroyTexture(cellX);
    cellX = nullptr;
    SDL_DestroyTexture(cellO);
    cellO = nullptr;

    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
}

void Graphics::initTexture()
{
    initSDL();
    cell = loadTexture("cell_empty.png");
    cellX = loadTexture("cell_X.png");
    cellO = loadTexture("cell_O.png");
}

void Graphics::render(const Tictactoe& game)
{
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++) {
            int x = BOARD_X + j * CELL_SIZE;
            int y = BOARD_Y + i * CELL_SIZE;
            switch (game.board[i][j]) {
                case EMPTY_CELL: renderTexture(cell, x, y); break;
                case X_CELL: renderTexture(cellX, x, y); break;
                case O_CELL: renderTexture(cellO, x, y); break;
            };
        };

//    renderTexture(cell, 10, 10);
//    renderTexture(cellX, 110, 10);
//    renderTexture(cellO, 210,10);

    presentScene();
}
