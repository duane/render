#ifndef INCLUDE_RASTER_IMAGEDRIVER_H
#define INCLUDE_RASTER_IMAGEDRIVER_H

#include <Raster/Image.h>

namespace render {

class ImageDriver {
public:
    ImageDriver() {}
    ~ImageDriver() {}
    virtual Image ReadImage(char *path) = 0;
    virtual void WriteImage(Image image, const char *path) = 0;
};

}
#endif