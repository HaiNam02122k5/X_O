#ifndef CLICK1_H
#define CLICK1_H

#include "XAndO.h"
#include "defs.h"
#include "Graphics.h"
#include "Sound.h"

void processClick1(int x, int y, XAndO& game, int& count, Sound sGame, Mix_Chunk* gSound, bool hSound);
void clickMouse1(XAndO& game, Graphics& graphic, int &kq, Button BackSet, Sound sGame, Mix_Chunk* gSound, bool hSound);

#endif // CLICK1_H
