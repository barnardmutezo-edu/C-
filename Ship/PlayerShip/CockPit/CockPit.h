
#ifndef PG400_EKSAMEN_COCKPIT_H
#define PG400_EKSAMEN_COCKPIT_H

#include <SDL_ttf.h>
#include <vector>
#include "../../../Projectile/Projectile.h"
#include "../../../ReusableGraphic/ReusableGraphic.h"
#include "../Stats/Stats.h"


class CockPit {
public:
    explicit CockPit(const std::shared_ptr<Stats> &stats);

    void update();

    void render();
    void reset();


private:

    std::vector<std::unique_ptr<ReusableGraphic>> lifeIcons;
    std::vector<std::unique_ptr<ReusableGraphic>> enemyIcons;
    std::vector<std::unique_ptr<ReusableGraphic>> ammoIcons;

    std::shared_ptr<Stats>  m_stats;


};


#endif //PG400_EKSAMEN_COCKPIT_H
