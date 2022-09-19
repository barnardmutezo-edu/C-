
#include "Move.h"
#include "../GameManager/GameManager.h"

void Move::operator+=(const int &pixel) const {

    m_x += pixel;
    if (m_x > m_constraintW) {
        m_x = m_constraintW;

    } else if (m_x < 0) {
        m_x = 0;
    }


}

bool Move::operator-=(const int &pixel) const {
    m_y -= pixel;

    if (m_concurrent) {
        if (m_y > GameManager::winH) {
            m_y = -m_constraintH; // enemy gone past bottom of screen
            return true;

        }
    } else {
        if (m_y > m_constraintH) {
            m_y = m_constraintH;
        }
    }


}

Move::Move(int &xPos, int &yPos, const int &constraintW, const int &constraintH) : m_x(xPos), m_y(yPos) {
    m_constraintW = constraintW;
    m_constraintH = constraintH;
}

Move::Move(int &xPos, int &yPos, const int &constraintW, const int &constraintH, bool concurrent) : m_x(xPos),
                                                                                                    m_y(yPos) {
    m_constraintW = constraintW;
    m_constraintH = constraintH;
    m_concurrent = concurrent;
}
