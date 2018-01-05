/*
 * FastLEDfx.cpp
 *
 *  Created on: 05.01.2018
 *  Author: seze
 */

float fx_linear(float a, float b, float m) {
	return a * (1.0f - m) + b * m;
}

float fx_clamp(float v, float min, float max) {
	return v < min ? min : v > max ? max : v;
}
