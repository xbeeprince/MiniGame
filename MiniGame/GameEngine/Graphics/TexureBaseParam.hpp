//
//  TexureBaseParam.hpp
//  MiniGame
//
//  Created by iprincewang on 2020/12/18.
//

#ifndef TexureBaseParam_hpp
#define TexureBaseParam_hpp

#pragma once
#include "Game.hpp"

namespace GameEngine {

class TexureBaseParam {
protected:
    map<GLenum, GLint> params;
    virtual void initParam();
public:
    TexureBaseParam(){initParam();}
    map<GLenum, GLint>& getParams() { return  params;}
};
}

#endif /* TexureBaseParam_hpp */
