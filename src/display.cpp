#include <iostream>

#include <SDL2/SDL.h>
#include <GL/glew.h>

#include "display.hpp"

Display::Display(int width, int height, const std::string title){
    std::cout << "Initializing display" << std::endl;

    // Buffer size
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    // Double buffer
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    
    this->window = SDL_CreateWindow(
            title.c_str(),
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            width, height,
            SDL_WINDOW_OPENGL
    );
    this->glContext = SDL_GL_CreateContext(window);
    std::cout << "OpenGL version is " << glGetString(GL_VERSION) << std::endl;

    GLenum status = glewInit();

    if (status != GLEW_OK){
        std::cerr << "Glew failed to initialize" << std::endl;
    }
}

Display::~Display(){
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
}

void Display::update(){
    SDL_GL_SwapWindow(window);
    glClearColor(0.f, 0.f, 0.15f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);
}
