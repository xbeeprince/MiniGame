//
//  BaseGame.cpp
//  MiniGame
//
//  Created by iprincewang on 2020/12/15.
//

#include "BaseGame.hpp"
namespace GameEngine {

BaseGame::BaseGame() {
    
}

BaseGame::~BaseGame() {
    
}

void BaseGame::initialize(string *resPath) {
    _resourcePath = resPath;
}

void BaseGame::ready() {
    
}

void BaseGame::resize(int width, int height) {
    
}

void BaseGame::update() {
    cout << "BaseGame update..." << endl;
}

void BaseGame::render() {
    cout << "BaseGame update..." << endl;
}

void BaseGame::pause() {
    
}

void BaseGame::resume() {
    
}

void BaseGame::finalize() {
    
}

}
