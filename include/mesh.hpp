#include <GL/glew.h>
#include <glm/glm.hpp>

class Vertex {
    public:
        glm::vec4 pos;
        glm::vec2 texcoord;
        Vertex(const glm::vec4& pos, const glm::vec2& texcoord);
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

        unsigned int drawCount;
};

