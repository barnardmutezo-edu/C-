cmake_minimum_required(VERSION 3.21)
project(PG400_Eksamen)

set(CMAKE_CXX_STANDARD 20)

add_executable(PG400_Eksamen main.cpp SDLWrapper/SDLWrapper.cpp SDLWrapper/SDLWrapper.h GameManager/GameManager.cpp GameManager/GameManager.h SDLWrapper/TextureManager/TextureManager.cpp SDLWrapper/TextureManager/TextureManager.h Position/Position.cpp Position/Position.h Projectile/Projectile.cpp Projectile/Projectile.h Ship/ShipObj/ShipObj.cpp Ship/ShipObj/ShipObj.h Ship/PlayerShip/PlayerShip.cpp Ship/PlayerShip/PlayerShip.h Ship/EnemyShip/EnemyShip.cpp Ship/EnemyShip/EnemyShip.h MovingBG/MovingBG.cpp MovingBG/MovingBG.h MovingBG/BackgroundPosition/BackgroundPosition.cpp MovingBG/BackgroundPosition/BackgroundPosition.h Ship/PlayerShip/CockPit/CockPit.cpp Ship/PlayerShip/CockPit/CockPit.h Ship/PlayerShip/Stats/Stats.cpp Ship/PlayerShip/Stats/Stats.h ReusableGraphic/ReusableGraphic.cpp ReusableGraphic/ReusableGraphic.h SDLWrapper/SDL_Funcs/SDL_FUNCS.h SDLWrapper/Sound/Sound.cpp SDLWrapper/Sound/Sound.h FileManager/FileManager.cpp FileManager/FileManager.h InputManager/InputManager.cpp InputManager/InputManager.h Move/Move.cpp Move/Move.h SDLWrapper/Text/Text.cpp SDLWrapper/Text/Text.h MyException/MyException.cpp MyException/MyException.h Ship/ShipBuilder/ShipBuilder.cpp Ship/ShipBuilder/ShipBuilder.h)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES})





