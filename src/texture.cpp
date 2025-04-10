#include "texture.h" 

bool Texture::init(video::Renderer& renderer, const std::string& filename) {
    auto surface = IMG_Load(filename.c_str()); 
    if (surface == nullptr) {
        return false;
    } 

    auto texture = SDL_CreateTextureFromSurface(renderer.renderer, &surface);
    if (texture == nullptr) {
        SDL_DestroySurface(surface);
        return false;
    }

    width = surface->w; 
    height = surface->h;

    SDL_DestroySurface(surface);
    return true;
}


Texture::~Texture() {
    SDL_DestroyTexture(texture);
    texture = nullptr;
}