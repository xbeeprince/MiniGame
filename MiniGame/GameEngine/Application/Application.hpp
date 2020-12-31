//
//  Application.hpp
//  MiniGame
//
//  Created by iprincewang on 2020/12/15.
//

#ifndef Application_hpp
#define Application_hpp
#include "Graphics.hpp"
#include "BaseGame.hpp"

using  namespace GameEngine;

namespace GameEngine {

class Application {
  
private:
    int width;
    int height;
    Graphics *_graphics;
    BaseGame *_game;
    
public:
    Application(BaseGame*);
    ~Application();
    
    void initialize(string* resourcePath);
    void Resized(int width, int height);
    void ready(int width, int height);
    void pause();
    void resume();
    void finialize();
    void loop();
    
};
}

#endif /* Application_hpp */
