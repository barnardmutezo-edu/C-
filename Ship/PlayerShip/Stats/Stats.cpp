
#include "Stats.h"

Stats::Stats(const int &life, const int &enemies, std::vector<std::shared_ptr<Projectile>> &projectiles) {

    m_enemies = enemies, m_enemiesCopy = enemies;
    m_life = life, m_lifeCopy = life;
    m_enemiesShot = 0;
    m_projectiles = projectiles;


    isShot = false;
    m_shotDownEnemy = false;


}

void Stats::reset() {

    m_enemies = m_enemiesCopy;
    m_life = m_lifeCopy;
    m_enemiesShot = 0;

    isShot = false;
    m_shotDownEnemy = false;
    std::cout<<  "Reset" <<std::endl;

}

