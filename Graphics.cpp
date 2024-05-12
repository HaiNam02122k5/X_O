#include "Graphics.h"
#include "Button.h"

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

    SDL_DestroyTexture(background1);
    background1 = nullptr;
    SDL_DestroyTexture(PlayBut);
    PlayBut = nullptr;
    SDL_DestroyTexture(CreditBut);
    CreditBut = nullptr;
    SDL_DestroyTexture(SettingBut);
    SettingBut = nullptr;
    SDL_DestroyTexture(QuitBut);
    QuitBut = nullptr;
    SDL_DestroyTexture(background2);
    background2 = nullptr;

    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
}

void Graphics::initTexture()
{
    initSDL();
    cell = loadTexture("img\\cell_empty.png");
    cellX = loadTexture("img\\cell_X.png");
    cellO = loadTexture("img\\cell_O.png");

    background1 = loadTexture("img\\background1.png");
    PlayBut = loadTexture("img\\Button\\PlayButton1.png");
    CreditBut = loadTexture("img\\Button\\CreditButton1.png");
    SettingBut = loadTexture("img\\Button\\SettingButton1.png");
    QuitBut = loadTexture("img\\Button\\QuitButton1.png");
    background2 = loadTexture("img\\background.png");

    BackBut = loadTexture("img\\Button\\Button.png");
    AgainBut = loadTexture("img\\Button\\Button.png");
    OWin = loadTexture("img\\Result\\oWin.png");
}

void Graphics::menu(Button PlayButton, Button CreditButton, Button SettingButton, Button QuitButton)
{
    renderTexture(background1,0,0);
    renderTexture(PlayBut, PlayButton.posx, PlayButton.posy);
    renderTexture(CreditBut, CreditButton.posx, CreditButton.posy);
    renderTexture(SettingBut, SettingButton.posx, SettingButton.posy);
    renderTexture(QuitBut, QuitButton.posx, QuitButton.posy);

    presentScene();
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

    //xanh
        if(game.board[0][0]==1 and game.board[0][0]==game.board[1][1] and game.board[0][0]==game.board[2][2]){
            SDL_Texture* cheo = loadTexture("img\\Tictactoe\\O\\cheo1o.png");
            renderTexture(cheo,BOARD_X,BOARD_Y);
        }
        if(game.board[0][2]==1 and game.board[0][2]==game.board[1][1] and game.board[0][2]==game.board[2][0]){
            SDL_Texture* cheo = loadTexture("img\\Tictactoe\\O\\cheo2o.png");
            renderTexture(cheo,BOARD_X ,BOARD_Y);
        }
        if(game.board[0][0]==1 and game.board[0][0]==game.board[0][1] and game.board[0][2]==game.board[0][1]){
            SDL_Texture* cheo = loadTexture("img\\Tictactoe\\O\\hango.png");
            renderTexture(cheo,BOARD_X,BOARD_Y-30);
        }
        if(game.board[1][0]==1 and game.board[1][0]==game.board[1][1] and game.board[1][2]==game.board[1][1]){
            SDL_Texture* cheo = loadTexture("img\\Tictactoe\\O\\hango.png");
            renderTexture(cheo,BOARD_X ,BOARD_Y);
        }
        if(game.board[2][0]==1 and game.board[2][0]==game.board[2][1] and game.board[2][2]==game.board[2][1]){
            SDL_Texture* cheo = loadTexture("img\\Tictactoe\\O\\hango.png");
            renderTexture(cheo,BOARD_X ,BOARD_Y+30);
        }
        if(game.board[0][0]==1 and game.board[1][0]==game.board[2][0] and game.board[0][0]==game.board[1][0]){
            SDL_Texture* cheo = loadTexture("img\\Tictactoe\\O\\coto.png");
            renderTexture(cheo,BOARD_X-30 ,BOARD_Y);
        }
        if(game.board[0][1]==1 and game.board[1][1]==game.board[2][1] and game.board[0][1]==game.board[1][1]){
            SDL_Texture* cheo = loadTexture("img\\Tictactoe\\O\\coto.png");
            renderTexture(cheo,BOARD_X ,BOARD_Y);
        }
        if(game.board[0][2]==1 and game.board[1][2]==game.board[2][2] and game.board[0][2]==game.board[1][2]){
            SDL_Texture* cheo = loadTexture("img\\Tictactoe\\O\\coto.png");
            renderTexture(cheo,BOARD_X+30 ,BOARD_Y);
        }

    // do
        if(game.board[0][0]==2 and game.board[0][0]==game.board[1][1] and game.board[0][0]==game.board[2][2]){
            SDL_Texture* cheo = loadTexture("img\\Tictactoe\\X\\cheo1x.png");
            renderTexture(cheo,BOARD_X,BOARD_Y);
        }
        if(game.board[0][2]==2 and game.board[0][2]==game.board[1][1] and game.board[0][2]==game.board[2][0]){
            SDL_Texture* cheo = loadTexture("img\\Tictactoe\\X\\cheo2x.png");
            renderTexture(cheo,BOARD_X ,BOARD_Y);
        }
        if(game.board[0][0]==2 and game.board[0][0]==game.board[0][1] and game.board[0][2]==game.board[0][1]){
            SDL_Texture* cheo = loadTexture("img\\Tictactoe\\X\\hangx.png");
            renderTexture(cheo,BOARD_X,BOARD_Y-30);
        }
        if(game.board[1][0]==2 and game.board[1][0]==game.board[1][1] and game.board[1][2]==game.board[1][1]){
            SDL_Texture* cheo = loadTexture("img\\Tictactoe\\X\\hangx.png");
            renderTexture(cheo,BOARD_X ,BOARD_Y);
        }
        if(game.board[2][0]==2 and game.board[2][0]==game.board[2][1] and game.board[2][2]==game.board[2][1]){
            SDL_Texture* cheo = loadTexture("img\\Tictactoe\\X\\hangx.png");
            renderTexture(cheo,BOARD_X ,BOARD_Y+30);
        }
        if(game.board[0][0]==2 and game.board[1][0]==game.board[2][0] and game.board[0][0]==game.board[1][0]){
            SDL_Texture* cheo = loadTexture("img\\Tictactoe\\X\\cotx.png");
            renderTexture(cheo,BOARD_X-30 ,BOARD_Y);
        }
        if(game.board[0][1]==2 and game.board[1][1]==game.board[2][1] and game.board[0][1]==game.board[1][1]){
            SDL_Texture* cheo = loadTexture("img\\Tictactoe\\X\\cotx.png");
            renderTexture(cheo,BOARD_X ,BOARD_Y);
        }
        if(game.board[0][2]==2 and game.board[1][2]==game.board[2][2] and game.board[0][2]==game.board[1][2]){
            SDL_Texture* cheo = loadTexture("img\\Tictactoe\\X\\cotx.png");
            renderTexture(cheo,BOARD_X+30 ,BOARD_Y);
        }

//    renderTexture(cell, 10, 10);
//    renderTexture(cellX, 110, 10);
//    renderTexture(cellO, 210,10);

    presentScene();
}

void Graphics::backgroundGame(const Tictactoe& game)
{
    renderTexture(background2,0,0);
    presentScene();
}

void Graphics::winGame(int kq, Button AgainButton, Button BackButton)
{
    if(kq==1){
        renderTexture(OWin, 225, 225);
    }
    renderTexture(BackBut, BackButton.posx, BackButton.posy);
    renderTexture(AgainBut, AgainButton.posx, AgainButton.posy);
    presentScene();
}
