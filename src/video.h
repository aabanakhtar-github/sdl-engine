#pragma once

#include "SDL3/SDL.h"
#include <string>
#include <cstdint>
#include <vector>

namespace video
{
    using Rect = SDL_FRect;

    struct Renderer;

    struct Color
    {
        float r, g, b, a;

        [[nodiscard]] std::vector<std::uint8_t> toBytes() const
        {
            return {
                static_cast<std::uint8_t>(r),
                static_cast<std::uint8_t>(g),
                static_cast<std::uint8_t>(b),
                static_cast<std::uint8_t>(a)
            };
        }
    };

    class Texture
    {
    public:
        bool init(Renderer& renderer, const std::string& filename);
        ~Texture();

        [[nodiscard]] std::uint32_t getWidth() const { return width; }
        [[nodiscard]] std::uint32_t getHeight() const { return height; }

    public:
        SDL_Texture* texture = nullptr;

    private:
        std::uint32_t width = 0, height = 0;
    };

    struct Window
    {
        SDL_Window* window = nullptr;

        bool init(std::uint32_t w, std::uint32_t h, const std::string& name);
        ~Window();
    };


    struct Renderer
    {
        Window& surface;
        SDL_Renderer* renderer = nullptr;

        explicit Renderer(Window& window);
        ~Renderer();

        bool init();
        void drawTexture(const Texture& texture, const Rect& source, const Rect& target, double angle = 0) const;
        void clear(const Color& color = Color{0.0, 0.0, 0.0, 0.0}) const;

        void present() const { SDL_RenderPresent(renderer); }
    };
}
