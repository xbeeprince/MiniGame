//
//  Buffer.cpp
//  MiniGame
//
//  Created by iprincewang on 2020/12/18.
//

#include "Buffer.hpp"

namespace GameEngine {

Buffer::Buffer(const char *data, GLuint size) {
    init(data, size);
}

Buffer::~Buffer() {
    unbind();
}

void Buffer::init(const char *data, GLuint size) {
    glGenBuffers(1, &m_bufferId);
    bind();
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    unbind();
}

void Buffer::bind() {
    glBindBuffer(GL_ARRAY_BUFFER, m_bufferId);
}

void Buffer::unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
}
