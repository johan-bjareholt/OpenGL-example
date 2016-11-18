#include <GL/glew.h>
#include <glm/glm.hpp>

class Vertex {
    public:
        Vertex(const glm::vec3& pos, const glm::vec3& color);
    protected:
    private:
        glm::vec3 pos;
        glm::vec3 color;
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

