/*
 * SolidColorEffect.cpp
 *
 *  Created on: 05.01.2018
 *      Author: sezep_000
 */

#include "FastLEDfx.h"

SolidColorEffect::SolidColorEffect(CRGB color) {
	this->color = color;
}

SolidColorEffect::~SolidColorEffect() { }

void SolidColorEffect::setColor(CRGB color) {
	this->color = color;
}

void SolidColorEffect::loop(float dT) {
	fill_solid(animator->ledData(), animator->ledCount(), color);
}
