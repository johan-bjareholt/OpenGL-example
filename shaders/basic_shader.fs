#version 130

in vec2 texCoord0;
out vec4 color;

uniform sampler2D diffuse;

void main(){
    //color = vec4(1,0,1,1);
    color = texture(diffuse, vec2(texCoord0.s, (1-texCoord0.t)));
}
