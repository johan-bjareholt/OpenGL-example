#include <GL/glew.h>
#include <glm/glm.hpp>

class Vertex {
    public:
        Vertex(const glm::vec3& pos);
    protected:
    private:
        glm::vec3 pos;
};

class Mesh {
    public:
        Mesh(Vertex* vertices, unsigned int vertex_count);
        ~Mesh();
        void draw();
    private:
        enum {
            POSITION_VB,
            BUFFER_COUNT
        };

        GLuint vertexArrayObject;
        GLuint vertexArrayBuffers[BUFFER_COUNT];
        unsigned int drawCount;
};

