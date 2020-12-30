
#version 300 es

in mediump vec4 ourColor;
in mediump vec2 TexCoord;

out mediump vec4 color;

uniform sampler2D ourTexture;

void main()
{
    color = texture(ourTexture, TexCoord);
//    color = vec4(ourColor, 1.0f);
}
