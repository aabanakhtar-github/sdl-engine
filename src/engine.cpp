#include "engine.h"
#include "SDL3/SDL.h"
#include "SDL3_image/SDL_image.h"
#include <stdexcept>
#include <iostream>

bool core::init()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        std::cerr << "Couldn't initialize SDL graphics! " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

void core::quit()
{
    SDL_Quit();
}
