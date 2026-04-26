//
// Created by robsc on 4/15/26.
//

#include "Math.h"

namespace SpGL {
Color::Color(float R, float G, float B, float A, bool ZeroToOne) {
	this->a = A;
	this->r = R;
	this->g = G;
	this->b = B;
	this->zeroToOne = ZeroToOne;
}

void Color::NormalizeColorsToOne() {
	if (zeroToOne) {
		SpUtils::PrintConsole(SP_WARNING, "Color already normalized to one!");
	}
	zeroToOne = true;
	a = a / 255.0f;
	r = r / 255.0f;
	g = g / 255.0f;
	b = b / 255.0f;
}

void Color::NormalizeColorsTo255() {
	if (!zeroToOne) {
		SpUtils::PrintConsole(SP_WARNING, "Color already normalized to 255!");
	}
	zeroToOne = false;
	a = a * 255.0f;
	r = r * 255.0f;
	g = g * 255.0f;
	b = b * 255.0f;

}

uint8 Color::intR() const {
	if (zeroToOne) {
		return static_cast<uint8>(r * 255.0f);
	}
	return static_cast<uint8>(r * 255.0f);
}

uint8 Color::intG() const {
	if (zeroToOne) {
		return static_cast<uint8>(g * 255.0f);
	}
	return static_cast<uint8>(g * 255.0f);
}

uint8 Color::intB() const {
	if (zeroToOne) {
		return static_cast<uint8>(b * 255.0f);
	}
	return static_cast<uint8>(b * 255.0f);
}

uint8 Color::intA() const {
	if (zeroToOne) {
		return static_cast<uint8>(a * 255.0f);
	}
	return static_cast<uint8>(a * 255.0f);
}

} // SpGL