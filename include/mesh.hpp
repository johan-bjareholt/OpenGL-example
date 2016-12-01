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
        Mesh(GLuint program, Vertex* vertices, unsigned int vertex_count, const glm::vec4& pos, const glm::vec3& rotation);
        ~Mesh();
        void draw();
    private:
        GLuint program;
        GLuint uniform_wpos_id;

        glm::vec4 pos;
        glm::vec3 rotation;

        GLuint vertexArrayObject;

        GLuint vertexArrayBuffer;
        GLuint worldPositionBuffer;

        unsigned int drawCount;
};

