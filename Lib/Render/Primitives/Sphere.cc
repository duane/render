#include <Render/Primitives/Sphere.h>

#include <math.h>

using namespace render;

BoundingBox Sphere::bound() {
  Vector3 radVec = new Vector3(radius, radius, radius);
  return BoundingBox(pos.sub(radVec), pos.add(radVec));
}

BoundingBox Sphere::dice() {
  
}
