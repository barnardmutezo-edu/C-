
#include "ReusableGraphic.h"

ReusableGraphic::ReusableGraphic(std::unique_ptr<Position> &pos) {
    isActive = false;
    m_pos = std::move(pos);

}

std::unique_ptr<SDL_Rect> ReusableGraphic::getPos() const {
    return std::make_unique<SDL_Rect>(m_pos->dstRect);

}

void ReusableGraphic::update() {
    if (isActive) m_pos->update();
}

void ReusableGraphic::render() {
    if (isActive) m_pos->render();
}

void ReusableGraphic::reset() {

}
