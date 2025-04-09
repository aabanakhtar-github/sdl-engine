#include "texture.h" 

bool Texture::init() {
    return false;
}

Texture::~Texture() {
    SDL_DestroyTexture(texture);
    texture = nullptr;
}