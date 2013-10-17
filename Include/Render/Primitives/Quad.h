#ifndef INCLUDE_RENDER_PRIMITIVES_QUAD_H
#define INCLUDE_RENDER_PRIMITIVES_QUAD_H

#include <Render/Primitive.h>

namespace render {

class Quad : public Primitive {
public:
    Quad(Vector3 topLeft, Vector3 topRight, Vector3 bottomRight, Vector3 bottomLeft) {
        a = topLeft;
        b = topRight;
        c = bottomRight;
        d = bottomLeft;
        diceable = true;
    }

    BoundingBox bound();
    MuGrid dice(RenderContext ctx);
    std::vector<Primitive*> split(RenderContext ctx);
    
    void setDiceable(bool diceable);
    bool isDiceable();

    bool diceable;    
    Vector3 a, b, c, d;
};

}

#endif
