#pragma once
#include <stdint.h>

#define EPSILON 0.001f
#define PI		3.14159265f
#define _2_PI    6.28318530f

#define popLesserOrEqualWithEpsilon (lhs, rhs)									\
	(lhs - rhs < EPSILON)

#define popLesserWithEpsilon(lhs, rhs)											\
	(lhs - rhs < -EPSILON)

#define popEqualWithEpsilon (lhs, rhs)											\
	((lhs - rhs < EPSILON) && (lhs - rhs > -EPSILON))

class MathUtil
{
public:
	static uint32_t Clamp(const uint32_t min, const uint32_t max, uint32_t x);
	static float Clamp(const float min, const float max, const float x);
	static inline float ToRads(float degrees) { return degrees * PI / 180.0f; }
	static inline float ToDegrees(float rads) { return rads * 180.f / PI; }
	static inline float Sqr(float value)	  { return value * value; }
};