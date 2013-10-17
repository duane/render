#ifndef INCLUDE_MATH_MATRIX4_H
#define INCLUDE_MATH_MATRIX4_H

#include <Math/Vector3.h>

namespace render {

static inline PerspectiveMatrix(double fov, double aspect, double hither, double yon) {
    double theta = fov;
    double thetaPrime = tan(theta / 2);
    return Matrix4(1 / (aspect * thetaPrime), 0, 0, 0,
                   0, 1 / thetaPrime, 0, 0,
                   0, 0, yon / (yon - hither), 0,
                   0, 0, (-hither * yon) / (yon - hither), 0);
}

class Matrix4 {
public:
  double m[16];

  Matrix4() {
    for (int i = 0; i < 16; i++) {
      m[i] = 0.0;
    }  
  }

  Matrix4(double m00, double m01, double m02, double m03,
          double m10, double m11, double m12, double m13,
          double m20, double m21, double m22, double m23,
          double m30, double m31, double m32, double m33) {
    m[0] = m00; m[1] = m01; m[2] = m02; m[3] = m03;
    m[4] = m10; m[5] = m11; m[6] = m12; m[7] = m13;
    m[8] = m20; m[9] = m21; m[10] = m22; m[11] = m23;
    m[12] = m30; m[13] = m31; m[14] = m32; m[15] = m33;
  }

  inline Matrix4 add(Matrix4 other) {
    Matrix4 result;
    for (int i = 0; i < 16; i++) {
      result.m[i] = m[i] + other.m[i];
    }
    return result;
  }

  inline Matrix4 mul(double scalar) {
    Matrix4 result;
    for (int i = 0; i < 16; i++) {
      result.m[i] = m[i] * scalar;
    }
    return result;
  }

  inline Matrix4 mmul(Matrix4 mul) {
    Matrix4 result;
    for (int i = 0; i < 16; i++) {
      int row = i - (i % 4);
      int column = (i % 4);
      result.m[i] = m[row] * mul.m[column]
                    + m[row + 1] * mul.m[column + 4]
                    + m[row + 2] * mul.m[column + 8]
                    + m[row + 3] * mul.m[column + 12];
    }
    return result;
  }

  
  inline Vector3 transform3(Vector3 v) {
    return Vector3(v.x * (m[0] + m[1] + m[2] + m[3]),
                   v.y * (m[4] + m[5] + m[6] + m[7]),
                   v.z * (m[8] + m[9] + m[10] + m[11]));
  }
};

}

#endif
