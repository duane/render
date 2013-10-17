#include <Render/Renderers/Reyes.h>
#include <limits.h>
#include <float.h>

using namespace render;

Image Reyes::render(std::vector<Primitive*> scene) {
  const size_t width = 500;
  const size_t height = 500;
  const size_t size = width * height * 3;
  const size_t samplesPerPixelX = 2;
  const size_t samplesPerPixely = 2;
  const size_t samples = width * samplesPerPixelX * height * samplesPerPixelY;
  
  double zbuf[samples];
  for (size_t i = 0; i < sizeof(zbuf); i++) {
      zbuf[i] = DBL_MAX;
  }
  
  std::vector<Primitive*> processingStack = std::vector<Primitive*>();
  
  
  
  Image img = Image(RGB, (void*)data, width, height);
  free(data);
  return img;
}