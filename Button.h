#ifndef BUTTON_H
#define BUTTON_H

#include <SDL.h>

struct Button
{
    int posx, posy, h, w;
    Button(){
    };
    Button(int _x, int _y, int _h, int _w){
        posx=_x;
        posy=_y;
        h=_h;
        w=_w;
    }
    bool Inside(SDL_Event* e);
};

#endif // BUTTON_H
