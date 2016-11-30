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

        // On keydown
        if (event.type == SDL_KEYDOWN){
            switch (event.key.keysym.sym){
                case SDLK_RETURN:
                    std::cout << "Pressed enter" << std::endl;
                    break;
            }
        }

        // Movement
        if (keyboardstate[SDLK_w])
            camera->translateCamera(glm::vec4(0.0f, -0.01f, -0.0f, 0.0f));
        if (keyboardstate[SDLK_s])
            camera->translateCamera(glm::vec4(0.0f, 0.01f, 0.0f, 0.0f));
        if (keyboardstate[SDLK_a])
            camera->translateCamera(glm::vec4(0.01f, 0.0f, 0.0f, 0.0f));
        if (keyboardstate[SDLK_d])
            camera->translateCamera(glm::vec4(-0.01f, 0.0f, 0.0f, 0.0f));
        if (event.type == SDL_MOUSEWHEEL){
            SDL_MouseWheelEvent* mwe = (SDL_MouseWheelEvent*) &event;
            camera->translateCamera(glm::vec4(0.f, 0.f, 0.f, mwe->y*0.01f));
        }
    }
}
