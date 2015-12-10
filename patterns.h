// grab patterns
#include "null.h";
#include "sparkle_mono.h";
#include "sparkle_colour.h";
#include "chase_mono.h";
#include "chase.h";
#include "random_colours.h";
#include "rainbow.h";

pattern gPatterns[] = {
	pNull,
	pSparkleMono,
	pSparkleColour,
	pChaseMono,
	pChase,
	pRandomColours,
	pRainbow
};

#define NUM_PATTERNS (sizeof(gPatterns)/sizeof(pattern))
