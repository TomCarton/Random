// main.c

#include <stdlib.h>
#include <stdio.h>

#include "tools/image.h"
#include "render/renderCountryFlag.h"
#include "render/renderFractal.h"
#include "render/renderSquareTile.h"


static const unsigned int kWidth = 480;
static const unsigned int kHeight = 360;

static const unsigned int kFlagWidth = 48;
static const unsigned int kFlagHeight = 32;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmultichar"

static const unsigned char kCountryFlagNames[][3] = { "FR", "JP", "US", "CH", "DE", "FI", "SE" };

#pragma clang diagnostic pop


int main(int argc, char *argv[])
{
    unsigned char *image = malloc(kWidth * kHeight * 4 * 3);
    unsigned char *reducedImage = NULL;


    // Country flags
	char imageFilename[] = "result/flagXX.png"; 
    for (unsigned int k = 0; k < kCountryFlagCount; ++k)
    {
    	RenderFlag(k, image, kFlagWidth << 1, kFlagHeight << 1);
	    reducedImage = Downsize(image, kFlagWidth << 1, kFlagHeight << 1);

	    sprintf(imageFilename, "result/flag%s.png", kCountryFlagNames[k]);
	    SaveImagePNG(imageFilename, reducedImage, kFlagWidth, kFlagHeight);
    	free(reducedImage);
    }


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


    // Square tile
    RenderSquareTile(image, 512, 512);
    SaveImagePNG("result/squareTile.png", image, 512, 512);


    free(image);

    return 0;
}
