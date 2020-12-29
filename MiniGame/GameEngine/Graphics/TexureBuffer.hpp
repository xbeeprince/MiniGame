//
//  TexureBuffer.hpp
//  MiniGame
//
//  Created by iprincewang on 2020/12/21.
//

#ifndef TexureBuffer_hpp
#define TexureBuffer_hpp

#include "Game.hpp"
#include "TexureBaseParam.hpp"

namespace GameEngine {

class TextureBuffer {
    
private:
    GLuint textureId;
    GLint format;
    
    struct Image {
        unsigned char* data = nullptr;
        int width;
        int height;
    } image;
  
public:
    TextureBuffer(const char *path, GLint format=GL_RGB);
    ~TextureBuffer();
    
    inline GLuint getTextureId() {return  textureId;}
    void bind();
    void unbind();
    
    void createMipMap(TexureBaseParam param);
    
};
}

#endif /* TexureBuffer_hpp */
