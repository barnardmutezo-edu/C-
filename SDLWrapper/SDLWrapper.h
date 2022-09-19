
#ifndef PG400_EKSAMEN_SDLWRAPPER_H
#define PG400_EKSAMEN_SDLWRAPPER_H

#include <SDL_image.h>
#include <iostream>
#include <SDL_ttf.h>


class SDLWrapper {
public:

    SDLWrapper() = default;

    ~SDLWrapper();

    void init(const std::string &title, const int &width, const int &height);

    void setHandler(const std::function<void(bool&)> &handler);


    void setUpdate(const std::function<void(void)> &updater);

    void setRender(const std::function<void(void)> &rendered);

    static SDL_Renderer *renderer;

    void runGame();

    bool isActive;

private:
    SDL_Window *window;


    std::function<void(bool &)> handleInput; // Template functions to set customized events
    std::function<void(void)> update;
    std::function<void(void)> render;

    static SDL_Window *getWindow(const char *title, int width, int height);

    void close();


};


#endif //PG400_EKSAMEN_SDLWRAPPER_H
