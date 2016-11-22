#include <GL/glew.h>
#include <glm/glm.hpp>

class Vertex {
    public:
        Vertex(const glm::vec4& pos, const glm::vec4& color);
    protected:
    private:
        glm::vec4 pos;
        glm::vec4 color;
};

class Mesh {
    public:
        Mesh(Vertex* vertices, unsigned int vertex_count);
        ~Mesh();
        void draw();
    private:

        GLuint vertexArrayObject;
        GLuint vertexArrayBuffer;
        unsigned int drawCount;
};

