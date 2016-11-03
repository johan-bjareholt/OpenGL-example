#include <GL/glew.h>

class Shader {
    private:
        static const unsigned int NUM_SHADERS = 2;
        GLuint program;
        GLuint shaders[NUM_SHADERS];

    public:
        Shader(const std::string filename);
        ~Shader();
        void bind();
    
    private:
        GLuint create_shader(const std::string& text, GLenum shader_type);
        std::string load_shader(const std::string& fileName);

        void check_shader_error(GLuint shader, GLuint flag, const std::string& errorMessage);
        void check_program_error(GLuint program, GLuint flag, const std::string& errorMessage);
};

