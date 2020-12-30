//
//  Mesh.cpp
//  MiniGame
//
//  Created by iprincewang on 2020/12/30.
//

#include "Mesh.hpp"

namespace GameEngine {


Vertex::Vertex(const float& array, int count) {
    m_array = new float(array);
    m_count = count;
}

Vertex::~Vertex() {
    delete [] m_array;
}


Mesh::Mesh() {
    
}

Mesh::Mesh(Vertex *vertex) {
    m_drawCount = vertex->getCount();
    glGenVertexArrays(1, &m_vertexArrayObject);
    glBindVertexArray(m_vertexArrayObject);
    
    
}

Mesh::~Mesh() {
    
}

void Mesh::draw() {
    
}

}
