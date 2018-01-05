/*
 * FastLEDfx.h
 *
 *  Created on: 05.01.2018
 *      Author: sezep_000
 */

#ifndef INCLUDE_FASTLEDFX_FASTLEDFX_H_
#define INCLUDE_FASTLEDFX_FASTLEDFX_H_

#include <FastLED.h>
#include <stdint.h>

class Effect;

class Animator {
friend class Effect;
private:
	Effect* effect;
	uint32_t lastEffectCallTime;
	CRGB* leds;
	uint16_t numLeds;
	float getDeltaTime();
public:
	Animator(CRGB* leds, uint16_t numLeds);
	virtual ~Animator();
	CRGB* ledData();
	uint16_t ledCount();
	void show(Effect* toLoad);
	void loop();
	void loopFor(uint32_t msec);
};

class Effect {
friend class Animator;
private:
	void begin(Animator* animator);
public:
	Effect();
	virtual ~Effect();
protected:
	Animator* animator;
	virtual void loop(float dT) = 0;
};

class SolidColorEffect : public Effect {
private:
	CRGB color;
public:
	SolidColorEffect(CRGB color);
	virtual ~SolidColorEffect();
	void setColor(CRGB color);
	void loop(float dT);
};

#endif /* INCLUDE_FASTLEDFX_FASTLEDFX_H_ */
