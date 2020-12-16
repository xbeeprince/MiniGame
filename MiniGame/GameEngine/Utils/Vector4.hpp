//
//  Vector4.hpp
//  MiniGame
//
//  Created by iprincewang on 2020/12/16.
//

#ifndef Vector4_hpp
#define Vector4_hpp

namespace GameEngine {

class Vector4 {
     
public:
    float x;
    float y;
    float z;
    float w;
    
    Vector4();
    Vector4(float,float,float,float);
    ~Vector4();
};
}

#endif /* Vector4_hpp */
