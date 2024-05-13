#ifndef SOUND_H
#define SOUND_H

#include <SDL_mixer.h>

#include "defs.h"

struct Sound
{
    void logErrorAndExit(const char* mess, const char* error);
    void init();
    Mix_Music *loadMusic(const char* path);
    void play(Mix_Music* gMusic);
    //bool hSound(){}
};

#endif // SOUND_H
