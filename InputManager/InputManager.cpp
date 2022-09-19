
#include "InputManager.h"

InputManager::InputManager() {
    keyboardState = SDL_GetKeyboardState(&numKeys);
    prevKeyboardState = new Uint8[numKeys];
    memcpy(prevKeyboardState, keyboardState, numKeys);

}

void InputManager::update() {
    memcpy(prevKeyboardState, keyboardState, numKeys);

}


bool InputManager::keyDown(const SDL_Scancode &keyCode) {
    return keyboardState[keyCode];
}


bool InputManager::keyPressed(const SDL_Scancode &keyCode) {
    return !prevKeyboardState[keyCode] && keyboardState[keyCode];
}



InputManager::~InputManager() {

    delete prevKeyboardState;

}

