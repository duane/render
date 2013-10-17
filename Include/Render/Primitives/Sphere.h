#ifndef INCLUDE_RENDER_PRIMITIVES_SPHERE_H
#define INCLUDE_RENDER_PRIMITIVES_SPHERE_H

#include <Render/Primitives.h>

namespace render {

class Primitive {
 public:
  Sphere(double radius, double thetaMin, double thetaMax, double phiMin, double phiMax, Vector3 pos) {
    rad = radius;
    thMin = thetaMin;
    thMax = thetaMax;
    phMin = phiMin;
    phMax = phiMax;
    tr = pos;
  }
  
  
  BoundingBox bound();
  MuGrid dice(RenderContext ctx);
  std::vector<Primitive> split(RenderContext ctx);

 private:
  double rad, thMin, thMax, phMin, phMax, tr;
};

}

#endif
