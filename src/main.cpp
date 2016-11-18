#include <iostream>

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <glm/glm.hpp>

#include "main.hpp"
#include "input.hpp"
#include "display.hpp"
#include "shader.hpp"
#include "mesh.hpp"

bool running = true;

int main(){
    SDL_Init(SDL_INIT_EVERYTHING);

    Display display(800,600,"Test");

    std::cout << "Initializing shaders" << std::endl;
    Shader shader("./shaders/basic_shader");

    std::cout << "Initializing vertices" << std::endl;
    Vertex vertices[] = {
        Vertex( glm::vec3(-1.0, -0.5,   0.0),
                glm::vec3(1.0,  0.0,    0.0)),
        Vertex( glm::vec3(-0.5, 0.5,    0.0),
                glm::vec3(0.0,  1.0,    0.0)),
        Vertex( glm::vec3(0.0,  -0.5,   0.0),
                glm::vec3(0.0,  0.0,    1.0)),
    };
    Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));

    Vertex vertices2[] = {
        Vertex( glm::vec3(1.0,  -0.5,   0.0),
                glm::vec3(1.0,  0.0,    0.0)),
        Vertex( glm::vec3(0.5,  0.5,    0.0),
                glm::vec3(0.0,  1.0,    0.0)),
        Vertex( glm::vec3(0.0,  -0.5,   0.0),
                glm::vec3(0.0,  0.0,    1.0)),
    };
    Mesh mesh2(vertices2, sizeof(vertices2)/sizeof(vertices2[0]));

    while (running){
        SDL_Event event;

        input();

        shader.bind();

        mesh.draw();
        mesh2.draw();

        display.update();
    }

    SDL_Quit();

    return 0;
}
