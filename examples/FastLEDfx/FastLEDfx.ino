#include <FastLED.h>
#include <FastLEDfx.h>

//Define a few things
//How many LEDs are there?
#define NUM_LEDS 17
//Which Pin on your controller provides the data?
#define DATA_PIN D4
//How bright should the LEDs be? (0-255)
#define LED_BRIGHTNESS 200
//What colour do you want for single colour effects?
#define BASE_HUE HUE_RED
//How slow should the fade be? Higher=slower
#define DELAY 100


CRGB leds[NUM_LEDS];
Animator* ledAnimator;

SolidColorEffect* solidColor;
GlitterEffect* glitter;
ScannerEffect* scanner;

void setup() {
	Serial.begin(115200);
	FastLED.addLeds<WS2811, DATA_PIN>(leds, NUM_LEDS);
	ledAnimator = new Animator(leds, NUM_LEDS);
	solidColor = new SolidColorEffect(CRGB::Red);
	glitter = new GlitterEffect(CRGB::White, CRGB::Black, 80);
	scanner = new ScannerEffect(CRGB::Red, CRGB::Black, 2.0f);
}

void loop() {

	ledAnimator->show(scanner);
	ledAnimator->loopFor(5000);

	solidColor->setColor(CRGB::Red);
	ledAnimator->show(solidColor);
	ledAnimator->loopFor(750);

	solidColor->setColor(CRGB::Green);
	ledAnimator->show(solidColor);
	ledAnimator->loopFor(750);

	solidColor->setColor(CRGB::Blue);
	ledAnimator->show(solidColor);
	ledAnimator->loopFor(750);

	ledAnimator->show(glitter);
	ledAnimator->loopFor(5000);

	//make all pixels black)
	fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
	delay(500);

	SOLID_SINGLE_GLITTER();
	SOLID_SINGLE();
	delay(500);
	SOLID_SINGLE_GLITTER();
	SOLID_SINGLE();
	delay(500);
	SOLID_SINGLE_GLITTER();
	SOLID_SINGLE();
	delay(500);

	//make all pixels black)
	fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
	delay(500);

	RAINBOW_FIXED();
	delay(3000);

	//make all pixels black)
	fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
	delay(500);

	RAINBOW_FADE();

	//make all pixels black)
	fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
	delay(500);

	SCANNER();
	SCANNER();
	SCANNER();

	//make all pixels black)
	fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
	delay(500);

	RANDOM_PIXELS();
	delay(1000);
	RANDOM_PIXELS();
	delay(1000);
	RANDOM_PIXELS();
	delay(1000);

}

//--------------------------------------------------------------------------------
//Show a Rainbow.
//--------------------------------------------------------------------------------
void RAINBOW_FIXED() {
	fill_gradient(leds, 0, CHSV(0, 255, LED_BRIGHTNESS), NUM_LEDS,
			CHSV(255, 255, LED_BRIGHTNESS), LONGEST_HUES);
	FastLED.show();
	delay(DELAY);
}

//--------------------------------------------------------------------------------
//Fades all LEDs through the colours of the rainbow.
//--------------------------------------------------------------------------------
void RAINBOW_FADE() {
	for (int h = 0; h < 256; h++) {
		fill_solid(leds, NUM_LEDS, CHSV(h, 255, LED_BRIGHTNESS));
		FastLED.show();
		delay(DELAY);
	}
}

//--------------------------------------------------------------------------------
//Fill strip with random pixels.
//--------------------------------------------------------------------------------
void RANDOM_PIXELS() {
	for (int i = 0; i < NUM_LEDS; i++) {
		int randhue = random(256);
		leds[i] = CHSV(randhue, 255, LED_BRIGHTNESS);
		FastLED.show();
		delay(DELAY);
	}
}

