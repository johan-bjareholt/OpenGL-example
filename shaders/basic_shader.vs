#version 130

#define PI 3.1415926535897932384626433832795

// Vector attributes
in vec4 v_position;
in vec2 v_texcoord;

// Fragment shader arguments
out vec2 texCoordVs;

// Uniforms
uniform vec4 w_position;
uniform vec4 cam_pos;

uniform mat4 mvp_mat;

void main(){
    //gl_Position = v_position-w_position;
    gl_Position = vec4(v_position-w_position);

    texCoordVs = v_texcoord;
    //gl_FrontColor = v_color;
}
