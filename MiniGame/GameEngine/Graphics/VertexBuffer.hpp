//
//  Buffer.hpp
//  MiniGame
//
//  Created by iprincewang on 2020/12/18.
//

#ifndef Buffer_hpp
#define Buffer_hpp

#include "Game.hpp"

namespace GameEngine {

class VertexBuffer {
  
private:
    GLuint m_bufferId;
    
public:
    VertexBuffer(const char *data, GLuint size);
    ~VertexBuffer();
    void init(const char *data, GLuint size);
    
    void bind();
    void unbind();
};


}

#endif /* Buffer_hpp */
