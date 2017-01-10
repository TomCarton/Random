// renderCountryFlag.h
//
// written by Thomas CARTON
//

#ifndef __RenderCountryFlag_h__
#define __RenderCountryFlag_h__


typedef enum
{
	kCountryFlagFrench, // 'FR',
	kCountryFlagJapanese, // 'JP',
	kCountryFlagAmerican, // 'US',
	kCountryFlagSwiss, // 'CH',
	kCountryFlagGerman, // 'DE',
	kCountryFlagFinnish, // 'FI',
	kCountryFlagSwedish, // 'SE',

	kCountryFlagCount

} CountryFlagType;


void RenderFlag(CountryFlagType type, unsigned char *buffer, unsigned int width, unsigned int height);

void RenderFrenchFlag(unsigned char *buffer, unsigned int width, unsigned int height);
void RenderJapaneseFlag(unsigned char *buffer, unsigned int width, unsigned int height);
void RenderAmericanFlag(unsigned char *buffer, unsigned int width, unsigned int height);
void RenderSwissFlag(unsigned char *buffer, unsigned int width, unsigned int height);
void RenderGermanFlag(unsigned char *buffer, unsigned int width, unsigned int height);
void RenderFinnishFlag(unsigned char *buffer, unsigned int width, unsigned int height);
void RenderSwedishFlag(unsigned char *buffer, unsigned int width, unsigned int height);


#endif // __RenderCountryFlag_h__
