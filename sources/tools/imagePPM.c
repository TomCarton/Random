// imagePPM.c
//
// written by Thomas CARTON
//

#include <stdio.h>

#include "image.h"


void SaveImagePPM(char *filename, unsigned char *image, int width, int height)
{
	FILE *outputFile = fopen(filename, "w");

	// PPM header
	fprintf(outputFile, "P6 %d %d %d\n", width, height, 255);

	fwrite(image, 3, width * height, outputFile);

	fclose(outputFile);
}
