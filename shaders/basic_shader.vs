#version 130

in vec3 v_position;
in vec3 v_color;

void main(){
    gl_FrontColor = vec4(v_color, 1.0);
    gl_BackColor = vec4(v_color, 1.0);
    gl_Position = vec4(v_position, 1.0);
}
