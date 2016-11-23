#pragma once
#include <GL/glew.h>
#include <stdlib.h>

class Texture {
    public:
        GLuint width, height;
        GLuint id;
        GLfloat* pixels;

        Texture(int width, int height, unsigned char* pixels);
        ~Texture();

        void Bind(unsigned int unit);
};
