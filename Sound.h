#ifndef SOUND_H
#define SOUND_H

#include <SDL_mixer.h>

#include "defs.h"

struct Sound
{
    void logErrorAndExit(const char* mess, const char* error);
    void init();
    Mix_Music *loadMusic(const char* path);
    void playMusic(Mix_Music* gMusic);
    Mix_Chunk* loadSound(const char* path);
    void playSound(Mix_Chunk* gChunk, bool hSound);
    void quit();
};

#endif // SOUND_H
