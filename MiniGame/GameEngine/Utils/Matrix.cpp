//
//  Matrix.cpp
//  MiniGame
//
//  Created by iprincewang on 2020/12/16.
//

#include "Matrix.hpp"

namespace GameEngine {

static const float MATRIX_IDENTITY[16] = {
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
};

Matrix::Matrix() {
    *this = Matrix::identity();
}

Matrix::Matrix(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24,
               float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44) {
    set(m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44);
}

void Matrix::set(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24,
                 float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44) {
    m[0]  = m11;
    m[1]  = m21;
    m[2]  = m31;
    m[3]  = m41;
    m[4]  = m12;
    m[5]  = m22;
    m[6]  = m32;
    m[7]  = m42;
    m[8]  = m13;
    m[9]  = m23;
    m[10] = m33;
    m[11] = m43;
    m[12] = m14;
    m[13] = m24;
    m[14] = m34;
    m[15] = m44;
}

Matrix::~Matrix() {
    
}

const Matrix& Matrix::identity() {
    static Matrix m(
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1 );
    return m;
}

const Matrix& Matrix::zero() {
    static Matrix m(
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0 );
    return m;
}

}
