
#version 300 es
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 texCoord;

out mediump vec4 outColor;
out mediump vec2 TexCoord;

void main()
{
    gl_Position = vec4(position, 1.0f);
    outColor = vec4(color, 1.0f);
    TexCoord = texCoord;
}
