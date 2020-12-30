//
//  TexureNormalParam.hpp
//  MiniGame
//
//  Created by iprincewang on 2020/12/18.
//

#ifndef TexureNormalParam_hpp
#define TexureNormalParam_hpp

#pragma once
#include "Game.hpp"
#include "TextureBaseParam.hpp"

namespace GameEngine {
class TextureNormalParam : public TextureBaseParam {
public:
    TextureNormalParam() {
        cout << "TextureNormalParam()" << endl;
        initParam();
    }
    ~TextureNormalParam() {
        cout << "~TextureNormalParam()" << endl;
    }
protected:
    void initParam() {
        cout << "TextureNormalParam initParam" << endl;
        this->params[GL_TEXTURE_WRAP_S] = GL_REPEAT;
        this->params[GL_TEXTURE_WRAP_T] = GL_REPEAT;
        this->params[GL_TEXTURE_MIN_FILTER] = GL_LINEAR;
        this->params[GL_TEXTURE_MAG_FILTER] = GL_LINEAR;
    }
};
}



#endif /* TexureNormalParam_hpp */
