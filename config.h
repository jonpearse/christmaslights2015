#include <FastLED.h>

CRGB gPrimaryColours[] = {
	CRGB::Red,
	CRGB::Yellow,
	CRGB::Green,
	CRGB::Cyan,
	CRGB::Blue,
	CRGB::Magenta
};

#define NUM_PRIMARY_COLOURS 6

void fill_every(struct CRGB * leds, int numToFill, int interval, int offset, const struct CRGB& colour)
{
	for (int i = offset; i < numToFill; i += interval)
		leds[i] = colour;
}

typedef struct _pattern {
	void (*init)();
	void (*frame)();
} pattern;
