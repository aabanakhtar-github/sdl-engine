#pragma once
#include "SDL3/SDL.h"
#include <cstdint>

class Texture {
    public:
        bool init(); 
        ~Texture();

        std::uint32_t getWidth() const { return width; }
        std::uint32_t getHeight() const { return height; }
    public:
        SDL_Texture* texture;

    private:
        std::uint32_t width, height;
};