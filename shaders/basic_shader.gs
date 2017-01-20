#version 150

layout(triangles) in;
layout(triangle_strip, max_vertices = 3) out;

in vec2 texCoordVs[];
out vec2 texCoordGs;

void main()
{
    for (int i=0; i<gl_in.length(); i++){
        texCoordGs = texCoordVs[i];
        gl_Position = gl_in[i].gl_Position;
        EmitVertex();
    }
    EndPrimitive();
}