// renderFractal.c
//

#include <math.h>

#include "renderFractal.h"


static double Fractal(double zr, double zi, double x, double y, int maxIterations)
{
  unsigned int k = 0;
  while (k < maxIterations && zr * zr + zi * zi <= 2 * 2)
  {
    double r = zr;
    double i = zi;

    zr = r * r - i * i + x;
    zi = 2 * r * i + y;

    ++k;
  }

  double j = (double)k / maxIterations;

  return j; 
}

void RenderFractal(FractalParameters params, unsigned char *buffer, unsigned int width, unsigned int height)
{
  for (unsigned int k = 0; k < width * height; ++k)
  {
    unsigned int x = k % width;
    unsigned int y = k / width;

    double fx = params.xMin + (x + 0.5) / width * (params.xMax - params.xMin);
    double fy = params.yMax - (y + 0.5) / height * (params.yMax - params.yMin);

    double j = 0;
    switch (params.mode)
    {
      case FractalModeMandelbrot:
        j = Fractal(0, 0, fx, fy, params.iterations);
        break;

      case FractalModeJulia:
        j = Fractal(fx, fy, -0.7, 0.270125, params.iterations);
        break;
    }

    buffer[k * 3 + 0] = (unsigned char)(pow(j, 0.6) * 255 + 0.5);
    buffer[k * 3 + 1] = (unsigned char)(pow(j, 0.3) * 255 + 0.5);
    buffer[k * 3 + 2] = (unsigned char)(pow(j, 0.1) * 255 + 0.5);
  }
}
