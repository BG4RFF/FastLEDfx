/*
 * GlitterEffect.cpp
 *
 *  Created on: 05.01.2018
 *  Author: seze
 */

#include "FastLEDfx.h"

GlitterEffect::GlitterEffect(CRGB foreground, CRGB background, fract8 chance) {
	this->foreground = foreground;
	this->background = background;
	this->chance = chance;
	this->glitterPos = 0;
}

GlitterEffect::~GlitterEffect() { }

void GlitterEffect::loop(float dT) {

	float timeChance = chance * dT;

	if (random8() < timeChance) {
		animator->ledData()[glitterPos] = background;
		glitterPos = random16(animator->ledCount());
		animator->ledData()[glitterPos] = foreground;
	}

}
