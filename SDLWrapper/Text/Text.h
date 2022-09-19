
#ifndef PG400_EKSAMEN_TEXT_H
#define PG400_EKSAMEN_TEXT_H

#include <SDL_ttf.h>
#include <iostream>


class Text {

public:

    explicit Text(const int &W, const int &H, const int &xPos, const int &yPos);

    ~ Text();

    void update();

    void render();
    [[maybe_unused]] void reset();

    void write(const std::string &text, const std::string &fontType, const int &&fontSize);

private:

    TTF_Font *m_font;
    SDL_Color color{};
    SDL_Surface *textSurface{};
    SDL_Texture *textTexture{};
    SDL_Rect textRect{};


    int m_xPos;
    int m_yPos;

    int m_W;
    int m_H;

};


#endif //PG400_EKSAMEN_TEXT_H
