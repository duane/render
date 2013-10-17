#ifndef INCLUDE_RENDER_RENDER_H
#define INCLUDE_RENDER_RENDER_H

#include <Raster/Image.h>
#include <Render/Primitive.h>

namespace render {

class Render {
  public:
    virtual Image render(std::vector<Primitive*> scene) = 0;
};

}

#endif
