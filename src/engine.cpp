#include "engine.h"
#include "SDL3/SDL.h"
#include <stdexcept>
#include <iostream>

void core::init() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        std::cerr << "Couldn't initialize SDL graphics! " << SDL_GetError() << std::endl;
    }

    if (IMG_Init(IMG_INIT_PNG) != 0) {
        std::cerr << "Failed to initialize SDL image loader! " << IMG_GetError() << std::endl;
    }
}

void core::quit() {
    SDL_Quit();
    IMG_Quit();
}