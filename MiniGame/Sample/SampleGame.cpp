//
//  SampleGame.cpp
//  MiniGame
//
//  Created by iprincewang on 2020/12/15.
//

#include "SampleGame.hpp"


float vertex[] = {
    -0.5, -0.5, 0.0,
    0.5, -0.5, 0.0,
    0.5, 0.5, 0.0,
    0.5, 0.5, 0.0,
    -0.5, 0.5, 0.0,
    -0.5, -0.5, 0.0
};

float color[] = {
    1.0, 0.0, 0.0, 1.0,
    1.0, 1.0, 0.0, 1.0,
    1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0,
    0.0, 1.0, 1.0, 1.0,
    0.0, 0.0, 1.0, 1.0
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
    Buffer *vertext_buffer = new Buffer((const char *)vertex, sizeof(vertex));
    vao->addBuffer(vertext_buffer, 3, 0);
    
    Buffer* color_buffer = new Buffer((const char *)color, sizeof(color));
    vao->addBuffer(color_buffer, 4, 1);
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

