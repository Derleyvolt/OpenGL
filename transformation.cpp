#include <iostream>
#include "C:/Users/Derley/Downloads/eigen-3.4.0/eigen-3.4.0/Eigen/Dense"

using namespace std;
using namespace Eigen;

// rotaciona em função do eixo Z
Matrix4f rotationZ(float angle) {
    Matrix4f a = Matrix4f::Identity(4, 4);
    a(0, 0) = cos(angle);
    a(0, 1) = -sin(angle);
    a(1, 0) = sin(angle);
    a(1, 1) = cos(angle);
    return a;
}

// rotaciona em função do eixo Y
Matrix4f rotationY(float angle) {
    Matrix4f a = Matrix4f::Identity(4, 4);
    a(0, 0) = cos(angle);
    a(0, 2) = sin(angle);
    a(2, 0) = -sin(angle);
    a(2, 2) = cos(angle);
    return a;
}

// rotaciona em função do eixo X
Matrix4f rotationX(float angle) {
    Matrix4f a = Matrix4f::Identity(4, 4);
    a(1, 1) = cos(angle);
    a(1, 2) = -sin(angle);
    a(2, 2) = cos(angle);
    a(2, 1) = sin(angle);
    return a;
}

// translarda
Matrix4f translation(float tx, float ty, float tz) {
    Matrix4f a = Matrix4f::Identity(4, 4);
    a(0, 3) = tx;
    a(1, 3) = ty;
    a(2, 3) = tz;
    return a;
}

// Gera uma matriz pra escalar
Matrix4f scalling(float fx, float fy, float fz) {
    Matrix4f a = Matrix4f::Identity(4, 4);
    a(0, 0) = fx;
    a(1, 1) = fy;
    a(2, 2) = fz;
    return a;
}