
#include "EnemyShip.h"
#include "../../GameManager/GameManager.h"
#include <utility>

EnemyShip::EnemyShip(std::unique_ptr<Position> &pos, std::vector<std::shared_ptr<Projectile> > &projectiles) : ShipObj(
        pos, projectiles) {
    isShot = false;
    collidedWithPlayer = false;

    currentPos = m_pos->dstRect.y;

    collisionPoint = 0;

    m_move = std::make_unique<Move>(m_pos->xPos, m_pos->yPos, 0, m_pos->m_scaledH, true);

}

void EnemyShip::update() {
    if (!isShot) {

        if (collidedWithPlayer) {
            if (collisionPoint == 0) collisionPoint = currentPos;
            else if (currentPos + 50 > collisionPoint + 50) {
                collidedWithPlayer = false;
                collisionPoint = 0;
            }


        }

        move();
        shoot();
    }

    SDL_FUNCS::Update(m_pos, m_projectiles);

}


void EnemyShip::render() {
    if (!isShot) {
        SDL_FUNCS::Render(m_pos);
    }
    SDL_FUNCS::Render(m_projectiles);

}

void EnemyShip::move()  {

    if (*m_move -= -1){
        currentPos = 0;
        m_pos->dstRect.y = 0;
    }


}

void EnemyShip::shoot() {
    if (m_pos->dstRect.y > currentPos) {

        for (auto &projectile: m_projectiles) {
            if (!projectile->isActive && !projectile->allreadyFired) {
                projectile->fire(m_pos->dstRect);
                currentPos += 200; // fire each 200 pixel

                return;
            }
        }

    }

}


void EnemyShip::reset() {
    m_pos->reset();
    collidedWithPlayer = false;

    currentPos = 0;
    m_pos->dstRect.y = 0;
    isShot = false;



    for (auto &projectile: m_projectiles) {
        projectile->reset();
    }

}


