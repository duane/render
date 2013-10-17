#ifndef INCLUDE_RASTER_PNGDRIVER_H
#define INCLUDE_RASTER_PNGDRIVER_H

#include <Raster/ImageDriver.h>

namespace render {

class PNGDriver : public ImageDriver {
public:
    PNGDriver() {}
    ~PNGDriver() {}
    
    Image ReadImage(char *path);
    void WriteImage(Image image, const char *path);
};

}
#endif