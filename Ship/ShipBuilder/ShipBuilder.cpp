
#include "ShipBuilder.h"
#include "../../FileManager/FileManager.h"

std::vector<std::shared_ptr<ShipObj>> &ShipBuilder::getShips(const std::string &filename) {

    loadShips(filename);

    return container;
}

void ShipBuilder::loadShips(const std::string &filename) {

    auto outPut = [&](const std::string &line, int &lineNumber) { createShipOBJ(line); };
    FileManager::readFile(filename, outPut);

}

void ShipBuilder::createShipOBJ(const std::string &line) {


    auto shipArray = getShipVector(line);


    auto createProjectiles = [](const std::string &filename, const std::string &audioFile, const int &amount,
                                const int &dir) {
        std::vector<std::shared_ptr<Projectile>> vector;
        for (int i = 0; i < amount; i++) {

            auto projectilePos = std::make_unique<Position>(filename, 4, 8);
            auto sound = std::make_unique<Sound>(audioFile.c_str());
            auto projectile = std::make_unique<Projectile>(projectilePos, sound, dir);
            vector.push_back(std::move(projectile));


        }
        return vector;
    };


    auto type = shipArray->at(0);
    auto shipIMG = shipArray->at(1);
    auto projectileIMG = shipArray->at(2);
    auto projectileSound = shipArray->at(3);
    auto projectileQuantity = atoi(shipArray->at(4).c_str());
    auto projectileDir = atoi(shipArray->at(5).c_str());

    int xPos, yPos;


    if (shipArray->size() > 6) { // I know that enemies have more than six properties from the file

        xPos = atoi(shipArray->at(6).c_str());
        yPos = atoi(shipArray->at(7).c_str());

    }


    auto projectiles = createProjectiles(projectileIMG, projectileSound, projectileQuantity, projectileDir);

    if (type == "PlayerShip") {

        auto playerPos = std::make_unique<Position>(shipIMG, 8, 8);

        auto player = std::make_shared<PlayerShip>(playerPos, projectiles);

        container.push_back(player);

    } else {
        auto pos = std::make_unique<Position>(shipIMG, 8, 8, xPos, yPos);
        auto enemyShip = std::make_shared<EnemyShip>(pos, projectiles);
        container.push_back(std::move(enemyShip));

    }


}

std::shared_ptr<std::vector<std::string>> ShipBuilder::getShipVector(const std::string &line) {

    auto tempString = std::string();
    auto tempVector = std::make_shared<std::vector<std::string> >();

    auto checkLetter = [&](auto &letter) {

        if (letter == '|') {          // Each value in the file is separated by the "|" char
            tempVector->push_back(tempString);  // When I have reached the values end I add it to the vector
            tempString.clear();     // Clear the string for next value

        } else {

            tempString.push_back(letter); // Still not reached "|"  append the letter

        }
    };

    std::for_each(line.begin(), line.end(), checkLetter);


    return tempVector;

}
