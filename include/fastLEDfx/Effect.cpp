/*
 * EffectBase.cpp
 *
 *  Created on: 05.01.2018
 *      Author: sezep_000
 */

#include "FastLEDfx.h"

Effect::Effect() {
	this->animator = nullptr;
}

Effect::~Effect() { }

void Effect::begin(Animator* animator) {
	this->animator = animator;
}

