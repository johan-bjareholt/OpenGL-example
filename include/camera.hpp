#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

class Camera {
    private:
        GLuint program;
        GLuint ubid;
        GLfloat campos[4];
    public:
        Camera(GLuint program);
        void updatePos();

        void moveCamera(const glm::vec4& pos);
        void translateCamera(const glm::vec4& pos);
};
