//
//  Drawable.hpp
//  MiniGame
//
//  Created by iprincewang on 2020/12/16.
//

#ifndef Drawable_hpp
#define Drawable_hpp

#include "Color.hpp"
#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Vector4.hpp"
#include "Matrix.hpp"

namespace GameEngine {

class Drawable {
  
private:
    float         _positionX;
    float         _positionY;
    float         _positionZ;
    
    float         _scaleX;
    float         _scaleY;
    float         _scaleZ;
    
    float         _rotationX;
    float         _rotationY;
    float         _rotationZ;
    
    color _color;
    
    Matrix       modelMatrix;
    Matrix       viewMatrix;
    Matrix       projectionMatrix;
    
public:
    Drawable();
    ~Drawable();
    
    //更新坐标、颜色、纹理等
    void update();
    
    //渲染
    void render();
};
}

#endif /* Drawable_hpp */
