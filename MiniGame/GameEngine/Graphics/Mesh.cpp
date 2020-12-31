//
//  Mesh.cpp
//  MiniGame
//
//  Created by iprincewang on 2020/12/30.
//

#include "Mesh.hpp"
#include "TextureBuffer.hpp"

namespace GameEngine {

//形状坐标
static float kVertex[] = {
    0.5f, 0.5f, 0.0f,   // 右上角
    0.5f, -0.5f, 0.0f,  // 右下角
    -0.5f, -0.5f, 0.0f, // 左下角
    -0.5f, 0.5f, 0.0f,  // 左上角
    0.5f, 0.5f, 0.0f,   // 右上角
    -0.5f, -0.5f, 0.0f, // 左下角
};

//坐标颜色
static float kColor[] = {
    1.0f, 0.0f, 0.0f,   // 右上角
    0.0f, 1.0f, 0.0f,   // 右下角
    0.0f, 0.0f, 1.0f,   // 左下角
    1.0f, 1.0f, 0.0f,   // 左上角
    1.0f, 0.0f, 0.0f,   // 右上角
    0.0f, 0.0f, 1.0f,   // 左下角
};

//纹理坐标
static float kTexture[] = {
    0, 0,   //左上
    1, 0,   //右上
    1, 1,   //右下
    0, 1,   //左下
    0, 0,   //左上
    1, 1,   //右下
};


Vertex::Vertex(float* array, int count, int length) {
    m_array = array;
    m_count = count;
    m_length = length;
}

Vertex::~Vertex() {
    
}


Mesh::Mesh(TextureBuffer *texture) {
    m_texture = texture;
    m_drawCount = sizeof(kVertex) / kVertex[0];
    Vertex vertex[NUM_BUFFERS] = {
        Vertex(kVertex, sizeof(kVertex), 3),
        Vertex(kColor, sizeof(kColor), 3),
        Vertex(kTexture, sizeof(kTexture), 2),
    };
    
    //VAO
    glGenVertexArrays(1, &m_vertexArrayObject);
    
    //绑定
    glBindVertexArray(m_vertexArrayObject);
    
    //VBO
    glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
    
    for (int i = 0; i < NUM_BUFFERS; i++) {
        glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[i]);
        glBufferData(GL_ARRAY_BUFFER, vertex[i].getCount(), vertex[i].getData(), GL_STATIC_DRAW);
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, vertex[i].getLength(), GL_FLOAT, GL_FALSE, 0, 0);
    }
    
    //解绑
    glBindVertexArray(0);
}

Mesh::Mesh(Vertex *vertex, int count, int drawCount) {
    m_drawCount = drawCount;
    //VAO
    glGenVertexArrays(1, &m_vertexArrayObject);
    
    //绑定
    glBindVertexArray(m_vertexArrayObject);
    
    //VBO
    glGenBuffers(count, m_vertexArrayBuffers);
    
    for (int i = 0; i < count; i++) {
        glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[i]);
        glBufferData(GL_ARRAY_BUFFER, vertex[i].getCount(), vertex[i].getData(), GL_STATIC_DRAW);
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, vertex[i].getLength(), GL_FLOAT, GL_FALSE, 0, 0);
    }
    
    //解绑
    glBindVertexArray(0);
}

Mesh::~Mesh() {
    
}

void Mesh::draw() {
    glBindVertexArray(m_vertexArrayObject);
    m_texture->bind();
    glDrawArrays(GL_TRIANGLES, 0, m_drawCount);
    m_texture->unbind();
    glBindVertexArray(0);
}

}
