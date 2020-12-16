//
//  Quad.hpp
//  MiniGame
//
//  Created by iprincewang on 2020/12/16.
//

#ifndef Quad_hpp
#define Quad_hpp

namespace GameEngine {

class Quad {
  
private:
public:
    float x;
    float y;
    float width;
    float height;
    
    Quad();
    Quad(float,float,float,float);
    ~Quad();
    
};
}

#endif /* Quad_hpp */
