#ifndef INCLUDE_MATH_VECTOR3_H
#define INCLUDE_MATH_VECTOR3_H

#include <math.h>

namespace render {

class Vector3 {
  public: 
  double x, y, z;
  Vector3() {
    x = 0.0;
    y = 0.0;
    z = 0.0;
  }

  Vector3(double newX, double newY, double newZ) {
    x = newX;
    y = newY;
    z = newZ;
  }

  inline Vector3 add(Vector3 other) {
    return Vector3(x + other.x, y + other.y, z + other.z);
  }

  inline Vector3 mul(double scalar) {
    return Vector3(x * scalar, y * scalar, z * scalar);
  }
  
  inline Vector3 sub(Vector3 other) {
    return add(other.mul(-1));
  }

  inline Vector3 dot(Vector3 other) {
    return Vector3(x * other.x, y * other.y, z * other.z);
  }

  inline double length() {
    return sqrt(x * x + y * y + z * z);
  }
  
  inline Vector3 unit() {
    return mul(1/length());
  }
  
  inline Vector3 cross(Vector3 other) {
    return Vector3(y * other.z - z * other.y,
                   z * other.x - x * other.z,
                   x * other.y - y * other.x);
  }
};

}

#endif
