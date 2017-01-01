// renderFlag.c

#include <stdio.h>

#include "renderFlag.h"


void RenderFrenchFlag(unsigned char *buffer, unsigned int width, unsigned int height)
{
	unsigned int left = width / 3;
	unsigned int right = left << 1;

	for (unsigned int k = 0; k < width * height; ++k)
	{
		unsigned int y = k / width;
		unsigned int x = k % width;

		*buffer++ = x > left ? 255 : 0;
		*buffer++ = x > left &&  x < right ? 255 : 0;
		*buffer++ = x < right ? 255 : 0;
	}
}

void RenderJapaneseFlag(unsigned char *buffer, unsigned int width, unsigned int height)
{
	unsigned int r2 = height * height * 0.09;

	for (unsigned int k = 0; k < width * height; ++k)
	{
		unsigned int y = k / width;
		unsigned int x = k % width;

		unsigned int px = x - (width >> 1);
		unsigned int py = y - (height >> 1);
		unsigned int d2 = px * px + py * py;

		*buffer++ = d2 < r2 ? 188 : 255;
		*buffer++ = d2 < r2 ? 0 : 255;
		*buffer++ = d2 < r2 ? 45 : 255;
	}
}
