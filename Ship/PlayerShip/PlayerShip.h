
#ifndef PG400_EKSAMEN_PLAYERSHIP_H
#define PG400_EKSAMEN_PLAYERSHIP_H

#include "../ShipObj/ShipObj.h"
#include "CockPit/CockPit.h"
#include "Stats/Stats.h"
#include "../../SDLWrapper/Sound/Sound.h"
#include "../../Move/Move.h"

class PlayerShip : public ShipObj {
public:
    explicit PlayerShip(std::unique_ptr<Position> &pos, std::vector<std::shared_ptr<Projectile>> &projectiles);

    void moveRight() const;

    void moveLeft() const;

    void moveUp() const;

    void moveDown() const;

    void setEnemies(const int &enemies);

    void shoot() override;

    void update() override;

    void render() override;

    std::shared_ptr<Stats> m_stats;


    void reset() override;

private:
    std::shared_ptr<CockPit> cockPit;

    std::unique_ptr<Move> move;

};


#endif //PG400_EKSAMEN_PLAYERSHIP_H
