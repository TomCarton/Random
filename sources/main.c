// main.c

#include <stdlib.h>
#include <stdio.h>

#include "tools/image.h"
#include "render/renderCountryFlag.h"
#include "render/renderFractal.h"


static const unsigned int kWidth = 800;
static const unsigned int kHeight = 600;

static const unsigned int kFlagWidth = 48;
static const unsigned int kFlagHeight = 32;


int main(int argc, char *argv[])
{
    unsigned char *image = malloc(kWidth * kHeight * 3);

    // Country flags
    RenderFrenchFlag(image, kFlagWidth, kFlagHeight);
    SaveImageTGA("result/flagFR.tga", image, kFlagWidth, kFlagHeight);
    SaveImagePNG("result/flagFR.png", image, kFlagWidth, kFlagHeight);

    RenderJapaneseFlag(image, kFlagWidth, kFlagHeight);
    SaveImageTGA("result/flagJP.tga", image, kFlagWidth, kFlagHeight);
    SaveImagePNG("result/flagJP.png", image, kFlagWidth, kFlagHeight);

    RenderAmericanFlag(image, kFlagWidth, kFlagHeight);
    SaveImageTGA("result/flagUS.tga", image, kFlagWidth, kFlagHeight);
    SaveImagePNG("result/flagUS.png", image, kFlagWidth, kFlagHeight);


    // Fractals
    FractalParameters params;
    params.iterations = 500;

    // Mandelbrot set
    params.mode = FractalModeMandelbrot;
    params.xMin = -2.1; params.xMax = 0.93;
    params.yMin = -1.33; params.yMax = 1.33;

    RenderFractal(params, image, kWidth, kHeight);
    SaveImageTGA("result/mandelbrot.tga", image, kWidth, kHeight);
    SaveImagePNG("result/mandelbrot.png", image, kWidth, kHeight);

    // Julia set
    params.mode = FractalModeJulia;
    params.xMin = -1.54; params.xMax = 1.54;
    params.yMin = -1.17; params.yMax = 1.17;
    params.cr = -0.7; params.ci = 0.27;

    RenderFractal(params, image, kWidth, kHeight);
    SaveImageTGA("result/julia.tga", image, kWidth, kHeight);
    SaveImagePNG("result/julia.png", image, kWidth, kHeight);

    // Julia set 2
    params.mode = FractalModeJulia;
    params.xMin = -1.44; params.xMax = 1.44;
    params.yMin = -1.17; params.yMax = 1.17;
    params.cr = -0.4; params.ci = 0.6;

    RenderFractal(params, image, kWidth, kHeight);
    SaveImageTGA("result/julia2.tga", image, kWidth, kHeight);
    SaveImagePNG("result/julia2.png", image, kWidth, kHeight);

    free(image);

    return 0;
}
