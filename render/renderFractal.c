// renderFractal.c
//

#include <math.h>

#include "renderFractal.h"


// Mandelbrot set

static int Mandelbrot(double x, double y, int maxIterations)
{
  double zr = 0;
  double zi = 0;

  unsigned int i;
  for (i = 0; i < maxIterations && zr * zr + zi * zi <= 4; ++i)
  {
    double temp = zr * zr - zi * zi + x;
    zi = 2 * zr * zi + y;
    zr = temp;
  }

  double j = (double)i / maxIterations;

  return (int)(pow(j, 0.6) * 255 + 0.5) << 16 | (int)(pow(j, 0.3) * 255 + 0.5) <<  8 | (int)(pow(j, 0.1) * 255 + 0.5);
}

// Julia set

static int Julia(double zr, double zi, int maxIterations)
{
  double cRe = -0.7;
  double cIm = 0.27015;

  unsigned int i;
  for (i = 0; i < maxIterations && zr * zr + zi * zi <= 4; ++i)
  {
    double r = zr;
    double i = zi;

    zr = r * r - i * i + cRe;
    zi = 2 * r * i + cIm;
  }

  double j = (double)i / maxIterations;

  return (int)(pow(j, 0.6) * 255 + 0.5) << 16 | (int)(pow(j, 0.3) * 255 + 0.5) <<  8 | (int)(pow(j, 0.1) * 255 + 0.5);
}

void RenderFractal(FractalCoordinates coords, unsigned char *buffer, unsigned int width, unsigned int height)
{
  for (unsigned int k = 0; k < width * height; ++k)
  {
    unsigned int x = k % width;
    unsigned int y = k / width;

    int pixel = 0;
    switch (coords.mode)
    {
      case FractalModeMandelbrot:
        pixel = Mandelbrot(coords.xMin + (x + 0.5) / width * (coords.xMax - coords.xMin), coords.yMax - (y + 0.5) / height * (coords.yMax - coords.yMin), coords.iterations);
        break;

      case FractalModeJulia:
        pixel = Julia(coords.xMin + (x + 0.5) / width * (coords.xMax - coords.xMin), coords.yMax - (y + 0.5) / height * (coords.yMax - coords.yMin), coords.iterations);
        break;
    }

    buffer[k * 3 + 0] = (pixel >> 16);
    buffer[k * 3 + 1] = (pixel >> 8);
    buffer[k * 3 + 2] = pixel;
  }
}
