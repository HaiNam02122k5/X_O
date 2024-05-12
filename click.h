#ifndef CLICK_H
#define CLICK_H

#include "Tictactoe.h"
#include "defs.h"
#include "Graphics.h"

void processClick(int x, int y, Tictactoe& game);
void clickMouse(Tictactoe& game, Graphics& graphic, int &kq);

#endif // CLICK_H
