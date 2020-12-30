//
//  SampleGame.cpp
//  MiniGame
//
//  Created by iprincewang on 2020/12/15.
//

#include "SampleGame.hpp"
#include "TextureNormalParam.hpp"
#include "Image.hpp"

//形状坐标
float vertex[] = {
    0.5f, 0.5f, 0.0f,   // 右上角
    0.5f, -0.5f, 0.0f,  // 右下角
    -0.5f, -0.5f, 0.0f, // 左下角
    -0.5f, 0.5f, 0.0f   // 左上角
};

//坐标颜色
float color[] = {
    1.0f, 0.0f, 0.0f,   // 右上角
    0.0f, 1.0f, 0.0f,   // 右下角
    0.0f, 0.0f, 1.0f,   // 左下角
    1.0f, 1.0f, 0.0f    // 左上角
};

//纹理坐标
float texture[] = {
    0, 0,   //左上
    1, 0,   //右上
    1, 1,   //右下
    0, 1    //左下
};

GLuint indices[] = {  // Note that we start from 0!
    0, 1, 3, // First Triangle
    1, 2, 3  // Second Triangle
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
    _shader = new ShaderManager();
    _shader->CompileShaders(*v_path, *f_path);
    _shader->LinkShaders();
    
    _vao = new VertexArray();
    
    VertexBuffer *v_buffer = new VertexBuffer((const char *)vertex, sizeof(vertex));
    _vao->addBuffer(v_buffer, 3, 0);
    
    VertexBuffer *c_buffer = new VertexBuffer((const char *)color, sizeof(color));
    _vao->addBuffer(c_buffer, 3, 1);
    
    VertexBuffer* t_buffer = new VertexBuffer((const char *)texture, sizeof(texture));
    _vao->addBuffer(t_buffer, 2, 2);
    
    _vao->bind();
    glGenBuffers(1, &_ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    _vao->unbind();
    
    string image_path = string(*(this->resourcePath) + "/" + "images/mei.png");
    _texture_buffer = new TextureBuffer(image_path.c_str());
    TextureBaseParam *param = new TextureNormalParam();
    _texture_buffer->createMipMap(param);
    
    _shader->Use();
    GLint textureLoc = _shader->GetUniformLocation("ourTexture");
    glUniform1i(textureLoc, 0);
    _shader->UnUse();
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
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    _shader->Use();
    _vao->bind();
    
    glActiveTexture(GL_TEXTURE0);
    _texture_buffer->bind();
    
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    _texture_buffer->unbind();
    _vao->unbind();
    _shader->UnUse();
    
//    delete texture_buffer;
}

void SampleGame::pause() {
    
}

void SampleGame::resume() {
    
}

void SampleGame::finalize() {
    
}

