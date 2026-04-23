//
// Created by robsc on 4/15/26.
//

#ifndef SILICONGRAPHICS_MATH_H
#define SILICONGRAPHICS_MATH_H
#include "SpUtils.h"

namespace SpGL {

class Vector2 {
public:
	float x, y;
};

class Vector3 {
public:
	float x, y, z;
};

struct Color {
	Color(float R = 0.0f, float G = 0.0f, float B = 0.0f, float A = 0.0f, bool ZeroToOne = false);

	bool zeroToOne;
	float r, g, b, a;

	/// Return new Color from 0.0 - 1.0
	void NormalizeColorsToOne();
	void NormalizeColorsTo255();

	uint8 intR() const;
	uint8 intG() const;
	uint8 intB() const;
	uint8 intA() const;

};

class Math {

};

} // SpGL

#endif //SILICONGRAPHICS_MATH_H
