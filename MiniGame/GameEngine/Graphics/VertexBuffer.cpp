//
//  Buffer.cpp
//  MiniGame
//
//  Created by iprincewang on 2020/12/18.
//

#include "VertexBuffer.hpp"

namespace GameEngine {

VertexBuffer::VertexBuffer(const char *data, GLuint size) {
    init(data, size);
}

VertexBuffer::~VertexBuffer() {
    unbind();
}

void VertexBuffer::init(const char *data, GLuint size) {
    glGenBuffers(1, &m_bufferId);
    glBindBuffer(GL_ARRAY_BUFFER, m_bufferId);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::bind() {
    glBindBuffer(GL_ARRAY_BUFFER, m_bufferId);
}

void VertexBuffer::unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
}
