#include <iostream>

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <glm/glm.hpp>

#include "main.hpp"
#include "input.hpp"
#include "display.hpp"
#include "shader.hpp"
#include "mesh.hpp"
#include "texture.hpp"
#include "camera.hpp"
#include "timer.hpp"

#include "bth_image.hpp"

bool running = true;

Camera* camera;

int main(){
    SDL_Init(SDL_INIT_EVERYTHING);

    Display display(800,600,"Test");

    Timer timer;

    std::cout << "Initializing shaders" << std::endl;
    Shader shader("./shaders/basic_shader");

    Camera cam(shader.program);
    camera = &cam;

    std::cout << "Initializing vertices" << std::endl;
    Vertex vertices[] = {
        Vertex( glm::vec4(-1.0, -0.5,  0.0,  1.0),
                glm::vec4( 1.0,  0.0,  0.0,  1.0)),
        Vertex( glm::vec4(-0.5,  0.5,  0.0,  1.0),
                glm::vec4( 0.0,  1.0,  0.0,  1.0)),
        Vertex( glm::vec4( 0.0, -0.5,  0.0,  1.0),
                glm::vec4( 0.0,  0.0,  1.0,  1.0)),
    };
    Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));

    Vertex vertices2[] = {
        Vertex( glm::vec4( 1.0, -0.5,  0.0,  1.0),
                glm::vec4( 1.0,  0.0,  0.0,  1.0)),
        Vertex( glm::vec4( 0.5,  0.5,  0.0,  1.0),
                glm::vec4( 0.0,  1.0,  0.0,  1.0)),
        Vertex( glm::vec4( 0.0, -0.5,  0.0,  1.0),
                glm::vec4( 0.0,  0.0,  1.0,  1.0)),
    };
    Mesh mesh2(vertices2, sizeof(vertices2)/sizeof(vertices2[0]));

    Vertex vertices3[] = {
        Vertex( glm::vec4(-0.5, -0.5,  0.0,  2.0),
                glm::vec4( 1.0,  0.0,  0.0,  1.0)),
        Vertex( glm::vec4( 0.0,  0.5,  0.0,  2.0),
                glm::vec4( 0.0,  1.0,  0.0,  1.0)),
        Vertex( glm::vec4( 0.5, -0.5,  0.0,  2.0),
                glm::vec4( 0.0,  0.0,  1.0,  1.0)),
    };
    Mesh mesh3(vertices3, sizeof(vertices2)/sizeof(vertices2[0]));

    Texture tex(BTH_IMAGE_WIDTH, BTH_IMAGE_HEIGHT, BTH_IMAGE_DATA);

    timer.start();

    while (running){
        SDL_Event event;

        input();

        timer.tick();
        //printf("FPS: %f\n", timer.get_fps());

        shader.bind();
        camera->updatePos();

        mesh3.draw();
        mesh.draw();
        mesh2.draw();

        display.update();
    }

    SDL_Quit();

    return 0;
}
