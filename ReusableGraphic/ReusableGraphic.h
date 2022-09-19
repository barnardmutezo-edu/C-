
#ifndef PG400_EKSAMEN_REUSABLEGRAPHIC_H
#define PG400_EKSAMEN_REUSABLEGRAPHIC_H
#include <SDL_render.h>
#include "SDL_rect.h"
#include "../Position/Position.h"

class ReusableGraphic {
public:
    explicit ReusableGraphic(std::unique_ptr<Position> &pos);
    bool isActive;
    [[nodiscard]] std::unique_ptr<SDL_Rect> getPos() const;

    virtual  void reset();

    virtual void update();

    virtual void render();



protected:
    std::unique_ptr<Position> m_pos;

};


#endif //PG400_EKSAMEN_REUSABLEGRAPHIC_H
