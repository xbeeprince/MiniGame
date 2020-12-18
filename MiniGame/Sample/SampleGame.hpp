//
//  SampleGame.hpp
//  MiniGame
//
//  Created by iprincewang on 2020/12/15.
//

#ifndef SampleGame_hpp
#define SampleGame_hpp

#include "BaseGame.hpp"
#include "VertexArray.hpp"
#include "Buffer.hpp"
#include "ShaderManager.hpp"

using namespace GameEngine;

class SampleGame : public BaseGame {
private:
    string *resourcePath;
    string *v_path;
    string *f_path;
    ShaderManager *shader;
    VertexArray *vao;
public:
    SampleGame();
    ~SampleGame();
    void initResourcePath(string *resource);
    
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
