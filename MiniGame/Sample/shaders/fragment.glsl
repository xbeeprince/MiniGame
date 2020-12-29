
#version 300 es
in mediump vec3 textureUV;
out mediump vec4 FragColor;

uniform sampler2D textureCord;

void main()
{
    FragColor = texture(textureCord, vec2(textureUV.x, textureUV.y));
}
