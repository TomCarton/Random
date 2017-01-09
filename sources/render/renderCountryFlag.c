// renderCountryFlag.c
//
// written by Thomas CARTON
//

#include <stdio.h>

#include "renderCountryFlag.h"


void RenderFlag(CountryFlagType type, unsigned char *buffer, unsigned int width, unsigned int height)
{
	switch (type)
	{
		case kCountryFlagFrench:
			RenderFrenchFlag(buffer, width, height);
			break;

		case kCountryFlagJapanese:
			RenderJapaneseFlag(buffer, width, height);
			break;

		case kCountryFlagAmerican:
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
	unsigned int rw = width >> 1;
	unsigned int rh = 7 * height / 13;

	for (unsigned int k = 0; k < width * height; ++k)
	{
		unsigned int y = k / width;
		unsigned int x = k % width;

        // blue square
		if (x <= rw && y <= rh)
		{
            if ((x % (rw / 6) == 3) && (y % (rh / 5) == 2))
            {
                *buffer++ = 255;
                *buffer++ = 255;
                *buffer++ = 255;
            }
            else
            {
                *buffer++ = 60;
                *buffer++ = 60;
                *buffer++ = 110;
            }
		}
        // white stripe
		else if ((y * 13 / height) & 1)
		{
			*buffer++ = 255;
			*buffer++ = 255;
			*buffer++ = 255;
		}
        // red stripe
		else
		{
			*buffer++ = 178;
			*buffer++ = 34;
			*buffer++ = 52;
		}
	}
}
