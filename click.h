#ifndef CLICK_H
#define CLICK_H

#include "Tictactoe.h"
#include "defs.h"
#include "Graphics.h"
#include "Sound.h"

void processClick(int x, int y, Tictactoe& game, Sound sGame, Mix_Chunk* gSound, bool hSound);
void clickMouse(Tictactoe& game, Graphics& graphic, int &kq, Button BackSet, Sound sGame, Mix_Chunk* gSound, bool hSound);

#endif // CLICK_H
