#include "engine.h"
#include "SDL3/SDL.h"
#include <stdexcept>

void core::init() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
    }
}

void core::quit() {
    SDL_Quit();
}