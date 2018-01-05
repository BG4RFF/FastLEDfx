#include <FastLED.h>
//Define a few things
//How many LEDs are there?
#define NUM_LEDS 10
//Which Pin on your controller provides the data?
#define DATA_PIN 6
//How bright should the LEDs be? (0-255)
#define LED_BRIGHTNESS 200
//What colour do you want for single colour effects?
#define BASE_HUE HUE_RED
//How slow should the fade be? Higher=slower
#define DELAY 100
  
CRGB leds[NUM_LEDS];

 void setup() { 
       FastLED.addLeds<WS2811, DATA_PIN>(leds, NUM_LEDS);
   }

  void loop() { 

    SOLID_SINGLE();
    SOLID_SINGLE();
    SOLID_SINGLE();
    delay(3000);

    //make all pixels black)
    fill_solid (leds, NUM_LEDS, CHSV(0,0,0));
    delay(500);

    RAINBOW_FIXED();
    delay(3000);

    //make all pixels black)
    fill_solid (leds, NUM_LEDS, CHSV(0,0,0));
    delay(500);

    RAINBOW_FADE();
    
    //make all pixels black)
    fill_solid (leds, NUM_LEDS, CHSV(0,0,0));
    delay(500);

    SCANNER();
    SCANNER();
    SCANNER();

    //make all pixels black)
    fill_solid (leds, NUM_LEDS, CHSV(0,0,0));
    delay(500);

    }

//--------------------------------------------------------------------------------
//--------------------------------Here be effects!--------------------------------
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//Show one solid colour.
//--------------------------------------------------------------------------------
  void SOLID_SINGLE()
  {
    fill_solid(leds, NUM_LEDS, CHSV(BASE_HUE, 255, LED_BRIGHTNESS));
    FastLED.show();
    delay(DELAY);
  }

//--------------------------------------------------------------------------------
//Show a Rainbow.
//--------------------------------------------------------------------------------
  void RAINBOW_FIXED()
  {
    fill_gradient(leds,0,CHSV(0,255,LED_BRIGHTNESS),NUM_LEDS,CHSV(255,255,LED_BRIGHTNESS),LONGEST_HUES); 
    FastLED.show();
    delay(DELAY);
  }

//--------------------------------------------------------------------------------
//Fades all LEDs through the colours of the rainbow.
//--------------------------------------------------------------------------------
  void RAINBOW_FADE()
  {
    for(int h = 0; h < 256; h++) 
    { 
    fill_solid (leds, NUM_LEDS, CHSV(h, 255, LED_BRIGHTNESS));
    FastLED.show(); 
    delay(DELAY); 
    }
  }

//--------------------------------------------------------------------------------
//It's K.I.T.T.!
//--------------------------------------------------------------------------------
  void SCANNER()
  {
    //make all pixels black)
    fill_solid (leds, NUM_LEDS, CHSV(0,0,0));

  //run in one direction
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(BASE_HUE, 255, 255);
    FastLED.show(); 
    leds[i] = CRGB::Black;
    delay(DELAY);
  }

  //run back
  for(int i = (NUM_LEDS)-1; i >= 0; i--) {
    leds[i] = CHSV(BASE_HUE, 255, 255);
    FastLED.show();
    leds[i] = CRGB::Black;
    delay(DELAY);
  }
  }

