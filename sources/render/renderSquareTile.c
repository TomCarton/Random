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
            unsigned char c = x & (y - 2*(x^y) + y) & x;

            *buffer++ = c;
            *buffer++ = c;
            *buffer++ = c;
        }
    }
}
