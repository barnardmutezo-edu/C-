
#ifndef PG400_EKSAMEN_POSITION_H
#define PG400_EKSAMEN_POSITION_H

#include "SDL.h"
#include "../SDLWrapper/SDLWrapper.h"
#include "../MyException/MyException.h"

class Position {

public:
    explicit Position(const std::string &filename,  const int &scaledW, const int &scaledH);

    ~Position();

    Position(const std::string &filename, const int &scaledW, const int &scaledH, const int &x, const int &y);

    SDL_Texture *texture{};
    SDL_Surface *surface{};

    SDL_Rect dstRect{};

    int xPos{};
    int yPos{};


    void update();
    void render();

    int m_scaledH{};
    int m_scaledW{};
    void update(int x, int y);
    void reset();

private:

    int xPosCopy{};
    int yPosCopy{};

};


#endif //PG400_EKSAMEN_POSITION_H
