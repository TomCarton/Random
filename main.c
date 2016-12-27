// main.c

#include <stdio.h>

#include "tools/image.h"
#include "render/renderFlag.h"


static const unsigned int kWidth = 800;
static const unsigned int kHeight = 600;


int main(int argc, char *argv[])
{
        unsigned char image[kWidth * kHeight * 3];
        RenderFrenchFlag(kWidth, kHeight, image);

        SaveImage("flag.ppm", image, kWidth, kHeight);

        return 0;
}
