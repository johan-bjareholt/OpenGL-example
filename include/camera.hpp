#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

class Camera {
    private:
        GLuint program;
        GLuint ubid;
        GLfloat campos[4];
        //GLuint world_mat_ubid, view_mat_ubid, proj_mat_ubid;
        //glm::mat4 world_mat, view_mat, proj_mat;
    public:
        Camera(GLuint program);
        void updatePos();

        void moveCamera(const glm::vec4& pos);
        void translateCamera(const glm::vec4& pos);
};
