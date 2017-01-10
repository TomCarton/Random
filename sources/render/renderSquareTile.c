// renderSquareTile.c
//
// written by Thomas CARTON
//

#include <math.h>

#include "renderSquareTile.h"


void RenderSquareTile(unsigned char *buffer, unsigned int width, unsigned int height)
{
    for (int x = 0; x < width; ++x)
    {
        for (int y = 0; y < height; ++y)
        {
        	unsigned int i = x * 255 / width;
        	unsigned int j = y * 255 / height;

            unsigned char c = j & (i - 2 * (j ^ i) + i) & j;

            *buffer++ = c;
            *buffer++ = c;
            *buffer++ = c;
        }
    }
}
