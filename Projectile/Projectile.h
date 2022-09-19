
#ifndef PG400_EKSAMEN_PROJECTILE_H
#define PG400_EKSAMEN_PROJECTILE_H

#include <SDL_render.h>
#include "SDL_rect.h"
#include "../Position/Position.h"
#include "../ReusableGraphic/ReusableGraphic.h"
#include "../SDLWrapper/Sound/Sound.h"

class Projectile : public ReusableGraphic {
public:
    explicit Projectile(std::unique_ptr<Position> &pos, std::unique_ptr<Sound> &sound, const int &dir);

    void update() override;

    void render() override;

    void fire(SDL_Rect &pos);

    bool allreadyFired;
    int m_dir;
    void reset() override;

private:
    std::unique_ptr<Sound> m_sound;


};


#endif //PG400_EKSAMEN_PROJECTILE_H
