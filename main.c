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

        FractalParameters params;

	params.iterations = 300;

	params.mode = FractalModeMandelbrot;
	params.xMin = -2.1; params.xMax = 0.93;
	params.yMin = -1.33; params.yMax = 1.33;
 
        RenderFractal(params, image, kWidth, kHeight);
        SaveImageTGA("result/mandelbrot.tga", image, kWidth, kHeight);

	params.mode = FractalModeJulia;
	params.xMin = -1.44; params.xMax = 1.44;
	params.yMin = -1.17; params.yMax = 1.17;
 
        RenderFractal(params, image, kWidth, kHeight);
        SaveImageTGA("result/julia.tga", image, kWidth, kHeight);

        return 0;
}
