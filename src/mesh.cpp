#include <GL/glew.h>
#include <glm/glm.hpp>
#include <iostream>

#include "mesh.hpp"

Vertex::Vertex(const glm::vec4& pos, const glm::vec4& color){
    this->pos = pos;
    this->color = color;
}

Mesh::Mesh(Vertex* vertices, unsigned int vertex_count){
    // How many vertexes to draw (Since only allow triangles works it should always be 3)
    drawCount = vertex_count;

    // Generate vertex array object name (p1 = count to generate, p2 = arrptr)
    glGenVertexArrays(1, &vertexArrayObject);
    // Bind a vertex array object
    glBindVertexArray(vertexArrayObject);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    // Generate buffer object names for our vertices
    glGenBuffers(1, &vertexArrayBuffer);
    // Binds out Vertex buffer
    glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffer);
    glBufferData(GL_ARRAY_BUFFER, vertex_count * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);

    // Index, count, type, normalize, spacing, start
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 8*sizeof(GLfloat), 0);

    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 8*sizeof(GLfloat), (const void*)(4*sizeof(GLfloat)));

    glBindVertexArray(0);
}

Mesh::~Mesh(){
    glDeleteVertexArrays(1, &vertexArrayObject);
}

void Mesh::draw(){
    glBindVertexArray(vertexArrayObject);

    glDrawArrays(GL_TRIANGLES, 0, drawCount);

    glBindVertexArray(0);
}
