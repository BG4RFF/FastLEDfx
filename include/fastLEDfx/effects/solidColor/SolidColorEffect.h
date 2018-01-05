/*
 * SolidColorEffect.h
 *
 *  Created on: 05.01.2018
 *      Author: sezep_000
 */

#ifndef INCLUDE_FASTLEDFX_EFFECTS_SOLIDCOLOR_SOLIDCOLOREFFECT_H_
#define INCLUDE_FASTLEDFX_EFFECTS_SOLIDCOLOR_SOLIDCOLOREFFECT_H_

#include <FastLED.h>
#include "../../FastLEDfx.h"

class SolidColorEffect : public Effect {
private:
	CRGB color;
public:
	SolidColorEffect(CRGB color);
	virtual ~SolidColorEffect();
	void setColor(CRGB color);
	void loop(float dT);
};

#endif /* INCLUDE_FASTLEDFX_EFFECTS_SOLIDCOLOR_SOLIDCOLOREFFECT_H_ */
