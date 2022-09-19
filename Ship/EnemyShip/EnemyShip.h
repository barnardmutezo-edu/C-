
#ifndef PG400_EKSAMEN_ENEMYSHIP_H
#define PG400_EKSAMEN_ENEMYSHIP_H

#include "../ShipObj/ShipObj.h"
#include "../../Move/Move.h"
#include <random>


class EnemyShip : public ShipObj {

public:
    explicit EnemyShip(std::unique_ptr<Position> &pos, std::vector<std::shared_ptr<Projectile> > &projectiles);

    void update() override;

    void move() ;

    void render() override;

    void shoot() override;

    void reset() override;

    bool isShot;
    bool collidedWithPlayer;


private:
    int currentPos;
    int collisionPoint;
    std::unique_ptr<Move> m_move;

};


#endif //PG400_EKSAMEN_ENEMYSHIP_H
