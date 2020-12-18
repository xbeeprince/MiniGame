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

class Buffer {
  
private:
    GLuint m_bufferId;
    
public:
    Buffer(const char *data, GLuint size);
    ~Buffer();
    void init(const char *data, GLuint size);
    
    void bind();
    void unbind();
};


}

#endif /* Buffer_hpp */
