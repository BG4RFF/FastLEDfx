/*
 * ScannerEffect.cpp
 *
 *  Created on: 05.01.2018
 *  Author: seze
 */

#include "FastLEDfx.h"

ScannerEffect::ScannerEffect(CRGB foreground, CRGB background, float scanTime) {
	this->foreground = foreground;
	this->background = background;
	this->scanHalfTime = scanTime * 0.5f;
	this->effectTime = 0.0f;
}

ScannerEffect::~ScannerEffect() { }

void ScannerEffect::loop(float dT) {
	effectTime += dT;

	uint16_t max = animator->ledCount() - 1;
	uint16_t pos = fx_linear(0, max, effectTime / scanHalfTime);
	pos = effectTime > scanHalfTime ? max - (pos - max) : pos;
	pos = fx_clamp(pos, 0, max);

	fill_solid(animator->ledData(), animator->ledCount(), background);
	animator->ledData()[pos] = foreground;

	if (effectTime > 2.0f * scanHalfTime)
		effectTime -= 2.0f * scanHalfTime;

}
