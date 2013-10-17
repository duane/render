#ifndef INCLUDE_RENDER_PRIMITIVE_H
#define INCLUDE_RENDER_PRIMITIVE_H

#include <vector>

#include <Math/Vector3.h>
#include <Math/Matrix4.h>

#include <Render/BoundingBox.h>
#include <Render/MuGrid.h>
#include <Render/RenderContext.h>


namespace render {

class Primitive {
 public:
  virtual BoundingBox bound() = 0;
  virtual MuGrid dice(RenderContext ctx) = 0;
  virtual std::vector<Primitive*> split(RenderContext ctx) = 0;
  
  virtual void setDiceable(bool diceable) = 0;
  virtual bool isDiceable() = 0;
};

}

#endif
