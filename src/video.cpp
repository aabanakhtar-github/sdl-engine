#include "video.h"
#include "texture.h"
#include "SDL3_image/SDL_image.h"

namespace video {
    bool Texture::init(Renderer& renderer, const std::string& filename) {
        auto surface = IMG_Load(filename.c_str()); 
        if (surface == nullptr) {
            return false;
        } 

        auto texture = SDL_CreateTextureFromSurface(renderer.renderer, surface);
        if (texture == nullptr) {
            SDL_DestroySurface(surface);
            return false;
        }

        width = surface->w; 
        height = surface->h;
        this->texture = texture;

        SDL_DestroySurface(surface);
        return true;
    }


    Texture::~Texture() {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }

    bool Window::init(std::uint32_t w, std::uint32_t h, const std::string& name) {
        window = SDL_CreateWindow(name.data(), w, h, 0);
        return window != nullptr;
    }

    Window::~Window() { 
        SDL_DestroyWindow(window);
        window = nullptr;
    }

    Renderer::Renderer(Window& window) 
        : surface(window)
    {}

    Renderer::~Renderer() {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }

    bool Renderer::init() {
        renderer = SDL_CreateRenderer(surface.window, nullptr);
        if (renderer == nullptr) {
            return false;
        }

        return true;
    }

    void Renderer::drawTexture(Texture& texture, Rect& source, Rect& target, double angle) {
        SDL_RenderTextureRotated(
            renderer,
            texture.texture, 
            &source,
            &target, 
            angle, 
            nullptr,
            SDL_FLIP_NONE
        );
    }

    void Renderer::clear(const Color& color) {
        auto bytes = color.toBytes();
        SDL_SetRenderDrawColor(renderer, bytes[0], bytes[1], bytes[2], bytes[3]);
        SDL_RenderClear(renderer);
    }
}