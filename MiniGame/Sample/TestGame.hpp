//
//  TestGame.hpp
//  MiniGame
//
//  Created by prince on 2020/12/31.
//

#ifndef TestGame_hpp
#define TestGame_hpp

#include "Game.hpp"
#include "BaseGame.hpp"
#include "VertexArray.hpp"
#include "VertexBuffer.hpp"
#include "ShaderManager.hpp"
#include "TextureBuffer.hpp"
#include "Mesh.hpp"

namespace GameEngine {

class TestGame : public BaseGame {
private:
    string *v_path;
    string *f_path;
    ShaderManager *_shader;
    Mesh *_mesh;
    TextureBuffer *_texture;

public:
    TestGame();
    ~TestGame();
    
    virtual void initialize(string *resPath);
    virtual void ready();
    virtual void resize(int width, int height);
    virtual void update();
    virtual void render();
    virtual void pause();
    virtual void resume();
    virtual void finalize();
};
}

#endif /* TestGame_hpp */
