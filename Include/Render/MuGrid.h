#ifndef INCLUDE_RENDER_MUGRID_H
#define INCLUDE_RENDER_MUGRID_H

#include <vector>

#include <Math/Vector3.h>

namespace render {

class MuPoly {
public:
  Vector3 a, b, c, d;
  MuPoly(Vector3 topLeft, Vector3 topRight, Vector3 bottomRight, Vector3 bottomLeft) {
    a = topLeft;
    b = topRight;
    c = bottomRight;
    d = bottomLeft;
  }
};

class MuGrid {
  public: 
  std::vector<MuPoly> grid; 
  void addMuPoly(MuPoly mu) {
    grid.push_back(mu);
  }
};

}

#endif
