
#ifndef PG400_EKSAMEN_BACKGROUNDPOSITION_H
#define PG400_EKSAMEN_BACKGROUNDPOSITION_H

#include "../../Position/Position.h"

class BackgroundPosition : public Position {

public:
    explicit BackgroundPosition(const char *filename);

    void render(int y, SDL_Rect* clip = nullptr, double angle = 0.0, SDL_Point* center = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE );
};


#endif //PG400_EKSAMEN_BACKGROUNDPOSITION_H
