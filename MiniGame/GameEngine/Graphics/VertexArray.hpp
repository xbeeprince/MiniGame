//
//  VertexArray.hpp
//  MiniGame
//
//  Created by iprincewang on 2020/12/18.
//

#ifndef VertexArray_hpp
#define VertexArray_hpp

#include "Game.hpp"
#include "VertexBuffer.hpp"

namespace GameEngine {

class VertexArray {
private:
    
    GLuint m_vertexArrayId;
    vector<VertexBuffer*> m_buffers;
  
public:
    VertexArray();
    ~VertexArray();
    
    void addBuffer(VertexBuffer *buffer, GLint length, GLint index);
    
    void bind();
    void unbind();
};
}

#endif /* VertexArray_hpp */
