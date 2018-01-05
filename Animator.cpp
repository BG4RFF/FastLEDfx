/*
 * Animator.cpp
 *
 *  Created on: 05.01.2018
 *      Author: sezep_000
 */

#include "FastLEDfx.h"

Animator::Animator(CRGB* leds, uint16_t numLeds) {
	this->effect = nullptr;
	this->effectState = NONE;
	this->lastEffectCallTime = millis();
	this->leds = leds;
	this->numLeds = numLeds;
}

Animator::~Animator() { }

CRGB* Animator::ledData() {
	return leds;
}

uint16_t Animator::ledCount() {
	return numLeds;
}

float Animator::getDeltaTime() {
	uint32_t now = millis();
	float dT = (now - lastEffectCallTime) / 1000.0f;
	lastEffectCallTime = now;
	return dT;
}

void Animator::show(Effect* toLoad) {
	this->effect = toLoad;
	effect->load(this);
	effectState = BEGIN;
	lastEffectCallTime = millis();
}

void Animator::loop() {
	if (!effect) return;

	if (effectState == BEGIN) {
		effectState = LOOP;
		effect->begin();
		FastLED.show();
	} else if (effectState == LOOP) {
		effect->loop(getDeltaTime());
		FastLED.show();
	}

}

void Animator::loopFor(uint32_t msec) {
	if (!effect) return;

	uint32_t tgtTime = millis() + msec;
	while (millis() < tgtTime) {
		loop();
		delay(ANIMATOR_DELAY_TIME); // limit frame rate - also makes integrators work better
	}
}
