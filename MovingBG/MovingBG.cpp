

#include "MovingBG.h"

MovingBG::MovingBG(std::unique_ptr<BackgroundPosition> &pos) {

    m_pos = std::move(pos);
    offset = 0;
}

void MovingBG::update() {

    --offset;
    if (offset < -m_pos->m_scaledH) {
        offset = 0;
    }

}


void MovingBG::render() {


    m_pos->render(-offset);
    m_pos->render(-m_pos->m_scaledH - offset);
}

void MovingBG::reset() {
    offset = 0;
    m_pos->reset();

}

