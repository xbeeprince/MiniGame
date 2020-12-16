//
//  Quad.cpp
//  MiniGame
//
//  Created by iprincewang on 2020/12/16.
//

#include "Quad.hpp"

namespace GameEngine {

Quad::Quad() {
    
}

Quad::Quad(float x, float y, float w, float h) {
    this->x = x;
    this->y = y;
    this->width = w;
    this->height = h;
}

}
