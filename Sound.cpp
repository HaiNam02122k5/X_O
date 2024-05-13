#include "Sound.h"
#include "defs.h"

#include <SDL.h>
#include <SDL_mixer.h>

void Sound::init(){
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) {
       logErrorAndExit( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
    }
}

void Sound::logErrorAndExit(const char* mess, const char* error)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", mess, error);
    SDL_Quit();
}

Mix_Music* Sound::loadMusic(const char* path)
{
    Mix_Music *gMusic = Mix_LoadMUS(path);
    if (gMusic == nullptr) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Could not load music! SDL_mixer Error: %s", Mix_GetError());
    }
    return gMusic;
}

void Sound::playMusic(Mix_Music* gMusic)
{
    if (gMusic == nullptr) return;

    if (Mix_PlayingMusic() == 0) {
        Mix_PlayMusic( gMusic, -1 );
    }
    else if( Mix_PausedMusic() == 1 ) {
        Mix_ResumeMusic();
    }
}

Mix_Chunk* Sound::loadSound(const char* path) {
    Mix_Chunk* gChunk = Mix_LoadWAV(path);
        if (gChunk == nullptr) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
            "Could not load sound! SDL_mixer Error: %s", Mix_GetError());
    }
}
void Sound::playSound(Mix_Chunk* gChunk, bool hSound) {
    if (gChunk != nullptr) {
        if(hSound==true) Mix_PlayChannel( -1, gChunk, 0 );
        else Mix_Pause(-1);
    }
}


void Sound::quit(){
    Mix_Quit();
}


