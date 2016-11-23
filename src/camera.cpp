#include "camera.hpp"
#include <iostream>
#include <cstring>

Camera::Camera(GLuint program){
    this->program = program;
    this->ubid = glGetUniformLocation(program, "camera");
    memset(campos, 0, sizeof(campos));
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
