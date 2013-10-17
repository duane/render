#ifndef INCLUDE_RENDER_RENDERCONTEXT_H
#define INCLUDE_RENDER_RENDERCONTEXT_H

namespace render {


class RenderContext {
public:
  int width, height; // Sample width and height expected.
  int startX, startY; // 
  
  RenderContext(int newWidth, int newHeight, int newStartX, int newStartY) {
    width = newWidth;
    height = newHeight;
    startX = newStartX;
    startY = newStartY;
  } 
};

}

#endif
