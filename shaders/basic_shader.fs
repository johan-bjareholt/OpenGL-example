#version 130

in vec2 texCoordGs;
out vec4 color;

uniform sampler2D diffuse;

void main(){
    //color = vec4(1,0,1,1);
    color = texture(diffuse, vec2(texCoordGs.s, (1-texCoordGs.t)));
}
