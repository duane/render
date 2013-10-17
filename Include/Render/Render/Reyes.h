#ifndef __INCLUDE_RENDER_RENDERERS_Reyes_H__
#define __INCLUDE_RENDER_RENDERERS_Reyes_H__

#include <Render/Render.h>


namespace render {
class Reyes : public Renderer {
public:
  Image render(std::vector<Primitive*> scene);
};
}

#endif