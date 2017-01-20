#include <GL/glew.h>

class Shader {
    private:
        static const unsigned int NUM_SHADERS = 3;
        GLuint shaders[NUM_SHADERS];

    public:
        Shader(const std::string filename);
        ~Shader();
        GLuint program;
        void bind();

    private:
        GLuint create_shader(const std::string& text, GLenum shader_type, const std::string name);
        std::string load_shader(const std::string& fileName);

        void check_shader_error(GLuint shader, GLuint flag, const std::string& shadername);
        void check_program_error(GLuint program, GLuint flag, const std::string& progname, const std::string& stage);
};

