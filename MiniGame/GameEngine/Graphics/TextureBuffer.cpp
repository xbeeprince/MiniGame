//
//  TexureBuffer.cpp
//  MiniGame
//
//  Created by iprincewang on 2020/12/21.
//

#include "TextureBuffer.hpp"
#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#endif
#include "Image.hpp"

namespace GameEngine {

TextureBuffer::TextureBuffer(const char* path, GLint format) {
    glGenTextures(1, &textureId);
    if (image.data) {
        stbi_image_free(image.data);
        image.data = nullptr;
    }
    int width, height, nChannel;
    unsigned char* data = stbi_load(path, &width, &height, &nChannel, 0);
    image.width = width;
    image.height = height;
    image.nChannel = nChannel;
    image.data = data;
}

TextureBuffer::~TextureBuffer() {
    if (image.data) {
        stbi_image_free(image.data);
        image.data = nullptr;
    }
}

void TextureBuffer::bind() {
    glBindTexture(GL_TEXTURE_2D, textureId);
}

void TextureBuffer::unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}

void TextureBuffer::createMipMap(TextureBaseParam* param) {
    bind();
    if (image.data) {
        
        map<GLenum, GLint> pa = param->getParams();
        for_each(pa.begin(), pa.end(), [](pair<GLenum, GLint> item)->void {
            glTexParameteri(GL_TEXTURE_2D, item.first, item.second);
        });
        
        if (image.nChannel == 3) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image.width, image.height, 0, GL_RGB, GL_UNSIGNED_BYTE, image.data);
        } else if (image.nChannel == 4) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.width, image.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.data);
        }
        
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    unbind();
}

}
