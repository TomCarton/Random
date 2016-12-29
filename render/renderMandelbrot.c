// renderMandelbrot.c
//

#include <math.h>


static const int kIterations = 1000;

static const double kMinX = -2.3, kMaxX = 0.66;
static const double kMinY = -1.33, kMaxY = 1.33;


static int Mandelbrot(double x, double y)
{
	double zr = 0;
	double zi = 0;

	unsigned int i;
	for (i = 0; i < kIterations; ++i)
	{
		if (zr * zr + zi * zi > 4)
		{
			break;			
		}

		double temp = zr * zr - zi * zi + x;
		zi = 2 * zr * zi + y;
		zr = temp;
	}

	double j = (double)i / kIterations;

	return (int)(pow(j, 0.6) * 255 + 0.5) << 16 | (int)(pow(j, 0.3) * 255 + 0.5) <<  8 | (int)(pow(j, 0.1) * 255 + 0.5) <<  0;
}

void RenderMandelbrot(unsigned int width, unsigned int height, unsigned char *buffer)
{
	for (unsigned int k = 0; k < width * height; ++k)
    {
        unsigned int x = k % width;
        unsigned int y = k / width;

		int pix = Mandelbrot(kMinX + (x + 0.5) / width * (kMaxX - kMinX), kMaxY - (y + 0.5) / height * (kMaxY - kMinY));

        buffer[k * 3 + 0] = (pix >> 16);
        buffer[k * 3 + 1] = (pix >> 8);
        buffer[k * 3 + 2] = pix;
    }
}
