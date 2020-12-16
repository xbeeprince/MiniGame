//
//  Texture.cpp
//  MiniGame
//
//  Created by iprincewang on 2020/12/16.
//

#include "Texture.hpp"
#include "Image.hpp"

namespace GameEngine {

Texture::Texture() {
    
}

Texture::Texture(unsigned char *data, int width, int height) {
    this->data = data;
    this->width = width;
    this->height = height;
}

Texture::~Texture() {
    if (this->data) {
        free(this->data);
    }
}

Texture::Texture(const string& path) {
    int width, height, nrChannels;
    unsigned char *data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
    this->data = data;
    this->width = width;
    this->height = height;
}

}
