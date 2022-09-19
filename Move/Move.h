
#ifndef PG400_EKSAMEN_MOVE_H
#define PG400_EKSAMEN_MOVE_H


#include "../Position/Position.h"

class Move {

public:
explicit Move(int &x, int&y, const int &constraintW,const int &constraintH);

    Move(int &xPos, int &yPos, const int &constraintW, const int &constraintH, bool concurrent);

    void operator+=(const int & pixel) const;
    bool operator-=(const int & pixel) const;


private:
    int m_constraintW;
    int m_constraintH;
    bool m_concurrent;
    int& m_x;
    int& m_y;
};


#endif //PG400_EKSAMEN_MOVE_H
