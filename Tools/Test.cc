#include <vector>

#include <Raster/PngDriver.h>
#include <Render/Primitive.h>
#include <Render/Primitives/Quad.h>
#include <Render/Renderers/Reyes.h>

using namespace render;

int main(int argc, char **argv) {
    Quad quad = Quad(Vector3(-0.5, 0.5, -1.0), Vector3(0.5, 0.5, -1.0), Vector3(0.5, -0.5, -1.0), Vector3(-0.5, -0.5, -1.0));
    std::vector<Primitive*> prims = std::vector<Primitive*>();
    prims.push_back(&quad);
    Reyes reyes = Reyes();
    Image image = reyes.render(prims);
    PNGDriver pngDriver = PNGDriver();
    pngDriver.WriteImage(image, "out.png");
    return 0;
}