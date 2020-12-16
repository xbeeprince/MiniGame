//
//  Matrix.hpp
//  MiniGame
//
//  Created by iprincewang on 2020/12/16.
//

#ifndef Matrix_hpp
#define Matrix_hpp

namespace GameEngine {

class Matrix {
  
private:
    float m[16];
    
public:
    Matrix();
    Matrix(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24,
               float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44);
    Matrix(const float* m);
    
    ~Matrix();
    
    static const Matrix& identity();
    static const Matrix& zero();
    
    void set(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24,
                 float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44);
};
}

#endif /* Matrix_hpp */
