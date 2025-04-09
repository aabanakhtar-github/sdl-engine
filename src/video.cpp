#include "video.h"
#include <exception> 

bool video::Window::init(std::uint32_t w, std::uint32_t h, const std::string& name) {
    window = SDL_CreateWindow(name.data(), w, h, 0);
    return window != nullptr;
}

video::Window::~Window() { 
    SDL_DestroyWindow(window);
    window = nullptr;
}
