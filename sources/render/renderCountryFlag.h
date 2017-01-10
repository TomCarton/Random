// renderCountryFlag.h
//
// written by Thomas CARTON
//

#ifndef __RenderCountryFlag_h__
#define __RenderCountryFlag_h__


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmultichar"

typedef enum
{
	kCountryFlagFrench		= 'FR',
	kCountryFlagJapanese 	= 'JP',
	kCountryFlagAmerican 	= 'US',
	kCountryFlagFinnish 	= 'FI',
} CountryFlagType;

#pragma clang diagnostic pop


void RenderFlag(CountryFlagType type, unsigned char *buffer, unsigned int width, unsigned int height);

void RenderFrenchFlag(unsigned char *buffer, unsigned int width, unsigned int height);
void RenderJapaneseFlag(unsigned char *buffer, unsigned int width, unsigned int height);
void RenderAmericanFlag(unsigned char *buffer, unsigned int width, unsigned int height);
void RenderFinnishFlag(unsigned char *buffer, unsigned int width, unsigned int height);


#endif // __RenderCountryFlag_h__
