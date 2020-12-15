//
//  Application.cpp
//  MiniGame
//
//  Created by iprincewang on 2020/12/15.
//

#include "Application.hpp"

namespace GameEngine {

Application::Application(BaseGame *game) : _game(game) {
    
}

void Application::initialize() {
    cout << "Application init..." << endl;
    _graphics = new Graphics();
}

void Application::loop() {
    _game->update();
    _game->render();
}

void Application::ready(int width, int height) {
    cout << "Application ready..." << endl;
    
    this->width = width;
    this->height = height;
    _graphics->init();
}

void Application::Resized(int width, int height) {
    _game->resize(width, height);
}

void Application::pause() {
    _game->pause();
}

void Application::resume() {
    _game->resume();
}

void Application::finialize() {
    _game->finalize();
}



}
