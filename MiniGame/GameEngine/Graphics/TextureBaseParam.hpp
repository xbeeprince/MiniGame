//
//  TexureBaseParam.hpp
//  MiniGame
//
//  Created by iprincewang on 2020/12/18.
//

#ifndef TextureBaseParam_hpp
#define TextureBaseParam_hpp

#pragma once
#include "Game.hpp"

namespace GameEngine {

class TextureBaseParam {
protected:
    map<GLenum, GLint> params;
    virtual void initParam() = 0;
public:
    TextureBaseParam() {
        cout << "TextureBaseParam()" << endl;
    }
    ~TextureBaseParam() {
        cout << "~TextureBaseParam()" << endl;
    }
    map<GLenum, GLint>& getParams() { return  this->params;}
};
}

#endif /* TexureBaseParam_hpp */
