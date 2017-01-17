#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

class Camera {
    private:
        GLuint program;
        GLuint ubid;
        glm::vec3 campos;

        GLuint mvp_mat_ubid;
        glm::mat4 mvp_mat, model_mat, view_mat, proj_mat;
    public:
        Camera(GLuint program);
        void updatePos();

        void moveCamera(const glm::vec3& pos);
        void translateCamera(const glm::vec3& pos);
};
