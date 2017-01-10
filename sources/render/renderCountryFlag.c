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

		case kCountryFlagswiss:
			RenderSwissFlag(buffer, width, height);
			break;

		case kCountryFlagGerman:
			RenderGermanFlag(buffer, width, height);
			break;

		case kCountryFlagFinnish:
			RenderFinnishFlag(buffer, width, height);
			break;

		case kCountryFlagSwedish:
			RenderSwedishFlag(buffer, width, height);
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

void RenderSwissFlag(unsigned char *buffer, unsigned int width, unsigned int height)
{
	unsigned int lr = 436 * width / 1500;
	unsigned int ul = 654 * width / 1500;
	unsigned int ur = 842 * width / 1500;

	unsigned int ud = 188 * height / 1000;
	unsigned int uh = 406 * height / 1000;
	unsigned int ub = 594 * height / 1000;

	for (unsigned int k = 0; k < width * height; ++k)
	{
		unsigned int x = k % width;
		unsigned int y = k / width;

		unsigned int c = 0xffffff;
		if (((x < ul || x > ur) && (y < uh || y > ub)) || y < ud || y > height - ud || x < lr || x > width - lr)
		{
			c = 0xd52b1e;
		}

		*buffer++ = c >> 16;
		*buffer++ = c >> 8;
		*buffer++ = c;
	}
}

void RenderGermanFlag(unsigned char *buffer, unsigned int width, unsigned int height)
{
	unsigned int color[] = { 0x000000, 0xdd0000, 0xffce00 };
	unsigned int first = height / 3;

	for (unsigned int k = 0; k < width * height; ++k)
	{
		unsigned int y = k / width;
		unsigned int c = color[y / first];

		*buffer++ = c >> 16;
		*buffer++ = c >> 8;
		*buffer++ = c;
	}
}

void RenderFinnishFlag(unsigned char *buffer, unsigned int width, unsigned int height)
{
	unsigned int left = 5 * width / 18;
	unsigned int right = 8 * width / 18;
	unsigned int up = 4 * height / 11;
	unsigned int down = 7 * height / 11;

	for (unsigned int k = 0; k < width * height; ++k)
	{
		unsigned int x = k % width;
		unsigned int y = k / width;

		int c = ((x >= left && x <= right) || (y >= up && y <= down)) ? 0 : 255;

		*buffer++ = c ?: 0;
		*buffer++ = c ?: 71;
		*buffer++ = c ?: 186;
	}
}

void RenderSwedishFlag(unsigned char *buffer, unsigned int width, unsigned int height)
{
	unsigned int left = 5 * width / 16;
	unsigned int right = 7 * width / 16;
	unsigned int up = 4 * height / 10;
	unsigned int down = 6 * height / 10;

	for (unsigned int k = 0; k < width * height; ++k)
	{
		unsigned int x = k % width;
		unsigned int y = k / width;

		int c = ((x >= left && x <= right) || (y >= up && y <= down)) ? 0xfecc00 : 0x006aa7;

		*buffer++ = c >> 16;
		*buffer++ = c >> 8;
		*buffer++ = c;
	}
}
