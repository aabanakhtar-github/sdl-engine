#pragma once

#include "SDL3/SDL.h"
#include <string>
#include <cstdint>
#include <optional>
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
        explicit Texture(Renderer& renderer) : renderer(renderer) {}
        Texture(const Texture& texture);
        Texture& operator=(Texture texture);
        Texture(Texture&& texture) noexcept;
        Texture& operator=(Texture&& texture) noexcept;

        bool init(Renderer &renderer, const std::string& path);
        [[nodiscard]] std::optional<Texture> clone() const;

        ~Texture();

        [[nodiscard]] std::uint32_t getWidth() const { return width; }
        [[nodiscard]] std::uint32_t getHeight() const { return height; }

        friend void swap(Texture& a, Texture& b) noexcept
        {
            using std::swap;
            swap(a.width, b.width);
            swap(a.height, b.height);
            swap(a.texture, b.texture);
        }

    public:
        SDL_Texture* texture = nullptr;
        Renderer& renderer;
    private:
        std::uint32_t width = 0, height = 0;
    };

    class Window
    {
    public:
        SDL_Window* window = nullptr;
        
        bool init(std::uint32_t w, std::uint32_t h, const std::string& name);
        ~Window();

        [[nodiscard]] std::uint32_t getWidth() const { return w; }
        [[nodiscard]] std::uint32_t getHeight() const { return h; }
    
    private:
        std::uint32_t w = 0, h = 0;
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
