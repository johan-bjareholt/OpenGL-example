#version 150

layout(triangles) in;
layout(triangle_strip, max_vertices = 3) out;

in vec2 texCoordVs[];
out vec2 texCoordGs;

uniform mat4 mvp_mat;

void main()
{
    vec3 l1 = gl_in[1].gl_Position.xyz - gl_in[0].gl_Position.xyz;
    vec3 l2 = gl_in[2].gl_Position.xyz - gl_in[0].gl_Position.xyz;

    vec3 norm = normalize(cross(l1, l2));

    for (int i=0; i<gl_in.length(); i++){
        gl_Position = mvp_mat * (gl_in[i].gl_Position+2*vec4(norm, 0.0));
        texCoordGs = texCoordVs[i];
        EmitVertex();
    }
    EndPrimitive();
    /*
    for (int i=0; i<gl_in.length(); i++){
        gl_Position = mvp_mat * (gl_in[i].gl_Position);
        texCoordGs = texCoordVs[i];
        EmitVertex();
    }
    EndPrimitive();
    */

}
