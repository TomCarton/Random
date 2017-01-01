// renderFlag.c

#include <stdio.h>

#include "renderFlag.h"


void RenderFlag(unsigned int type, unsigned char *buffer, unsigned int width, unsigned int height)
{
	switch (type)
	{
		case 'FR':
			RenderFrenchFlag(buffer, width, height);
			break;

		case 'JP':
			RenderJapaneseFlag(buffer, width, height);
			break;

		case 'US':
			RenderAmericanFlag(buffer, width, height);
			break;
	}
}


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
		unsigned int y = (k / width) - (height >> 1);
		unsigned int x = (k % width) - (width >> 1);
		unsigned int d2 = x * x + y * y;

		*buffer++ = d2 < r2 ? 188 : 255;
		*buffer++ = d2 < r2 ? 0 : 255;
		*buffer++ = d2 < r2 ? 45 : 255;
	}
}

void RenderAmericanFlag(unsigned char *buffer, unsigned int width, unsigned int height)
{
	unsigned int r2 = height * height * 0.09;

	for (unsigned int k = 0; k < width * height; ++k)
	{
		unsigned int y = k / width;
		unsigned int x = k % width;

		if (x < width >> 1 && y < 7 * height / 13)
		{
			*buffer++ = 60;
			*buffer++ = 60;
			*buffer++ = 110;
		}
		else if ((y * 13 / height) & 1)
		{
			*buffer++ = 255;
			*buffer++ = 255;
			*buffer++ = 255;
		}
		else
		{
			*buffer++ = 178;
			*buffer++ = 34;
			*buffer++ = 52;
		}
	}
}
