//
//  Color.hpp
//  MiniGame
//
//  Created by iprincewang on 2020/12/16.
//

#ifndef Color_hpp
#define Color_hpp

namespace GameEngine {

class color {
  
private:
    float _r;
    float _g;
    float _b;
    float _a;
    
public:
    color();
    color(float,float,float,float);
    ~color();
};
}

#endif /* Color_hpp */
