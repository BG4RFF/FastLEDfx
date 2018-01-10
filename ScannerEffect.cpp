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
	this->scanTime = scanTime;
	this->effectTime = 0.0f;
}

ScannerEffect::~ScannerEffect() { }

void ScannerEffect::loop(float dT) {
	effectTime += dT;

	uint16_t pos = fx_wave_tri(effectTime / scanTime) * animator->ledCount();
	fill_solid(animator->ledData(), animator->ledCount(), background);
	animator->ledData()[pos] = foreground;

	if (effectTime > scanTime)
		effectTime -= scanTime;

}
