#ifndef PG400_EKSAMEN_GAMEMANAGER_H
#define PG400_EKSAMEN_GAMEMANAGER_H

#include <algorithm>
#include "../Ship/ShipObj/ShipObj.h"
#include "../Ship/PlayerShip/PlayerShip.h"
#include "../MovingBG/MovingBG.h"
#include "../Ship/EnemyShip/EnemyShip.h"
#include "../SDLWrapper/SDL_Funcs/SDL_FUNCS.h"
#include "../SDLWrapper/Sound/Sound.h"
#include "../FileManager/FileManager.h"
#include "../InputManager/InputManager.h"
#include "../SDLWrapper/Text/Text.h"
#include "../Ship/ShipBuilder/ShipBuilder.h"

class GameManager {

public:
    explicit GameManager();

    void start();

    static const int winW;
    static const int winH;


private:
    //The SDL wrapper
    std::unique_ptr<SDLWrapper> sdl;


    std::unique_ptr<Sound> hitEnemySound;
    std::unique_ptr<Sound> hitPlayerSound;


    //The scrolling background
    std::unique_ptr<MovingBG> background;

    // The player pointer
    std::shared_ptr<PlayerShip> playerShip;

    // Collection of the enemies
    std::vector<std::shared_ptr<EnemyShip>> enemies;

    // Input manager
    std::unique_ptr<InputManager> input;

    // Build ships from file
    std::unique_ptr<ShipBuilder> shipBuilder;


    //Collection of the texts
    std::vector<std::unique_ptr<Text> > texts;

    void handleInput(bool &isActive);

    void update();

    void render();


    void handleCollision();

    bool gameOver;
    bool waitForInput;
    bool playerWon;

    void processGameOver();

    void resetGame();

    bool initManager();

    void loadShips(std::vector<std::shared_ptr<ShipObj>> & ships);
};


#endif //PG400_EKSAMEN_GAMEMANAGER_H
