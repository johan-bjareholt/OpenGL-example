#include <iostream>

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <glm/glm.hpp>

#include "display.hpp"
#include "shader.hpp"
#include "mesh.hpp"


int main(){
    SDL_Init(SDL_INIT_EVERYTHING);

    Display display(800,600,"Test");

    std::cout << "Initializing shaders" << std::endl;
    Shader shader("./shaders/basic_shader");
    
    std::cout << "Initializing vertices" << std::endl;
    Vertex vertices[] = {
        Vertex(glm::vec3(-0.5,-0.5,0)),
        Vertex(glm::vec3(0,0.5,0)),
        Vertex(glm::vec3(0.5,-0.5,0)),
    };
    Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));

    bool running = true;
    while (running){
        SDL_Event e;
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT)
                running = false;
        }
        shader.bind();
        
        mesh.draw();
        
        display.update();
    }

    SDL_Quit();

    return 0;
}
