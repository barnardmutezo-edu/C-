
#include <iostream>
#include "SDLWrapper.h"
#include "../MyException/MyException.h"

SDL_Renderer *SDLWrapper::renderer = nullptr; // avoid passing references@

void SDLWrapper::init(const std::string &title, const int &width, const int &height) {
    window = nullptr;
    window = getWindow(title.c_str(), width, height);

    if (!window) throw MyException("Window was not Initialized");

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer) throw MyException("Renderer not Initialized");


    std::cout << "Wrapper initialized!" << std::endl;
    isActive = true;

}

SDL_Window *SDLWrapper::getWindow(const char *title, int width, int height) {

    if (!SDL_WasInit(SDL_Init(SDL_INIT_VIDEO))) throw MyException("SDL Video not initialized");
    if (!SDL_WasInit(SDL_Init(SDL_INIT_AUDIO))) throw MyException("SDL Audio not initialized");


    return SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

}

void SDLWrapper::close() {
    SDL_DestroyWindow(window);
    window = nullptr;
    if (!window) std::cout << "Window Cleaned!" << std::endl;
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
    if (!renderer) std::cout << "Renderer Cleaned!" << std::endl;
    SDL_Quit();
}


SDLWrapper::~SDLWrapper() {

    close();

}

void SDLWrapper::runGame() {

    while (isActive) {

        handleInput(isActive);
        update();
        render();


    }


}

void SDLWrapper::setHandler(const std::function<void(bool &)> &handler) {
    handleInput = handler;

}

void SDLWrapper::setUpdate(const std::function<void(void)> &updater) {
    update = updater;

}

void SDLWrapper::setRender(const std::function<void(void)> &rendered) {
    render = rendered;
}

