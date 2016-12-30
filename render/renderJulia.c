// renderJulia.c
//

#include <math.h>


static const int kMaxIterations = 500;

static const double kMinX = -1.44, kMaxX = 1.44;
static const double kMinY = -1.17, kMaxY = 1.17;


static int Julia(double zr, double zi)
{
  double cRe = -0.7;
  double cIm = 0.27015;

  unsigned int i;
  for (i = 0; i < kMaxIterations && zr * zr + zi * zi <= 4; ++i)
  {
    double r = zr;
    double i = zi;

    zr = r * r - i * i + cRe;
    zi = 2 * r * i + cIm;
  }

  double j = (double)i / kMaxIterations;

  return (int)(pow(j, 0.6) * 255 + 0.5) << 16 | (int)(pow(j, 0.3) * 255 + 0.5) <<  8 | (int)(pow(j, 0.1) * 255 + 0.5);
}

void RenderJulia(unsigned char *buffer, unsigned int width, unsigned int height)
{
  for (unsigned int k = 0; k < width * height; ++k)
  {
      unsigned int x = k % width;
      unsigned int y = k / width;
      
      int pix = Julia(kMinX + (x + 0.5) / width * (kMaxX - kMinX), kMaxY - (y + 0.5) / height * (kMaxY - kMinY));

      buffer[k * 3 + 0] = (pix >> 16);
      buffer[k * 3 + 1] = (pix >> 8);
      buffer[k * 3 + 2] = pix;
  }
}
