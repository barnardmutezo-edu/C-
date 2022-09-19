
#include "GameManager.h"

const int GameManager::winW = 1000;
const int GameManager::winH = 800;

GameManager::GameManager() {
    playerWon = false;
    waitForInput = false;
    gameOver = false;

    sdl = std::make_unique<SDLWrapper>();
    input = std::make_unique<InputManager>();
    shipBuilder = std::make_unique<ShipBuilder>();

}


void GameManager::start() {

    if (!initManager()) return; // Handling exceptions, if any found quit game.

    sdl->setHandler([&](bool &isActive) { handleInput(isActive); });

    sdl->setUpdate([&]() { update(); });
    sdl->setRender([&]() { render(); });
    sdl->runGame();


}


bool GameManager::initManager() {

    try {
        sdl->init("Space Attack V1", winW, winH);
        auto backgroundPos = std::make_unique<BackgroundPosition>("../Assets/Images/opacityBG.png");
        background = std::make_unique<MovingBG>(backgroundPos);

        hitEnemySound = std::make_unique<Sound>("../Assets/Sounds/hitEnemy.wav");
        hitPlayerSound = std::make_unique<Sound>("../Assets/Sounds/hitPlayer.wav");


       auto ships = shipBuilder->getShips("../DB/ships.txt");

        loadShips(ships);



    } catch (MyException &e) {
        std::cout << e.what() << std::endl;
        SDL_Quit();
        return false;
    }

    return true;
}



void GameManager::handleInput(bool &isActive) {

    SDL_PumpEvents();


    if (gameOver) {
        if (input->keyDown(SDL_SCANCODE_SPACE)) {
            resetGame();
            std::cout << "RESET GAME!!" << std::endl;


        }


    } else {


        if (input->keyDown(SDL_SCANCODE_W) || input->keyDown(SDL_SCANCODE_UP))
            playerShip->moveUp();

        if (input->keyDown(SDL_SCANCODE_A) || input->keyDown(SDL_SCANCODE_LEFT))
            playerShip->moveLeft();
        if (input->keyDown(SDL_SCANCODE_S) || input->keyDown(SDL_SCANCODE_DOWN))
            playerShip->moveDown();
        if (input->keyDown(SDL_SCANCODE_D) || input->keyDown(SDL_SCANCODE_RIGHT))
            playerShip->moveRight();

        if (input->keyPressed(SDL_SCANCODE_SPACE))
            playerShip->shoot();
    }


    if (SDL_HasEvent(SDL_QUIT) || input->keyPressed(SDL_SCANCODE_ESCAPE))
        isActive = false;

    input->update();

}


void GameManager::update() {

    if (gameOver) processGameOver();

    if (!gameOver) SDL_FUNCS::Update(background, playerShip, enemies, texts);

    else SDL_FUNCS::Update(background, texts);

    handleCollision();
}

void GameManager::render() {
    SDL_RenderClear(SDLWrapper::renderer);
    if (!gameOver) SDL_FUNCS::Render(background, playerShip, enemies, texts);

    else SDL_FUNCS::Render(background, texts);


    SDL_RenderPresent(SDLWrapper::renderer);
}


void GameManager::handleCollision() {

    if (gameOver) return;


    // An inner templated lambda that checks for any collisions
    auto collided = []<typename T1, typename T2>(const T1 &rectA, const T2 &rectB) {
        return rectA->x < (rectB->x + rectB->w) &&
               (rectA->x + rectA->w) > rectB->x &&
               rectA->y < (rectB->y + rectB->h) &&
               (rectA->h + rectA->y) > rectB->y;
    };


    for (auto &enemy: enemies) {

        for (auto &projectile: enemy->m_projectiles) {

            //CHECKING IF ENEMY-PROJECTILES HIT THE PLAYER

            if (collided(projectile->getPos(), playerShip->getPos()) && projectile->isActive) {

                projectile->isActive = false;
                projectile->allreadyFired = true;
                playerShip->m_stats->isShot = true;
                hitPlayerSound->playSound();
                std::cout << "Projectile hit player!" << std::endl;
                return;
            }

            //CHECKING IF THE ENEMY OR PLAYER COLLIDE
            if (collided(enemy->getPos(), playerShip->getPos()) && !enemy->isShot) {

                if (!enemy->collidedWithPlayer) {
                    std::cout << "EDGES COLLIDED!!" << std::endl;

                    playerShip->m_stats->isShot = true;
                    enemy->collidedWithPlayer = true; // Used to create a slight delay between each collision
                    return;
                }


            }

            //CHECKING IF PLAYER-PROJECTILES HIT ANY ENEMY
            for (auto &pProjectile: playerShip->m_projectiles) {
                if (collided(pProjectile->getPos(), enemy->getPos()) && !enemy->isShot) {
                    std::cout << "projectiles hit enemy!" << std::endl;
                    enemy->isShot = true;
                    pProjectile->isActive = false;
                    playerShip->m_stats->m_enemiesShot++;
                    playerShip->m_stats->m_shotDownEnemy = true;

                    hitEnemySound->playSound();
                    return;
                }
            }
        }

    }


    if (playerShip->m_stats->m_enemiesShot == enemies.size()) {
        playerWon = true;
        gameOver = true;

    }
    if (playerShip->m_stats->m_life == 0) {
        playerWon = false;
        gameOver = true;

    }


}


void GameManager::processGameOver() {

    if (!waitForInput) {

        auto width = 400;
        auto height = 200;


        auto horizontalCenter = GameManager::winW / 2 - (width / 2);
        auto verticalCenter = GameManager::winH / 2 - (height / 2);


        auto text1 = std::make_unique<Text>(width, height, horizontalCenter,
                                            verticalCenter);

        auto text2 = std::make_unique<Text>(400, 50, horizontalCenter,
                                            500);


        if (playerWon) {
            text1->write("Congratulations you won!", "../Assets/Fonts/game_over.ttf", 60);
            std::cout << "YOU WON GAME!!" << std::endl;

        } else {
            text1->write("GAME OVER", "../Assets/Fonts/game_over.ttf", 50);
            std::cout << "YOU lost GAME!!" << std::endl;

        }


        text2->write("Play again? Hit space!", "../Assets/Fonts/open.ttf", 20);


        texts.push_back(std::move(text1));
        texts.push_back(std::move(text2));
        waitForInput = true;

    }


}

void GameManager::resetGame() {

    SDL_FUNCS::Reset(playerShip, enemies, background);

    waitForInput = false;
    gameOver = false;


    texts.clear();

}

void GameManager::loadShips(std::vector<std::shared_ptr<ShipObj>> & ships) {

    auto checkType = [&](auto &ship) {

        auto player = std::dynamic_pointer_cast<PlayerShip>(ship);
        auto enemy = std::dynamic_pointer_cast<EnemyShip>(ship);

        if (player) playerShip = std::move(player);


        else if (enemy) {
            enemies.push_back(std::move(enemy));
        }


    };


    std::for_each(ships.begin(), ships.end(), checkType);

    playerShip->setEnemies(enemies.size());

}



