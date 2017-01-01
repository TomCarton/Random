// renderFractal.h

typedef enum
{
	FractalModeMandelbrot,
	FractalModeJulia,
} FractalMode;

typedef struct
{
	FractalMode mode;
	double cr, ci;
	
	double xMin, xMax;
	double yMin, yMax;

	int iterations;

} FractalParameters;

void RenderFractal(FractalParameters params, unsigned char *buffer, unsigned int width, unsigned int height);
