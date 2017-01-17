#include "camera.hpp"
#include <iostream>
#include <cstring>

#include <GL/glu.h>

#define PI 3.1415926535897932384626433832795

Camera::Camera(GLuint program){
    this->program = program;
    this->ubid = glGetUniformLocation(program, "cam_pos");
    memset(campos, 0, sizeof(campos));
    //this->view_mat_ubid = glGetUniformLocation(program, "view_mat");
    //this->proj_mat_ubid = glGetUniformLocation(program, "proj_mat");

    // Set camera perspective
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective(90, 800/600, 0.1,  10.0); // Viewing angle, aspect ratio, near, far
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
}

void Camera::updatePos(){
    glUniform4fv(ubid, 1, campos);
    //glUniform4fv(world_mat_ubid, 1, (GLfloat*)&world_mat);
    //glUniform4fv(view_mat_ubid, 1, (GLfloat*)&view_mat);
    //glUniform4fv(proj_mat_ubid, 1, (GLfloat*)&proj_mat);
}

void Camera::moveCamera(const glm::vec4& pos){
    campos[0] = pos.x;
    campos[1] = pos.y;
    campos[2] = pos.z;
    campos[3] = pos.w;
    //world_mat = (pos * glm::mat4());
}

void Camera::translateCamera(const glm::vec4& pos){
    campos[0] += pos.x;
    campos[1] += pos.y;
    campos[2] += pos.z;
    campos[3] += pos.w;
    //world_mat[0] += pos.x;
    //world_mat[1] += pos.y;
    //world_mat[2] += pos.z;
    //world_mat[3] += pos.w;
}
