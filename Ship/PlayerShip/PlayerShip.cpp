
#include "PlayerShip.h"

#include "../../GameManager/GameManager.h"


PlayerShip::PlayerShip(std::unique_ptr<Position> &pos, std::vector<std::shared_ptr<Projectile>> &projectiles)
        : ShipObj(pos, projectiles) {


    auto w = GameManager::winW - (m_pos->m_scaledW);
    auto h = GameManager::winH - (m_pos->m_scaledH);

    move = std::make_unique<Move>(m_pos->xPos, m_pos->yPos, w, h);


}


void PlayerShip::moveRight() const {
    //   moveHorisontally(1);
    *move += 1;
}

void PlayerShip::moveLeft() const {
    //  moveHorisontally(-1);
    *move += -1;

}

void PlayerShip::moveUp() const {
    //moveVertically(1);
    *move -= 1;
}

void PlayerShip::moveDown() const {
    // moveVertically(-1);
    *move -= -1;

}


void PlayerShip::shoot() {

    for (const auto &projectile: m_projectiles) {
        if (!projectile->isActive) {

            projectile->fire(m_pos->dstRect);
            std::cout << "shotFired!";

            return;
        }
    }

}


void PlayerShip::update() {
    SDL_FUNCS::Update(cockPit, m_pos, m_projectiles);
}


void PlayerShip::render() {
    SDL_FUNCS::Render(cockPit, m_pos, m_projectiles);
}

void PlayerShip::setEnemies(const int &enemies) {

    m_stats = std::make_shared<Stats>(3, enemies, m_projectiles);
    cockPit = std::make_unique<CockPit>(m_stats);

}

void PlayerShip::reset() {
    SDL_FUNCS::Reset(m_pos,cockPit,m_projectiles);
    m_stats->reset();



}



