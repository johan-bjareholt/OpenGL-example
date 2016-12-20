#version 130

in vec2 texCoord0;

uniform sampler2D diffuse;

void main(){
    //gl_FragColor = vec4(1,0,1,1);
    gl_FragColor = texture(diffuse, vec2(texCoord0.s, (1-texCoord0.t)));
}
