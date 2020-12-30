//
//  VertexArray.cpp
//  MiniGame
//
//  Created by iprincewang on 2020/12/18.
//

#include "VertexArray.hpp"

namespace GameEngine {

VertexArray::VertexArray() {
    glGenVertexArrays(1, &m_vertexArrayId);
}

VertexArray::~VertexArray () {
    for_each(m_buffers.begin(), m_buffers.end(), [](VertexBuffer *buffer)->void {
        buffer->unbind();
        delete buffer;
    });
    unbind();
}

void VertexArray::addBuffer(VertexBuffer *buffer, GLint length, GLint index) {
    bind();
    
    buffer->bind();
    glEnableVertexAttribArray(index);
    glVertexAttribPointer(index, length, GL_FLOAT, GL_FALSE, 0, 0);
    buffer->unbind();
    
    unbind();
}

void VertexArray::bind() {
    glBindVertexArray(m_vertexArrayId);
}

void VertexArray::unbind() {
    glBindVertexArray(0);
}


}
