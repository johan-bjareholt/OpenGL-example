#version 130

#define PI 3.1415926535897932384626433832795

in vec4 v_position;
in vec4 v_color;

uniform vec4 camera;

void main(){
    float timer = PI/3;

    // Default aspect ratio is 4:3
    const float ar  = 600.0/800.0;
    const float ari = 800.0/600.0;

    const mat4 projection = mat4(
        vec4(ar,  0.0, 0.0, 0.0),
        vec4(0.0, 1.0, 0.0, 0.0),
        vec4(0.0, 0.0, 1.0, 0.0),
        vec4(0.0, 0.0, 0.0, 1.0)
    );

    mat4 rotation = mat4(
        vec4(1.0,         0.0,         0.0, 0.0),
        vec4(0.0,  cos(timer),  sin(timer), 0.0),
        vec4(0.0, -sin(timer),  cos(timer), 0.0),
        vec4(0.0,         0.0,         0.0, 1.0)
    );
    mat4 scale = mat4(
        vec4(ari, 0.0, 0.0, 0.0),
        vec4(0.0, 1.0, 0.0, 0.0),
        vec4(0.0, 0.0, 1.0, 0.0),
        vec4(0.0, 0.0, 0.0, 1.0)
    );

    gl_Position = (projection * rotation * scale * v_position) + camera;

    gl_FrontColor = v_color;
    gl_BackColor = v_color;
}
