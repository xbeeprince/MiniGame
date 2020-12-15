//
//  SampleGame.hpp
//  MiniGame
//
//  Created by iprincewang on 2020/12/15.
//

#ifndef SampleGame_hpp
#define SampleGame_hpp

#include "BaseGame.hpp"
using namespace GameEngine;

class SampleGame : public BaseGame {
private:
public:
    SampleGame();
    ~SampleGame();
    
    virtual void initialize();
    virtual void ready();
    virtual void resize(int width, int height);
    virtual void update();
    virtual void render();
    virtual void pause();
    virtual void resume();
    virtual void finalize();
};

#endif /* SampleGame_hpp */
