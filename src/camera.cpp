#include "camera.hpp"
#include <iostream>
#include <cstring>

#include <GL/glu.h>

#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define PI 3.1415926535897932384626433832795

Camera::Camera(GLuint program){
    this->program = program;
    this->ubid = glGetUniformLocation(program, "cam_pos");
    this->mvp_mat_ubid = glGetUniformLocation(program, "mvp_mat");
    this->moveCamera(glm::vec3(0.f, 0.f, -2.f));

    // Projection
    proj_mat = glm::perspective(
        3.14f*0.45f,// The horizontal Field of View, in degrees : the amount of "zoom". Think "camera lens". Usually between 90° (extra wide) and 30° (quite zoomed in)
        4.0f/3.0f,  // Aspect Ratio. Depends on the size of your window. 4/3 == 800/600
        0.1f,       // Near clipping plane. Keep as big as possible, or you'll get precision issues.
        10.0f       // Far clipping plane. Keep as little as possible if you don't need long viewing distance
    );

}

static float angle = 0;
void Camera::updatePos(){
    // Model (identity matrix, will be at origin)
    model_mat = glm::mat4(1.0f);
    angle += 0.05;
    model_mat = glm::rotate(model_mat, angle, glm::vec3(0,1,0));

    // View
    view_mat = glm::lookAt(
        campos, // Camera is at (4,3,3), in World Space
        glm::vec3(0,0,0), // and looks at the origin
        glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
    );

    mvp_mat = proj_mat*view_mat*model_mat;

    glUniformMatrix4fv(mvp_mat_ubid, 1, GL_FALSE, (GLfloat*)&mvp_mat[0][0]);
}

void Camera::moveCamera(const glm::vec3& pos){
    campos = pos;
}

void Camera::translateCamera(const glm::vec3& pos){
    campos += pos;
}
