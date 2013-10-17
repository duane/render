#ifndef INCLUDE_RENDER_BOUNDINGBOX_H
#define INCLUDE_RENDER_BOUNDINGBOX_H

#include <assert.h>

#include <Math/Vector3.h>


namespace render {

class BoundingBox {
  public:
  Vector3 min, max;
  
  BoundingBox(double xMin, double xMax, double yMin, double yMax, double zMin, double zMax) {
    assert(xMin < xMax);
    assert(yMin < yMax);
    assert(zMin < zMax);
    min = Vector3(xMin, yMin, zMin);
    max = Vector3(xMax, yMax, zMax);
  }
  
  BoundingBox(Vector3 a, Vector3 b) {
    assert(a.x < b.x);
    assert(a.y < b.y);
    assert(a.z < b.z);
    min = a;
    max = b;
  }
};

}

#endif
