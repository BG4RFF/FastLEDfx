#include <FastLED.h>
#include <FastLEDfx.h>

//Define a few things
//How many LEDs are there?
#define NUM_LEDS 17
//Which Pin on your controller provides the data?
#define DATA_PIN 4
//How bright should the LEDs be? (0-255)
#define LED_BRIGHTNESS 200
//What colour do you want for single colour effects?
#define BASE_HUE HUE_RED
//How slow should the fade be? Higher=slower
#define DELAY 100
//Which effect should be displayed by default?
#define DEFAULT_EFFECT 0

CRGB leds[NUM_LEDS];
Animator* ledAnimator;

SolidColorEffect* solidColor;

void setup() {
  Serial.begin(115200);
  FastLED.addLeds<WS2811, DATA_PIN>(leds, NUM_LEDS);
  ledAnimator = new Animator(leds, NUM_LEDS);
  solidColor = new SolidColorEffect(CRGB::Red);
}

int EFFECT = DEFAULT_EFFECT;

void loop() {

  Serial.write("That is what's on the menu:\r\n");
  Serial.write("0 - Cycle through the demo.\r\n");
  Serial.write("1 - Show a single colour on all LEDs.\r\n");
  Serial.write("2 - Show a single colour with some glitter.\r\n");
  Serial.write("3 - Display a rainbow.\r\n");
  Serial.write("4 - Fade through the colours of the rainbow.\r\n");
  Serial.write("5 - K.I.T.T.\r\n");
  Serial.write("6 - Show random pixels.\r\n");
  Serial.write("----------------------------------------------\r\n");
  Serial.write("Have fun!\r\n");
  Serial.write(EFFECT);

  if (Serial.available() > 0) {
                // read the incoming byte:
                String inEFFECT = Serial.readString();
                EFFECT = inEFFECT.toInt();

                // say what you got:
                Serial.print("I received: ");
                Serial.print(EFFECT);
        }

  switch(EFFECT) {

    case 1:
      SOLID_SINGLE();
      break;

    case 2:
      SOLID_SINGLE_GLITTER();
      break;

    case 3:
      RAINBOW_FIXED();
      break;

    case 4:
      RAINBOW_FADE();
      break;

    case 5:
      SCANNER();
      break;

    case 6:
      RANDOM_PIXELS();
      break;

    default:

  solidColor->setColor(CRGB::Red);
  ledAnimator->show(solidColor);
  ledAnimator->loopFor(750);

  solidColor->setColor(CRGB::Green);
  ledAnimator->show(solidColor);
  ledAnimator->loopFor(750);

  solidColor->setColor(CRGB::Blue);
  ledAnimator->show(solidColor);
  ledAnimator->loopFor(750);
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
}

//--------------------------------------------------------------------------------
//--------------------------------Here be effects!--------------------------------
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//Add Glitter (taken from the FastLED Example)
//--------------------------------------------------------------------------------
void addGlitter(fract8 chanceOfGlitter) {
  if (random8() < chanceOfGlitter) {
    leds[random16(NUM_LEDS)] += CRGB::White;
  }
}

//--------------------------------------------------------------------------------
//Show one solid colour.
//--------------------------------------------------------------------------------
void SOLID_SINGLE() {
  fill_solid(leds, NUM_LEDS, CHSV(BASE_HUE, 255, LED_BRIGHTNESS));
  FastLED.show();
  delay(DELAY);
}

//--------------------------------------------------------------------------------
//Show one solid colour with glitter.
//--------------------------------------------------------------------------------
void SOLID_SINGLE_GLITTER() {
  fill_solid(leds, NUM_LEDS, CHSV(BASE_HUE, 255, LED_BRIGHTNESS));
  addGlitter(80);
  FastLED.show();
  delay(DELAY);
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
//It's K.I.T.T.!
//--------------------------------------------------------------------------------
void SCANNER() {
  //make all pixels black)
  fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));

  //run in one direction
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(BASE_HUE, 255, LED_BRIGHTNESS);
    FastLED.show();
    leds[i] = CRGB::Black;
    delay(DELAY);
  }

  //run back
  for (int i = (NUM_LEDS) - 1; i >= 0; i--) {
    leds[i] = CHSV(BASE_HUE, 255, LED_BRIGHTNESS);
    FastLED.show();
    leds[i] = CRGB::Black;
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
