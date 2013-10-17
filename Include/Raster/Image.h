#ifndef INCLUDE_RASTER_IMAGE_H
#define INCLUDE_RASTER_IMAGE_H

#include <stdint.h>

#include <Log/Log.h>

namespace render {

typedef enum {
    RGB = 0,
    RGBA = 1,
    RGBF = 2,
    RGBAF = 3,
} ImageChannelType;

static size_t BitsPerChannel(ImageChannelType type) {
    switch(type) {
        case RGB:
        case RGBA:
            return 8;
        case RGBF:
        case RGBAF:
            return 32;
        default:
            LogError("Unknown image channel type!");
            return 0;
    }
}

static size_t BytesPerChannel(ImageChannelType type) {
    switch(type) {
        case RGB:
        case RGBA:
            return 1;
        case RGBF:
        case RGBAF:
            return 4;
        default:
            LogError("Unknown image channel type!");
            return 0;
    }
}

static size_t BytesPerPixel(ImageChannelType type) {
    switch(type) {
        case RGB:
            return 3;
        case RGBA:
            return 4;
        case RGBF:
            return 12;
        case RGBAF:
            return 16;
        default:
            LogError("Unknown image channel type!");
            return 0;
    }
}

class Image {
public:
    Image(ImageChannelType t, void *d, size_t w, size_t h) {
        type = t;
        const size_t dataSize = w * h * BytesPerPixel(t);
        dataBuf = malloc(dataSize);
        memcpy(dataBuf, d, dataSize);
        width = w;
        height = h;
    }
    
    ImageChannelType type;
    void *dataBuf;
    size_t width, height;
};
}

#endif