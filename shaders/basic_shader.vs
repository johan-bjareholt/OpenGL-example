#version 130

#define PI 3.1415926535897932384626433832795

in vec4 v_position;
in vec4 v_color;

uniform vec4 camera;

void main(){
    // Default aspect ratio is 4:3
    const float ar  = 600.0/800.0;

    // Rotation
    float angx = 0;
    float angy = PI/4;
    float angz = 0;

    mat4 rotx = mat4(
        vec4(1.0,   0.0,        0.0,        0.0),
        vec4(0.0,   cos(angx),  -sin(angx), 0.0),
        vec4(0.0,   sin(angx),  cos(angx),  0.0),
        vec4(0.0,   0.0,        0.0,        1.0)
    );
    mat4 roty = mat4(
        vec4(cos(angy), 0.0,    -sin(angy), 0.0),
        vec4(0.0,       1.0,    0.0,        0.0),
        vec4(sin(angy), 0.0,    cos(angy),  0.0),
        vec4(0.0,       0.0,    0.0,        1.0)
    );
    mat4 rotz = mat4(
        vec4(cos(angz), -sin(angz), 0.0,    0.0),
        vec4(sin(angz), cos(angz),  0.0,    0.0),
        vec4(0.0,       0.0,        1.0,    0.0),
        vec4(0.0,       0.0,        0.0,    1.0)
    );
    mat4 rotation = rotz * rotx * roty;

    // Scaling
    float scale_f = 1.0;
    mat4 scale = mat4(
        vec4(scale_f, 0.0, 0.0, 0.0),
        vec4(0.0, scale_f, 0.0, 0.0),
        vec4(0.0, 0.0, scale_f, 0.0),
        vec4(0.0, 0.0, 0.0,     1.0)
    );

    gl_Position = vec4(scale * rotation * v_position) + camera;

    gl_FrontColor = v_color;
    gl_BackColor = v_color;
}
