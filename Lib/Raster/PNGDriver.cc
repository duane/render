#define PNG_DEBUG 3

#include <Raster/PNGDriver.h>
#include <Log/Log.h>
#include <png.h>

using namespace render;

Image PNGDriver::ReadImage(char *path) {
    return  Image(RGB,NULL,0,0);
}

void PNGDriver::WriteImage(Image image, const char *path) {
    if (image.type != RGB && image.type != RGBA) {
        LogError("Unable to write 4-byte-per-channel images.");
        return;
    }
    
    FILE *fp = fopen(path, "wb");
    if (!fp) {
        LogError("Unable to open output file for writing.");
        return;
    }
    
    png_structp png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png_ptr) {
        fclose(fp);
        LogError("Error creating png write struct.");
        return;
    }
    
    png_infop info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr) {
        png_destroy_write_struct(&png_ptr, (png_infopp)NULL);
        fclose(fp);
        LogError("Unable to create info struct.");
        return;
    }
    
    if (setjmp(png_jmpbuf(png_ptr))) {
        png_destroy_write_struct(&png_ptr, &info_ptr);
        fclose(fp);
        LogError("Unknown PNG error.");
        return;
    }
    

    if(image.type == RGB)
        png_set_IHDR(png_ptr, info_ptr, image.width, image.height, BitsPerChannel(image.type), PNG_COLOR_TYPE_RGB, PNG_INTERLACE_ADAM7, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);
    else
        png_set_IHDR(png_ptr, info_ptr, image.width, image.height, BitsPerChannel(image.type), PNG_COLOR_TYPE_RGB_ALPHA, PNG_INTERLACE_ADAM7, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);
    
    // now construct an array of row pointers.
    png_byte **rows = (png_byte**)png_malloc(png_ptr, image.height * sizeof(png_byte*));
    const size_t rowSize = image.width * BytesPerPixel(image.type);
    for (size_t y = 0; y < image.height; y++) {
        rows[y] = (png_byte*)png_malloc(png_ptr, rowSize); 
        rows[y] = (png_byte*)memcpy(rows[y], (png_byte*)image.dataBuf + (y * rowSize), rowSize);
    }
    
    png_init_io(png_ptr, fp);
    png_set_rows(png_ptr, info_ptr, rows);
    png_write_png(png_ptr, info_ptr, PNG_TRANSFORM_IDENTITY, NULL);
    png_write_end(png_ptr, info_ptr);
    
    for (size_t y = 0; y < image.height; y++)
        png_free(png_ptr, rows[y]);
    png_free(png_ptr, rows);
    
    png_destroy_write_struct(&png_ptr, &info_ptr);
    fclose(fp);
}