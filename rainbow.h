#include <FastLED.h>

#define RAINBOW_CYCLE	10000

void init_rainbow() {}

void frame_rainbow()
{
	int hue = round(((float)(millis() % RAINBOW_CYCLE) / (float)RAINBOW_CYCLE) * 255);

	//Serial.println(hue);
	int i = 0;
	for (; i < 50; i++)
		leds[i] = CHSV(hue, 255, 255);

	hue = (hue + 128) % 256;
	for (; i < NUM_LEDs; i++)
		leds[i] = CHSV(hue, 255, 255);


	if (random8() < 80)
		leds[random8(NUM_LEDs)] = CRGB::White;
}

pattern pRainbow = { &init_rainbow, &frame_rainbow };
