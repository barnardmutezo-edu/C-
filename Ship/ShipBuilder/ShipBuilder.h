
#ifndef PG400_EKSAMEN_SHIPBUILDER_H
#define PG400_EKSAMEN_SHIPBUILDER_H

#include "../PlayerShip/PlayerShip.h"
#include "../EnemyShip/EnemyShip.h"


class ShipBuilder {

public:
    std::vector<std::shared_ptr<ShipObj>> &getShips(const std::string &filename);


private:
    std::vector<std::shared_ptr<ShipObj>> container;

    void loadShips(const std::string &filename);

    void createShipOBJ(const std::string &line);

    std::shared_ptr<std::vector<std::string>> getShipVector(const std::string &line);

};


#endif //PG400_EKSAMEN_SHIPBUILDER_H
