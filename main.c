// main.c

#include <stdio.h>

#include "tools/image.h"
#include "render/renderFlag.h"
#include "render/renderMandelbrot.h"


static const unsigned int kWidth = 800;
static const unsigned int kHeight = 600;


int main(int argc, char *argv[])
{
        unsigned char image[kWidth * kHeight * 3];

        RenderFrenchFlag(kWidth, kHeight, image);
        SaveImageTGA("result/flag.tga", image, kWidth, kHeight);

        RenderMandelbrot(kWidth, kHeight, image);
        SaveImageTGA("result/mandelbrot.tga", image, kWidth, kHeight);

        return 0;
}
