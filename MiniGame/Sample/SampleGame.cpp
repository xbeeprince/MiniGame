//
//  SampleGame.cpp
//  MiniGame
//
//  Created by iprincewang on 2020/12/15.
//

#include "SampleGame.hpp"
#include "TexureBuffer.hpp"

float vertex[] = {
    -0.5, -0.5, 0.0,
    0.5, -0.5, 0.0,
    0.5, 0.5, 0.0,
    0.5, 0.5, 0.0,
    -0.5, 0.5, 0.0,
    -0.5, -0.5, 0.0
};

float texture[] = {
    1.0, 0.0, 0.0,
    1.0, 1.0, 0.0,
    1.0, 1.0, 1.0,
    1.0, 1.0, 1.0,
    0.0, 1.0, 1.0,
    0.0, 0.0, 1.0,
};

SampleGame::SampleGame() {

}

SampleGame::~SampleGame() {
    
}

void SampleGame::initResourcePath(string *resource) {
    this->resourcePath = resource;
    v_path = new string(*(this->resourcePath) + "/" + "shaders/vertex.glsl");
    f_path = new string(*(this->resourcePath) + "/" + "shaders/fragment.glsl");
}

void SampleGame::initialize() {
    shader = new ShaderManager();
    shader->CompileShaders(*v_path, *f_path);
    shader->LinkShaders();
    
    shader->Use();
    vao = new VertexArray();
    vao->bind();
    Buffer *v_buffer = new Buffer((const char *)vertex, sizeof(vertex));
    vao->addBuffer(v_buffer, 3, 0);
    
    Buffer* t_buffer = new Buffer((const char *)texture, sizeof(texture));
    vao->addBuffer(t_buffer, 4, 1);
    
    
    
    string image_path = string(*(this->resourcePath) + "/" + "images/web.jpg");
    TextureBuffer *texture_buffer = new TextureBuffer(image_path.c_str());
    GLint textureLoc = shader->GetUniformLocation("textureCord");
    glUniform1i(textureLoc, 0);
    glActiveTexture(0);
    texture_buffer->bind();
    
    vao->unbind();
    shader->UnUse();
}

void SampleGame::ready() {
    
}

void SampleGame::resize(int width, int height) {
    
}

void SampleGame::update() {
    cout << "SampleGame update..." << endl;
}

void SampleGame::render() {
    cout << "SampleGame render..." << endl;
    shader->Use();
    vao->bind();
    

    glDrawArrays(GL_TRIANGLES, 0, 6);
    vao->unbind();
    shader->UnUse();
}

void SampleGame::pause() {
    
}

void SampleGame::resume() {
    
}

void SampleGame::finalize() {
    
}

