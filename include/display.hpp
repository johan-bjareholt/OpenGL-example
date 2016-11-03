#pragma once

#include <SDL2/SDL.h>

class Display {
    private:
        SDL_Window* window;
        SDL_GLContext glContext;

    public:
        Display(int width, int height, const std::string title);
        ~Display();
        void update();
};
