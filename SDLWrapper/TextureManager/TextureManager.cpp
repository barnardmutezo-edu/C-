
#include "TextureManager.h"

SDL_Texture *TextureManager::loadTexture(SDL_Surface *surface) {
    SDL_Texture *texture = SDL_CreateTextureFromSurface(SDLWrapper::renderer, surface);



    return texture;
}

SDL_Surface *TextureManager::getSurface(const std::string &filename) {
    SDL_Surface *surface = IMG_Load(filename.c_str());

    if (!surface){
        SDL_Quit();
    }
    return surface;
}

