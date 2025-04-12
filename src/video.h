#pragma once 

#include "SDL3/SDL.h"
#include <string>
#include <cstdint>
#include <vector>

#include "texture.h"

namespace video {
    using Rect = SDL_FRect;

    struct Renderer;

    struct Color {
        float r, g, b, a;

        std::vector<std::uint8_t> toBytes() const {
            return {
                static_cast<std::uint8_t>(r),
                static_cast<std::uint8_t>(g),
                static_cast<std::uint8_t>(b),
                static_cast<std::uint8_t>(a)
            };
        }
    };

    class Texture {
        public:
            bool init(Renderer& renderer, const std::string& filename); 
            ~Texture();

            std::uint32_t getWidth() const { return width; }
            std::uint32_t getHeight() const { return height; }
        public:
            SDL_Texture* texture = nullptr;

        private:
            std::uint32_t width, height;
    };

    struct Window {
        SDL_Window *window = nullptr;

        bool init(std::uint32_t w, std::uint32_t h, const std::string& name);
        ~Window();
    };


    struct Renderer { 
        Window& surface;
        SDL_Renderer* renderer = nullptr;

        Renderer(Window& window);
        ~Renderer(); 

        bool init();
        void drawTexture(Texture& t, Rect& source, Rect& destination, double angle = 0);
        void clear(const Color& color = Color{0.0, 0.0, 0.0, 0.0});
    };
}