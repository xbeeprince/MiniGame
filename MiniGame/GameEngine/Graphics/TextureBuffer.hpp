//
//  TexureBuffer.hpp
//  MiniGame
//
//  Created by iprincewang on 2020/12/21.
//

#ifndef TexureBuffer_hpp
#define TexureBuffer_hpp

#include "Game.hpp"
#include "TextureBaseParam.hpp"

namespace GameEngine {

class TextureBuffer {
    
private:
    GLuint textureId;
    GLint format;
    
    struct Image {
        unsigned char* data = nullptr;
        int width;
        int height;
        int nChannel;
    } image;
  
public:
    TextureBuffer(const char *path, GLint format=GL_RGB);
    ~TextureBuffer();
    
    inline GLuint getTextureId() {return  textureId;}
    void bind();
    void unbind();
    
    void createMipMap(TextureBaseParam* param);
    
};
}

#endif /* TexureBuffer_hpp */
