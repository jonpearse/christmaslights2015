#include <FastLED.h>
void init_sparkleMono()
{}

void frame_sparkleMono()
{
	fadeToBlackBy(leds, NUM_LEDs, 10);
	if (random8() < 80)
		leds[random16(NUM_LEDs)] += CRGB::White;
}

pattern pSparkleMono = { &init_sparkleMono, &frame_sparkleMono };
