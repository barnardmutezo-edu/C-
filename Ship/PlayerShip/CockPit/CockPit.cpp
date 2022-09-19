
#include "CockPit.h"
#include "../../../SDLWrapper/TextureManager/TextureManager.h"

template<typename T, typename T2, typename T3>
void process(const T &arg, T2 &&condition, T3 &&optional = nullptr) {
    for (auto &i: arg) {


        if (i->isActive && condition) {
            if (optional > 0) optional--;

            i->isActive = false;

            condition = false;

            break;
        }
    }
}


void CockPit::update() {

    process(lifeIcons, m_stats->isShot, m_stats->m_life);
    process(enemyIcons, m_stats->m_shotDownEnemy, -1);

    for (int i = 0; i < m_stats->m_projectiles.size(); ++i)
        ammoIcons[i]->isActive = !m_stats->m_projectiles[i]->isActive;


    SDL_FUNCS::Update(lifeIcons, enemyIcons, ammoIcons);

}

void CockPit::reset() {
    for (auto &life: lifeIcons) life->isActive = true;
    for (auto &enemy: enemyIcons) enemy->isActive = true;

}

void CockPit::render() {
    SDL_FUNCS::Render(lifeIcons, enemyIcons, ammoIcons);

}

CockPit::CockPit(const std::shared_ptr<Stats> &stats) {
    m_stats = stats;
    if (TTF_Init() == -1) {
        std::cout << TTF_GetError() << std::endl;

    }
    int base = 0;


    auto buildIcons = [&]<typename T>(const int amount, const std::string &file, const int &scaledW, const int &scaledH,
                                      const int &x, const int &y, const int &distance, const int &pos) {

        auto container = std::vector<std::unique_ptr<T>>();


        for (int i = 0; i < amount; ++i) {

            auto iconPos = std::unique_ptr<Position>();

            if (pos < 0) {
                iconPos = std::make_unique<Position>(file, scaledW, scaledH, x - base, y);// align left on the screen

            } else {

                iconPos = std::make_unique<Position>(file, scaledW, scaledH, x + base, y); // align right on the screen


            }

            auto icon = std::make_unique<ReusableGraphic>(iconPos);
            base += distance;
            icon->isActive = true;
            container.push_back(std::move(icon));

        }
        base = 0;
        return container;

    };


    lifeIcons = buildIcons.operator()<ReusableGraphic>(m_stats->m_life, "../Assets/Images/fighter.png", 10, 12,
                                                       (GameManager::winW - 250), 20, 80, 1);
    enemyIcons = buildIcons.operator()<ReusableGraphic>(m_stats->m_enemies, "../Assets/Images/enemyship.png", 10, 12, 250, 20,
                                                        100, -1);
    ammoIcons = buildIcons.operator()<ReusableGraphic>(m_stats->m_projectiles.size(), "../Assets/Images/lazer2Cropped.png", 6, 8, GameManager::winW - 150 , GameManager::winH - 100,
                                                        40, 1);


}


