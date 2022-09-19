

#include "Sound.h"
#include "../../MyException/MyException.h"

Sound::Sound(const std::string &filename) {


    if (!SDL_LoadWAV(filename.c_str(), &m_audioSpec, &m_waveStart, &m_waveEnd))
        throw MyException("Could not find: " + filename);


    m_audioDeviceID = SDL_OpenAudioDevice(nullptr, 0, &m_audioSpec, nullptr, 0);


    if (m_audioDeviceID == 0) std::cout << SDL_GetError() << m_audioDeviceID << std::endl;


}


void Sound::playSound() {

    SDL_QueueAudio(m_audioDeviceID, m_waveStart, m_waveEnd);
    SDL_PauseAudioDevice(m_audioDeviceID, 0);

}


Sound::~Sound() {
    SDL_FreeWAV(m_waveStart);
    SDL_CloseAudioDevice(m_audioDeviceID);

    std::cout << "Sound closed !" << std::endl;


}



