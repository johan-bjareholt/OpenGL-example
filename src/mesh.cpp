#include <GL/glew.h>
#include <glm/glm.hpp>

#include "mesh.hpp"

Vertex::Vertex(const glm::vec3& pos){
    this->pos = pos;
}

Mesh::Mesh(Vertex* vertices, unsigned int vertex_count){
    drawCount = vertex_count;

    glGenVertexArrays(1, &vertexArrayObject);
    glBindVertexArray(vertexArrayObject);

    glGenBuffers(BUFFER_COUNT, vertexArrayBuffers);
    glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER, vertex_count * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    // Index, count, type, normalize, spacing, start
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

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
