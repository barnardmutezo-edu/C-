
#include "Text.h"
#include "../TextureManager/TextureManager.h"


Text::Text(const int &W, const int &H, const int &xPos, const int &yPos) {
    if (!TTF_Init()) {
        std::cout << SDL_GetError() << std::endl;

    }

    m_font = TTF_OpenFont("../Assets/Fonts/open.ttf", 58);

    if (m_font == nullptr) {

        std::cout << "yesss is null" << std::endl;

    };

    color = {255, 255, 255}; // White

    m_W = W;
    m_H = H;

    m_xPos = xPos;
    m_yPos = yPos;


}


void Text::write(const std::string &text, const std::string &fontType, const int && fontSize) {


    textRect = {m_xPos, m_yPos, m_W, m_H};
    m_font = TTF_OpenFont(fontType.c_str(), fontSize);

    if (m_font == nullptr) {

        std::cout << "yesss is null" << std::endl;

    };


    textSurface = TTF_RenderText_Solid(m_font, text.c_str(), color);

}


void Text::update() {

    textTexture = TextureManager::loadTexture(textSurface);

}

void Text::render() {
    SDL_RenderCopy(SDLWrapper::renderer, textTexture, nullptr, &textRect);
}


Text::~Text() {
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);

}

void Text::reset() {

}

