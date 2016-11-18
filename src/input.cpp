#include <iostream>

#include <SDL2/SDL.h>

#include "main.hpp"
#include "input.hpp"

bool keyboardstate[322];

void input(){
    SDL_Event event;
    while (SDL_PollEvent(&event)){
        if (event.type == SDL_QUIT)
            running = false;
        // Save key state
        if (event.type == SDL_KEYDOWN && event.key.keysym.sym <= 322)
            keyboardstate[event.key.keysym.sym] = true;
        else if (event.type == SDL_KEYUP && event.key.keysym.sym <= 322)
            keyboardstate[event.key.keysym.sym] = false;
        // 
        switch (event.key.keysym.sym){
            case SDLK_RETURN:
                std::cout << "Pressed enter" << std::endl;
                break;
        }
    }
}
