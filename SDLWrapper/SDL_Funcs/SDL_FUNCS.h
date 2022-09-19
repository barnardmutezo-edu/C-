
#ifndef PG400_EKSAMEN_SDL_FUNCS_H
#define PG400_EKSAMEN_SDL_FUNCS_H

#include <memory.h>
#include <vector>
#include <iostream>

namespace SDL_FUNCS {

    static void Update() {

    }

    static void Render() {

    }


    static void Reset() {

    }


    template<typename T>
    static auto process(const T &arg, int FLAG) {

        switch (FLAG) {
            case 1:
                arg->update();
                break;
            case 2:
                arg->render();
                break;


            case 3:

                arg->reset();


                break;
            default:
                break;
        }

    }

    template<typename T>
    static auto process(const std::vector<T> &arg, int FLAG) {

        switch (FLAG) {
            case 1:
                for (auto &i: arg) i->update();
                break;
            case 2:
                for (auto &i: arg) i->render();
                break;
            case 3:
               for (auto &i: arg) i->reset();

                break;

            default:
                break;
        }
    }


    template<typename T1, typename... T2>
    static void Update(const T1 &arg, const T2 &... rest) {

        process(arg, 1);
        Update(rest...);
    }


    template<typename T1, typename... T2>
    static void Render(const T1 &arg, const T2 &... rest) {

        process(arg, 2);
        Render(rest...);
    }

    template<typename T1, typename... T2>
    static void Reset(const T1 &arg, const T2 &... rest) {

        process(arg, 3);
        Reset(rest...);
    }

};


#endif //PG400_EKSAMEN_SDL_FUNCS_H
