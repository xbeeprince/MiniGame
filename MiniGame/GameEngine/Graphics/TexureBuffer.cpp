//
//  TexureBuffer.cpp
//  MiniGame
//
//  Created by iprincewang on 2020/12/21.
//

#include "TexureBuffer.hpp"
#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#endif
#include "Image.hpp"

namespace GameEngine {

TextureBuffer::TextureBuffer(const char* path, GLint format) {
    glGenTextures(1, &textureId);
    image.data = stbi_load(path, &image.width, &image.height, nullptr, 0);
}

TextureBuffer::~TextureBuffer() {
    if (image.data) {
        stbi_image_free(image.data);
    }
}

void TextureBuffer::bind() {
    glBindTexture(GL_TEXTURE_2D, textureId);
}

void TextureBuffer::unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}

void TextureBuffer::createMipMap(TexureBaseParam param) {
    
    bind();
    
    if (image.data) {
        
        map<GLenum, GLint> pa = param.getParams();
        for_each(pa.begin(), pa.end(), [](pair<GLenum, GLint> item)->void {
            glTexParameteri(GL_TEXTURE_2D, item.first, item.second);
        });
        
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RG8, image.width, image.height, 0, GL_RG8, GL_UNSIGNED_BYTE, image.data);
        stbi_image_free(image.data);
    }
    
    unbind();
}

}
