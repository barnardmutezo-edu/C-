
#include "ShipObj.h"
#include <utility>

ShipObj::ShipObj(std::unique_ptr<Position> &pos, std::vector<std::shared_ptr<Projectile>> &projectiles) {

    m_pos = std::move(pos);
    m_projectiles = projectiles;

}


ShipObj::~ShipObj() {
    std::cout << "Ship destroyed" << std::endl;


}

std::unique_ptr<SDL_Rect> ShipObj::getPos() const {
    return std::make_unique<SDL_Rect>(m_pos->dstRect);
}

