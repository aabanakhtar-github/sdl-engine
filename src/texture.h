#pragma once
#include "SDL3/SDL.h"
#include "video.h"
#include <cstdint>
#include <string>

class Texture {
    public:
        bool init(video::Renderer& renderer, const std::string& filename); 
        ~Texture();

        std::uint32_t getWidth() const { return width; }
        std::uint32_t getHeight() const { return height; }
    public:
        SDL_Texture* texture = nullptr;

    private:
        std::uint32_t width, height;
};