#ifndef __INCLUDE_RENDER_RENDERERS_REYES_H__
#define __INCLUDE_RENDER_RENDERERS_REYES_H__

#include <Render/Render.h>

namespace render {

class Reyes : public Render {
public:
    Image render(std::vector<Primitive*> scene);
};

}

#endif