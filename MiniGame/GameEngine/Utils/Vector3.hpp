//
//  Vector3.hpp
//  MiniGame
//
//  Created by iprincewang on 2020/12/16.
//

#ifndef Vector3_hpp
#define Vector3_hpp

namespace GameEngine {

class Vector3 {
 
public:
    float x;
    float y;
    float z;
    
    Vector3();
    Vector3(float,float,float);
    ~Vector3();
};
}

#endif /* Vector3_hpp */
