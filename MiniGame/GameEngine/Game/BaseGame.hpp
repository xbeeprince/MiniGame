//
//  BaseGame.hpp
//  MiniGame
//
//  Created by iprincewang on 2020/12/15.
//

#ifndef BaseGame_hpp
#define BaseGame_hpp

#include "Game.hpp"
#include "GameScence.hpp"

namespace GameEngine {

class BaseGame {
  
private:
public:
    BaseGame();
    ~BaseGame();
    
    virtual void initialize();
    virtual void ready();
    virtual void resize(int width, int height);
    virtual void update();
    virtual void render();
    virtual void pause();
    virtual void resume();
    virtual void finalize();
    
};
}

#endif /* BaseGame_hpp */
