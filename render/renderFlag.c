// renderFlag.c

#include <stdio.h>

#include "renderFlag.h"


void RenderFrenchFlag(unsigned char *buffer, unsigned int width, unsigned int height)
{
        unsigned int third = width / 3;
        unsigned int third2 = third << 1;

        for (unsigned int k = 0; k < width * height; ++k)
        {
                unsigned int x = k % width;
                unsigned int y = k / width;

                buffer[k * 3 + 0] = x > third ? 255 : 0;
                buffer[k * 3 + 1] = x > third &&  x < third2 ? 255 : 0;
                buffer[k * 3 + 2] = x < third2 ? 255 : 0;
        }
}
