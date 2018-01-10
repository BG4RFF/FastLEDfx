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

float fx_wave_tri(float x) {
	return x < 0.5f ? x * 2.0f : 1.0f - ((x - 0.5f) * 2.0f);
}
