#include "Button.h"

bool Button::Inside(SDL_Event* e){
    int x, y;
    SDL_GetMouseState(&x, &y);
    if(x>posx and x<posx+w and y>posy and y<posy+h) return true;
    return false;
}
