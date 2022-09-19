#ifndef PG400_EKSAMEN_SHIPOBJ_H
#define PG400_EKSAMEN_SHIPOBJ_H

#include "SDL.h"
#include <iostream>
#include <vector>
#include "../../Position/Position.h"
#include "../../Projectile/Projectile.h"

class ShipObj {

public:

    ShipObj(std::unique_ptr<Position> &pos, std::vector<std::shared_ptr<Projectile>> &projectiles);

    ~ShipObj();

    virtual void shoot() = 0;

    virtual void update() = 0;

    virtual void render() = 0;

    virtual void reset() = 0;

    [[nodiscard]] std::unique_ptr<SDL_Rect> getPos() const;

    std::vector<std::shared_ptr<Projectile>> m_projectiles;


protected:
    std::unique_ptr<Position> m_pos;

};


#endif //PG400_EKSAMEN_SHIPOBJ_H
