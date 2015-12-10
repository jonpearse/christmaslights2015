#include <FastLED.h>

/**
 * Sets all LEDs to black, otherwise does nothing =).
 */
void init_null()
{
	fill_solid(leds, NUM_LEDs, CRGB::Black);
}
void frame_null()
{
}

pattern pNull = { &init_null, &frame_null };
