#include <iostream>
#include <fstream>
#include <sstream>

#include <GL/glew.h>

#include "shader.hpp"

Shader::Shader(const std::string filename){
    this->program = glCreateProgram();

    shaders[0] = create_shader(load_shader(filename+".vs"), GL_VERTEX_SHADER);
    shaders[1] = create_shader(load_shader(filename+".fs"), GL_FRAGMENT_SHADER);

    for (unsigned int i=0; i < NUM_SHADERS; i++)
        glAttachShader(program, shaders[i]);

    glBindAttribLocation(program, 0, "position");

    glLinkProgram(program);
    check_program_error(program, GL_LINK_STATUS, "Error: Program linking failed");

    glValidateProgram(program);
    check_program_error(program, GL_VALIDATE_STATUS, "Error: Program is invalid");
}

Shader::~Shader(){
    for (unsigned int i=0; i < NUM_SHADERS; i++){
        glDetachShader(program, shaders[i]);
        glDeleteShader(shaders[i]);
    }

    glDeleteProgram(program);
}

void Shader::bind(){
    glUseProgram(program);
}

GLuint Shader::create_shader(const std::string& text, GLenum shader_type){
    GLuint shader = glCreateShader(shader_type);
    if (shader == 0)
        std::cerr << "Error: Shader creation failed" << std::endl;

    const GLchar* shaderSourceStrings[1];
    GLint shaderSourceStringLengths[1];

    shaderSourceStrings[0] = text.c_str();
    shaderSourceStringLengths[0] = text.length();

    glShaderSource(shader, 1, shaderSourceStrings, shaderSourceStringLengths);
    glCompileShader(shader);

    check_shader_error(shader, GL_COMPILE_STATUS, "Error: Shader compilation failed");

    return shader;
}

std::string Shader::load_shader(const std::string& fileName)
{
    std::ifstream file(fileName);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

void Shader::check_shader_error(GLuint shader, GLuint flag, const std::string& errorMessage){
    GLint success = 0;
    GLchar error[1024] = { 0 };

    glGetShaderiv(shader, flag, &success);

    if(success == GL_FALSE){
        glGetShaderInfoLog(shader, sizeof(error), NULL, error);
        std::cerr << errorMessage << ": '" << error << "'" << std::endl;
    }
}

void Shader::check_program_error(GLuint program, GLuint flag, const std::string& errorMessage){
    GLint success = 0;
    GLchar error[1024] = { 0 };
    glGetProgramiv(program, flag, &success);

    if(success == GL_FALSE){
        glGetProgramInfoLog(program, sizeof(error), NULL, error);
        std::cerr << errorMessage << ": '" << error << "'" << std::endl;
    }
}
