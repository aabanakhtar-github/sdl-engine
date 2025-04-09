#include "video.h"
#include "texture.h"

using namespace video;

bool video::Window::init(std::uint32_t w, std::uint32_t h, const std::string& name) {
    window = SDL_CreateWindow(name.data(), w, h, 0);
    return window != nullptr;
}

video::Window::~Window() { 
    SDL_DestroyWindow(window);
    window = nullptr;
}

video::Renderer::Renderer(Window& window) 
    : surface(window)
{}

video::Renderer::~Renderer() {
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
}

bool video::Renderer::init() {
    renderer = SDL_CreateRenderer(surface.window, nullptr);
    if (renderer == nullptr) {
        return false;
    }

    return true;
}

void video::Renderer::drawTexture(Texture& texture, Rect& source, Rect& target, double angle) {
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

void video::Renderer::clear() {
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}
