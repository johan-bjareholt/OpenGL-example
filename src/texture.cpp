#include "texture.hpp"
#include <cassert>

Texture::Texture(int width, int height, unsigned char* pixels){
    /*
        Input must be a unsigned RGB char array
    */
    this->width = width;
    this->height = height;

    glGenTextures(1, &id); // Generate texture
    glBindTexture(GL_TEXTURE_2D, id); // Bind texture as 2D texture

    // Wrap and repeat texture
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // How it handles iterpolating texture rotation
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Target, mipmaplevel, internalbufferformat (RGBA, RGB), width, height, border(?), inputformat (RGB, RGBA), inputtype, pointer)
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
}

Texture::~Texture(){
    glDeleteTextures(1, &id);
}

void Texture::bind(unsigned int unit){
    assert( unit >= 0 && unit < 32);
    glActiveTexture(GL_TEXTURE0+unit); // Set texture as TEXTURE(unit)
    glBindTexture(GL_TEXTURE_2D, id);
}
