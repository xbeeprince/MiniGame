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
#include "TexureBaseParam.hpp"

namespace GameEngine {
class TexureNomalParam : public TexureBaseParam {
private:
    void initParam() override {
        this->params[GL_TEXTURE_WRAP_S] = GL_REPEAT;
        this->params[GL_TEXTURE_WRAP_T] = GL_REPEAT;
    }
};
}



#endif /* TexureNormalParam_hpp */
