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

class TextureBuffer;

class Vertex {
private:
    float *m_array;
    int m_length;
    int m_count;
public:
    Vertex(float *array, int count, int length);
    ~Vertex();
    
    inline int getCount() {return m_count;}
    inline int getLength() {return m_length;}
    inline void* getData(){return  m_array;};
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
    TextureBuffer *m_texture;
    unsigned int m_drawCount;
public:
    Mesh(TextureBuffer *);
    Mesh(Vertex *vertex, int count, int drawCount);
    ~Mesh();
    
    void draw();
    
};
}

#endif /* Mesh_hpp */
