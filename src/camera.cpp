#include "camera.hpp"
#include <iostream>
#include <cstring>

#include <GL/glu.h>

#define PI 3.1415926535897932384626433832795

Camera::Camera(GLuint program){
    this->program = program;
    this->ubid = glGetUniformLocation(program, "camera");
    memset(campos, 0, sizeof(campos));

    // Set camera perspective
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective(90, 800/600, 0.1,  10.0); // Viewing angle, aspect ratio, near, far
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
}

void Camera::updatePos(){
    glUniform4fv(ubid, 1, campos);
}

void Camera::moveCamera(const glm::vec4& pos){
    campos[0] = pos.x;
    campos[1] = pos.y;
    campos[2] = pos.z;
    campos[3] = pos.w;
}

void Camera::translateCamera(const glm::vec4& pos){
    campos[0] += pos.x;
    campos[1] += pos.y;
    campos[2] += pos.z;
    campos[3] += pos.w;
}
