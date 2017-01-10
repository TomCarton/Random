// main.c

#include <stdlib.h>
#include <stdio.h>

#include "tools/image.h"
#include "render/renderCountryFlag.h"
#include "render/renderFractal.h"
#include "render/renderSquareTile.h"


static const unsigned int kWidth = 480;
static const unsigned int kHeight = 360;

static const unsigned int kFlagWidth = 480;
static const unsigned int kFlagHeight = 320;


int main(int argc, char *argv[])
{
    unsigned char *image = malloc(kWidth * kHeight * 4 * 3);
    unsigned char *reducedImage = NULL;

    // Country flags
    RenderFrenchFlag(image, kFlagWidth << 1, kFlagHeight << 1);
    reducedImage = Downsize(image, kFlagWidth << 1, kFlagHeight << 1);
    SaveImagePNG("result/flagFR.png", reducedImage, kFlagWidth, kFlagHeight);
    free(reducedImage);

    RenderJapaneseFlag(image, kFlagWidth << 1, kFlagHeight << 1);
    reducedImage = Downsize(image, kFlagWidth << 1, kFlagHeight << 1);
    SaveImagePNG("result/flagJP.png", reducedImage, kFlagWidth, kFlagHeight);
    free(reducedImage);

    RenderAmericanFlag(image, kFlagWidth << 1, kFlagHeight << 1);
    reducedImage = Downsize(image, kFlagWidth << 1, kFlagHeight << 1);
    SaveImagePNG("result/flagUS.png", reducedImage, kFlagWidth, kFlagHeight);
    free(reducedImage);

    RenderSwissFlag(image, kFlagWidth << 1, kFlagHeight << 1);
    reducedImage = Downsize(image, kFlagWidth << 1, kFlagHeight << 1);
    SaveImagePNG("result/flagCH.png", reducedImage, kFlagWidth, kFlagHeight);
    free(reducedImage);

    RenderGermanFlag(image, kFlagWidth << 1, kFlagHeight << 1);
    reducedImage = Downsize(image, kFlagWidth << 1, kFlagHeight << 1);
    SaveImagePNG("result/flagDE.png", reducedImage, kFlagWidth, kFlagHeight);
    free(reducedImage);

    RenderFinnishFlag(image, kFlagWidth << 1, kFlagHeight << 1);
    reducedImage = Downsize(image, kFlagWidth << 1, kFlagHeight << 1);
    SaveImagePNG("result/flagFI.png", reducedImage, kFlagWidth, kFlagHeight);
    free(reducedImage);

    RenderSwedishFlag(image, kFlagWidth << 1, kFlagHeight << 1);
    reducedImage = Downsize(image, kFlagWidth << 1, kFlagHeight << 1);
    SaveImagePNG("result/flagSE.png", reducedImage, kFlagWidth, kFlagHeight);
    free(reducedImage);


    // Fractals
    FractalParameters params;
    params.iterations = 500;

    // Mandelbrot set
    params.mode = FractalModeMandelbrot;
    params.xMin = -2.2; params.xMax = 1.03;
    params.yMin = -1.33; params.yMax = 1.33;

    RenderFractal(params, image, kWidth << 1, kHeight << 1);
    reducedImage = Downsize(image, kWidth << 1, kHeight << 1);
    SaveImagePNG("result/mandelbrot.png", reducedImage, kWidth, kHeight);
    free(reducedImage);

    // Julia set
    params.mode = FractalModeJulia;
    params.xMin = -1.54; params.xMax = 1.54;
    params.yMin = -1.17; params.yMax = 1.17;
    params.cr = -0.7; params.ci = 0.27;

    RenderFractal(params, image, kWidth << 1, kHeight << 1);
    reducedImage = Downsize(image, kWidth << 1, kHeight << 1);
    SaveImagePNG("result/julia.png", reducedImage, kWidth, kHeight);
    free(reducedImage);

    params.xMin = -1.44; params.xMax = 1.44;
    params.cr = -0.4; params.ci = 0.6;

    RenderFractal(params, image, kWidth << 1, kHeight << 1);
    reducedImage = Downsize(image, kWidth << 1, kHeight << 1);
    SaveImagePNG("result/julia2.png", reducedImage, kWidth, kHeight);
    free(reducedImage);


    // other
    RenderSquareTile(image, kWidth, kHeight);
    SaveImagePNG("result/squareTile.png", image, kWidth, kHeight);


    free(image);

    return 0;
}
