
#ifndef PG400_EKSAMEN_SOUND_H
#define PG400_EKSAMEN_SOUND_H

#include "../SDLWrapper.h"

class Sound {

public:
    explicit Sound(const std::string &filename);

    void playSound();

    ~Sound();

private:
    SDL_AudioDeviceID m_audioDeviceID;

    SDL_AudioSpec m_audioSpec;
    Uint32 m_waveEnd;
    Uint8 *m_waveStart;


};


#endif //PG400_EKSAMEN_SOUND_H
