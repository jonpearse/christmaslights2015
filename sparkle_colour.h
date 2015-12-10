#include <FastLED.h>

void init_sparkleColour()
{}

void frame_sparkleColour()
{
	fadeToBlackBy(leds, NUM_LEDs, 10);
	if (random8() < 128)
		leds[random16(NUM_LEDs)] = gPrimaryColours[random8(NUM_PRIMARY_COLOURS)];
}

pattern pSparkleColour = { &init_sparkleColour, &frame_sparkleColour };
