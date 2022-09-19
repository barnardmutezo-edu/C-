
#ifndef PG400_EKSAMEN_INPUTMANAGER_H
#define PG400_EKSAMEN_INPUTMANAGER_H

#include "SDL.h"
#include <memory>

class InputManager {

public:
    InputManager();

    ~InputManager();

    bool keyDown(const SDL_Scancode &keyCode);
    bool keyPressed(const SDL_Scancode &keyCode);
    void update();

private:
    int numKeys;
    const Uint8 *keyboardState;

    Uint8 *prevKeyboardState;


};


#endif //PG400_EKSAMEN_INPUTMANAGER_H
