#include "texture.hpp"

Texture::Texture(int width, int height, unsigned char* pixels){
    this->width = width;
    this->height = height;
    this->pixels = (GLfloat*) malloc(width*height*sizeof(GLfloat));
    for (int hi=0; hi<height; hi++){
        for (int wi=0; wi<width; wi++){
            this->pixels[(hi*width)+wi] = pixels[(hi*width)+wi] / 255.0;
        }
    }
}

Texture::~Texture(){
    free(this->pixels);
}

void Texture::Bind(unsigned int unit){

}
