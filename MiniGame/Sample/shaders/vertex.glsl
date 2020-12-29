
#version 300 es
layout (location = 0) in vec3 vertexPosition;
layout (location = 1) in vec3 texturePosition;

out mediump vec3 textureUV;

void main()
{
    gl_Position = vec4(vertexPosition.x, vertexPosition.y, vertexPosition.z, 1.0);
    textureUV = texturePosition;
}
