// image.c
//

#include <stdio.h>

#include "image.h"


void SaveImage(char *filename, unsigned char *image, int width, int height)
{
	FILE *outputFile = fopen(filename, "w");

	// PPM header
	fprintf(outputFile, "P6 %d %d %d\n", width, height, 255);

	fwrite(image, 3, width * height, outputFile);

	fclose(outputFile);
}
