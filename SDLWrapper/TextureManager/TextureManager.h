
#ifndef PG400_EKSAMEN_TEXTUREMANAGER_H
#define PG400_EKSAMEN_TEXTUREMANAGER_H

#include "../../GameManager/GameManager.h"
#include "../SDLWrapper.h"

class TextureManager {

public:
    static SDL_Texture *loadTexture(SDL_Surface *surface);
    static SDL_Surface *getSurface(const std::string &filename);

};


#endif //PG400_EKSAMEN_TEXTUREMANAGER_H
