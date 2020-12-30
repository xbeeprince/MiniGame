//
//  Mesh.hpp
//  MiniGame
//
//  Created by iprincewang on 2020/12/30.
//

#ifndef Mesh_hpp
#define Mesh_hpp

#include "Game.hpp"

namespace GameEngine {

class Vertex {
private:
    float *m_array;
    int m_count;
public:
    Vertex(const float& array, int count);
    ~Vertex();
    
    inline int getCount() {return m_count;}
};

class Mesh {
  
private:
    enum {
        POSITION = 0,
        COLOR,
        TEXTURE,
        NUM_BUFFERS
    };
    
    GLuint m_vertexArrayObject;
    GLuint m_vertexArrayBuffers[NUM_BUFFERS];
    unsigned int m_drawCount;
public:
    Mesh();
    Mesh(Vertex *vertex);
    ~Mesh();
    
    void draw();
    
};
}

#endif /* Mesh_hpp */
