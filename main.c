// main.c

#include <stdio.h>

#include "tools/image.h"
#include "render/renderFlag.h"
#include "render/renderFractal.h"


static const unsigned int kWidth = 800;
static const unsigned int kHeight = 600;


int main(int argc, char *argv[])
{
        unsigned char image[kWidth * kHeight * 3];

        RenderFrenchFlag(image, kWidth, kHeight);
        SaveImageTGA("result/flag.tga", image, kWidth, kHeight);

        FractalCoordinates coords;

		coords.iterations = 300;

		coords.mode = FractalModeMandelbrot;
		coords.xMin = -2.1; coords.xMax = 0.93;
		coords.yMin = -1.33; coords.yMax = 1.33;
 
        RenderFractal(coords, image, kWidth, kHeight);
        SaveImageTGA("result/mandelbrot.tga", image, kWidth, kHeight);

		coords.mode = FractalModeJulia;
		coords.xMin = -1.44; coords.xMax = 1.44;
		coords.yMin = -1.17; coords.yMax = 1.17;
 
        RenderFractal(coords, image, kWidth, kHeight);
        SaveImageTGA("result/julia.tga", image, kWidth, kHeight);

        return 0;
}
