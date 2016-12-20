#pragma once
#include <GL/glew.h>
#include <stdlib.h>

class Texture {
    public:
        GLuint width, height;
        GLuint id;

        Texture(int width, int height, unsigned char* pixels);
        ~Texture();

        void bind(unsigned int unit);
};
