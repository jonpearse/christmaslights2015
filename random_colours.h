#include <FastLED.h>

void init_randomColours()
{
	// fill with random colours
	for (int i = 0; i < NUM_LEDs; i++)
		leds[i] = gPrimaryColours[random8(NUM_PRIMARY_COLOURS)];
}
void frame_randomColours()
{
	if (random8() > 80)
		return;

	leds[random8(NUM_LEDs)] = gPrimaryColours[random8(NUM_PRIMARY_COLOURS)];
}

pattern pRandomColours = { &init_randomColours, &frame_randomColours };
