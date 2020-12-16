//
//  Texture.hpp
//  MiniGame
//
//  Created by iprincewang on 2020/12/16.
//

#ifndef Texture_hpp
#define Texture_hpp

#include "Game.hpp"
#define STB_IMAGE_IMPLEMENTATION

namespace GameEngine {

class Texture {
  
private:
    unsigned char *data;
    int width;
    int height;
public:
    Texture();
    Texture(unsigned char *data, int width, int height);
    Texture(const string& path);
    ~Texture();
};
}

#endif /* Texture_hpp */
