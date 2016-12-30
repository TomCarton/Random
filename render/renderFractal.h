// renderFractal.h

typedef struct
{
	double xMin, xMax;
	double yMin, yMax;

	int iterations;

} FractalCoordinates;


void RenderMandelbrot(FractalCoordinates coords, unsigned char *buffer, unsigned int width, unsigned int height);
void RenderJulia(FractalCoordinates coords, unsigned char *buffer, unsigned int width, unsigned int height);
