
#include "Projectile.h"
#include "../GameManager/GameManager.h"

Projectile::Projectile(std::unique_ptr<Position> &pos, std::unique_ptr<Sound> &sound, const int &dir)
        : ReusableGraphic(pos) {
    isActive = false;
    allreadyFired = false;
    m_dir = dir;
    m_sound = std::move(sound);

}

void Projectile::update() {

    if (isActive) {
        if (m_dir == 0) {
            m_pos->yPos -= 4; // Player shooting upwards

        } else m_pos->yPos += 4; // enemy shooting downwards

        m_pos->dstRect = {m_pos->xPos, m_pos->yPos, m_pos->m_scaledW, m_pos->m_scaledH};

        if (m_pos->yPos < -m_pos->m_scaledH || m_pos->yPos > GameManager::winH + m_pos->m_scaledH )isActive = false; // Checking if player/enemy projectile goes of screen


        m_pos->update();

    }

}

void Projectile::render() {
    if (isActive) m_pos->render(); // Only render when is fired
}

void Projectile::reset() {
    isActive = false;
    allreadyFired = false;

    m_pos->reset();
}

void Projectile::fire(SDL_Rect &pos) {

    isActive = true;
    m_sound->playSound();
    m_pos->xPos = pos.x + (pos.w) / 2 - ((m_pos->m_scaledW) / 2);
    m_pos->yPos = pos.y;
}


