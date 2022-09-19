#ifndef PG400_EKSAMEN_STATS_H
#define PG400_EKSAMEN_STATS_H

#include <vector>
#include "../../../Projectile/Projectile.h"

class Stats {
public:
    Stats(const int &life, const int &enemies,std::vector<std::shared_ptr<Projectile>> &projectiles);

    int m_life;
    int m_enemies;
    int m_enemiesShot;
    std::vector<std::shared_ptr<Projectile>> m_projectiles;

    bool isShot;
    bool m_shotDownEnemy;

    void reset();

private:
    int m_lifeCopy;
    int m_enemiesCopy;

};


#endif //PG400_EKSAMEN_STATS_H
