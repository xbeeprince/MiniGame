
#version 300 es

in mediump vec4 outColor;
in mediump vec2 TexCoord;

out mediump vec4 color;

uniform sampler2D ourTexture;

void main()
{
    color = texture(ourTexture, TexCoord);
    //color = outColor;
}
