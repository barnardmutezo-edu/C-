
#include "Position.h"
#include "../SDLWrapper/TextureManager/TextureManager.h"

Position::Position(const std::string &filename, const int &scaledW, const int &scaledH) {
    surface = TextureManager::getSurface(filename);

    if (!surface) throw MyException("Could not find: " + filename);

    texture = TextureManager::loadTexture(surface);


    m_scaledW = surface->w / scaledW;
    m_scaledH = surface->h / scaledH;
    xPos = (GameManager::winW / 2) - (m_scaledW / 2); // ONLY PLAUSIBLE TO THE PLAYER-SHIP...
    yPos = GameManager::winH - (m_scaledH);

    xPosCopy = xPos;
    yPosCopy = yPos;
}


Position::Position(const std::string &filename, const int &scaledW, const int &scaledH, const int &x, const int &y) {

    surface = TextureManager::getSurface(filename);

    if (!surface) throw MyException("Could not find: " + filename);

    texture = TextureManager::loadTexture(surface);


    m_scaledW = surface->w / scaledW;
    m_scaledH = surface->h / scaledH;
    xPos = x;
    yPos = y;


    xPosCopy = xPos;
    yPosCopy = yPos;

}


void Position::update() {
    dstRect = {xPos, yPos, m_scaledW, m_scaledH};
}

void Position::update(int x, int y) {
    dstRect = {x, y, m_scaledW, m_scaledH};
}

void Position::render() {
    SDL_RenderCopy(SDLWrapper::renderer, texture, nullptr, &dstRect);
}

Position::~Position() {
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    std::cout << "Position destroyed" << std::endl;
}

void Position::reset() {

    xPos = xPosCopy;
    yPos = yPosCopy;

}


