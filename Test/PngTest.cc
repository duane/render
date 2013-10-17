#include <Raster/Image.h>
#include <Raster/PNGDriver.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv) {
    const size_t width = 100;
    const size_t height = 100;
    const size_t size = width * height * 3;
    uint8_t *data = (uint8_t*)malloc(size);
    for (size_t i = 0; i < size; i++) {
        data[i] = (uint8_t*)rand();
    }
    
    render::Image image = render::Image(render::RGB, data, width, height);
    render::PNGDriver driver = render::PNGDriver();
    driver.WriteImage(image, "output.png");
    return 0;
}