#include <Render/Primitives/Quad.h>

#include <Math/Utility.h>
#include <Math/Interpolation.h>


using namespace render;

BoundingBox Quad::bound() {
  double minX = min(a.x, min(b.x, min(c.x, d.x)));
  double maxX = max(a.x, max(b.x, max(c.x, d.x)));

  double minY = min(a.y, min(b.y, min(c.y, d.y)));
  double maxY = max(a.y, max(b.y, max(c.y, d.y)));

  double minZ = min(a.z, min(b.z, min(c.z, d.z)));
  double maxZ = max(a.z, max(b.z, max(c.z, d.z)));

  return BoundingBox(minX, maxX, minY, maxY, minZ, maxZ);
}


MuGrid Quad::dice(RenderContext ctx) {
  MuGrid grid = MuGrid();
  double uDelta = 1 / ctx.width;
  double vDelta = 1 / ctx.height;
  for (int v = 0; v < ctx.height; v++) {
    double vAmt = vDelta * v;
    Vector3 lineAPre = v3lerp(a, d, vAmt);
    Vector3 lineBPre = v3lerp(b, c, vAmt);
    Vector3 lineAPost = v3lerp(a, d, vAmt + vDelta);
    Vector3 lineBPost = v3lerp(b, c, vAmt + vDelta);
    for (int u = 0; u < ctx.width; u++) {
      double uAmt = uDelta * u;
      Vector3 muA = v3lerp(lineAPre, lineBPre, uAmt);
      Vector3 muB = v3lerp(lineAPre, lineBPre, uAmt + uDelta);
      Vector3 muC = v3lerp(lineAPost, lineBPost, uAmt + uDelta);
      Vector3 muD = v3lerp(lineAPost, lineBPost, uAmt);
      grid.addMuPoly(MuPoly(muA, muB, muC, muD));
    }
  }
  return grid;
}

std::vector<Primitive*> Quad::split(RenderContext ctx) {
  const size_t uChildren = 4;
  const size_t  vChildren = 4;
  std::vector<Primitive*> children = std::vector<Primitive*>();

  double uDelta = 1 / uChildren;
  double vDelta = 1 / vChildren;
  for (size_t v = 0; v < vChildren; v++) {
    double vAmt = vDelta * v;
    Vector3 lineAPre = v3lerp(a, d, vAmt);
    Vector3 lineBPre = v3lerp(b, c, vAmt);
    Vector3 lineAPost = v3lerp(a, d, vAmt + vDelta);
    Vector3 lineBPost = v3lerp(b, c, vAmt + vDelta);
    for (size_t u = 0; u < uChildren; u++) {
      double uAmt = uDelta * u;
      Vector3 cA = v3lerp(lineAPre, lineBPre, uAmt);
      Vector3 cB = v3lerp(lineAPre, lineBPre, uAmt + uDelta);
      Vector3 cC = v3lerp(lineAPost, lineBPost, uAmt + uDelta);
      Vector3 cD = v3lerp(lineAPost, lineBPost, uAmt);
      children.push_back(new Quad(cA, cB, cC, cD));
    }
  }
  return children;
}

void Quad::setDiceable(bool diceableq) {
  diceable = diceableq;
}

bool Quad::isDiceable() {
  return diceable;
}