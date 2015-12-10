#include <FastLED.h>
#include "config.h"

// basic setup
#define LED_TYPE	WS2801
#define LED_ORDER	RGB
#define NUM_LEDs	100
#define BRIGHTNESS 	96

#define P_BUTTON	21

#define FPS			120

// local variables
CRGB leds[NUM_LEDs];
int  current_pattern = 0;

#include "patterns.h";

void setup()
{
	// init delay
	delay(1000);

	// init our LED string
	FastLED.addLeds<LED_TYPE,LED_ORDER>(leds, NUM_LEDs).setCorrection(TypicalLEDStrip);
	FastLED.setBrightness(BRIGHTNESS);
	FastLED.clear(true);

	// set button as an output and engage pullup
	pinMode(P_BUTTON, INPUT);
	digitalWrite(P_BUTTON, HIGH);
}

bool lastButtonState = false;
void loop()
{
	// 1. have we got a button press
	bool currButtonState = digitalRead(P_BUTTON);
	if (currButtonState != lastButtonState)
	{
		if (currButtonState)
		{
			current_pattern = ++current_pattern % NUM_PATTERNS;
			gPatterns[current_pattern].init();
		}

		lastButtonState = currButtonState;
	}

	// 2. call the appropriate pattern
	gPatterns[current_pattern].frame();

	// 3. update and hold
	FastLED.show();
	FastLED.delay(1000 / FPS);
}


void frame_off()
{
	fill_solid(leds, NUM_LEDs, CRGB::Black);
}
