#include <GL/glew.h>
#include <glm/glm.hpp>
#include <iostream>

#include "mesh.hpp"

Vertex::Vertex(const glm::vec4& pos, const glm::vec2& texcoord){
    this->pos = pos;
    this->texcoord = texcoord;
}

Mesh::Mesh(GLuint program, Vertex* vertices, unsigned int vertex_count, const glm::vec4& pos, const glm::vec3& rotation){
    // Set object attributes
    this->program = program;
    this->uniform_wpos_id = glGetUniformLocation(program, "w_position");
    this->pos = pos;
    this->rotation = rotation;
    // How many vertexes to draw (Since only allow triangles works it should always be 3)
    drawCount = vertex_count;

    // Generate vertex array object name (p1 = count to generate, p2 = arrptr)
    glGenVertexArrays(1, &vertexArrayObject);
    // Bind a vertex array object
    glBindVertexArray(vertexArrayObject);

    // Generate buffer object names for our vertices
    glGenBuffers(1, &vertexArrayBuffer);

    // Binds out Vertex buffer
    glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffer);
    // Set buffer data
    glBufferData(GL_ARRAY_BUFFER, vertex_count * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);

    // Index, count, type, normalize, spacing, start
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 6*sizeof(GLfloat), 0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 6*sizeof(GLfloat), (const void*)(4*sizeof(GLfloat)));

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

Mesh::~Mesh(){
    glDeleteVertexArrays(1, &vertexArrayObject);
}

void Mesh::draw(){
    glBindVertexArray(vertexArrayObject);

    glUniform4fv(uniform_wpos_id, 1, (const GLfloat*)&this->pos);

    glDrawArrays(GL_TRIANGLES, 0, drawCount);

    glBindVertexArray(0);
}
