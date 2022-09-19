
#ifndef PG400_EKSAMEN_MOVINGBG_H
#define PG400_EKSAMEN_MOVINGBG_H

#include"BackgroundPosition/BackgroundPosition.h"

class MovingBG {

public:
    explicit MovingBG(std::unique_ptr<BackgroundPosition> &pos);

    void update();
    void render();
    [[maybe_unused]] void reset();


private:
    std::shared_ptr<BackgroundPosition> m_pos;
    int offset;


};


#endif //PG400_EKSAMEN_MOVINGBG_H
