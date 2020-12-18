
#version 300 es
layout (location = 0) in vec3 position;
layout (location = 1) in mediump vec4 color;

out mediump vec4 outColor;

void main()
{
    outColor = color;
    gl_Position = vec4(position.x, position.y, position.z, 1.0);
}
