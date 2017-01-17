#version 130

#define PI 3.1415926535897932384626433832795

// Vector attributes
in vec4 v_position;
in vec2 v_texcoord;

// Fragment shader arguments
out vec2 texCoord0;

// Uniforms
uniform vec4 w_position;
uniform vec4 cam_pos;
//uniform mat4 view_mat;
//uniform mat4 proj_mat;

void main(){
    // Default aspect ratio is 4:3
    const float ar  = 600.0/800.0;

    // Rotation
    float angx = 0;//PI/4;
    float angy = 0;//PI/4;
    float angz = 0;//PI/4;

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

    //if (v_texcoord.x != 0 && v_texcoord.y != 0)
    //if (v_rotation.x != 0 && v_rotation.y != 0)
    //gl_Position = vec4(v_position.x, v_position.y, 0, 1) - cam_pos - w_position;
    //else
    //    gl_Position = vec4(0,0,0,0);
    gl_Position = vec4(scale * rotation * v_position) - cam_pos - w_position;
    //gl_Position = vec4(v_texcoord.s, v_texcoord.t, 0, 0) - cam_pos - w_position;

    //gl_FrontColor = v_color;

    texCoord0 = v_texcoord;
}
