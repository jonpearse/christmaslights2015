#include <FastLED.h>

#define OLD_CHASE_SEQUENCE_LENGTH	30000
#define OLD_CHASE_STEP_BASE          2000
#define OLD_CHASE_STEP_DELTA		 1000.0

// blah
#define OLD_CHASE_SEQUENCE_HALF		(OLD_CHASE_SEQUENCE_LENGTH / 2.0)

void init_chaseMono()
{}

void frame_chaseMono()
{
	float stepModifier	= abs((OLD_CHASE_SEQUENCE_HALF - (millis() % OLD_CHASE_SEQUENCE_LENGTH)) / OLD_CHASE_SEQUENCE_HALF);
	int   stepSize      = OLD_CHASE_STEP_BASE + round(stepModifier * OLD_CHASE_STEP_DELTA);
	int   stepBlat      = stepSize / 4;

	int   step          = floor((millis() % stepSize) / stepBlat);

	fadeToBlackBy(leds, NUM_LEDs, 50);
	fill_every(leds, NUM_LEDs, 4, step, CRGB::White);

	step = ++step % 4;
	fill_every(leds, NUM_LEDs, 4, step, CRGB::White);
}

pattern pChaseMono = { &init_chaseMono, &frame_chaseMono };
