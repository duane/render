#ifndef INCLUDE_MATH_INTERPOLATION_H
#define INCLUDE_MATH_INTERPOLATION_H

#include <Math/Vector3.h>

namespace render {

static inline double lerp(double v1, double v2, double amt) {
    double lerped = v1 + (v2 - v1) * amt;
    return lerped;
}

static inline Vector3 v3lerp(Vector3 v1, Vector3 v2, double amt) {
    Vector3 lerped = Vector3(lerp(v1.x, v2.x, amt), lerp(v1.y, v2.y, amt), lerp(v1.z, v2.z, amt));
    return lerped;
}

} // render

#endif // INCLUDE_MATH_INTERPOLATION_H
