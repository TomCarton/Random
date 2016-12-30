// renderFractal.h

typedef enum
{
	FractalModeMandelbrot,
	FractalModeJulia,
} FractalMode;

typedef struct
{
	FractalMode mode;	
	
	double xMin, xMax;
	double yMin, yMax;

	int iterations;

} FractalCoordinates;

void RenderFractal(FractalCoordinates coords, unsigned char *buffer, unsigned int width, unsigned int height);
