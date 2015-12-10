#include <FastLED.h>

CRGB gOldSchoolColours[] = { CRGB::Red, CRGB::Yellow, CRGB::Green, CRGB::Blue };

void init_chase() {}

void frame_chase()
{
	float stepModifier	= abs((OLD_CHASE_SEQUENCE_HALF - (millis() % OLD_CHASE_SEQUENCE_LENGTH)) / OLD_CHASE_SEQUENCE_HALF);
	int   stepSize      = OLD_CHASE_STEP_BASE + round(stepModifier * OLD_CHASE_STEP_DELTA);
	int   stepBlat      = stepSize / 4;

	int   step          = floor((millis() % stepSize) / stepBlat);

	fadeToBlackBy(leds, NUM_LEDs, 50);
	fill_every(leds, NUM_LEDs, 4, step, gOldSchoolColours[step]);

	step = ++step % 4;
	fill_every(leds, NUM_LEDs, 4, step, gOldSchoolColours[step]);
}

pattern pChase = { &init_chase, &frame_chase };
