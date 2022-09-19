
#include "../../SDLWrapper/TextureManager/TextureManager.h"
#include "BackgroundPosition.h"

BackgroundPosition::BackgroundPosition(const char *filename) : Position(filename, 5, 5) {

}


void BackgroundPosition::render(int const y, SDL_Rect *clip, double angle, SDL_Point *center,
                                SDL_RendererFlip flip) {
    yPos = y;
    update();
    if (clip != nullptr) {
        std::cout << "Not null" << std::endl;

        dstRect.w = clip->w;
        dstRect.h = clip->h;
    }

    SDL_RenderCopyEx(SDLWrapper::renderer, texture, clip, &dstRect, angle, center, flip);
}



