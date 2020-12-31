//
//  TestGame.cpp
//  MiniGame
//
//  Created by prince on 2020/12/31.
//

#include "TestGame.hpp"
#include "TextureNormalParam.hpp"
#include "Image.hpp"

namespace GameEngine {

TestGame::TestGame() {

}

TestGame::~TestGame() {
    
}

void TestGame::initialize(string *resPath) {
    this->_resourcePath = resPath;
    string *path = this->resPath();
    v_path = new string(*(path) + "/" + "shaders/vertex.glsl");
    f_path = new string(*(path) + "/" + "shaders/fragment.glsl");
    
    _shader = new ShaderManager();
    _shader->CompileShaders(*v_path, *f_path);
    _shader->LinkShaders();
    
    string image_path = string(*(path) + "/" + "images/mei.png");
    _texture = new TextureBuffer(image_path.c_str());
    TextureBaseParam *param = new TextureNormalParam();
    _texture->createMipMap(param);
    
    _mesh = new Mesh(_texture);
    
    _shader->Use();
    GLint textureLoc = _shader->GetUniformLocation("ourTexture");
    glUniform1i(textureLoc, 0);
    _shader->UnUse();
    
}

void TestGame::ready() {
    
}

void TestGame::resize(int width, int height) {
    
}

void TestGame::update() {
    cout << "SampleGame update..." << endl;
}

void TestGame::render() {
    cout << "SampleGame render..." << endl;
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    _shader->Use();
    glActiveTexture(GL_TEXTURE0);
    _mesh->draw();
    _shader->UnUse();
    
//    delete texture_buffer;
}

void TestGame::pause() {
    
}

void TestGame::resume() {
    
}

void TestGame::finalize() {
    
}
}
