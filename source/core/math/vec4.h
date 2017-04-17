#pragma once
#include <stdio.h>
#include <stdint.h>
#include <math.h>

class vec4
{
public:
	vec4();
	vec4(const vec4& value);
	vec4(float x, float y, float z, float w);
	
	void operator=  (const vec4& lhs);
	void operator+= (const vec4& lhs);

	vec4 operator+ (const vec4& lhs) const;
	vec4 operator- (const vec4& lhs) const;

	vec4 operator/ (const float lhs) const;
	vec4 operator* (const float lhs) const;


	float& operator[] (uint32_t i);
	float operator[](uint32_t i) const;

	float SquareLength() const;
	float GetLength() const;

	vec4 Normalize() const;
	
	void Print() const;

	static float Dot(const vec4& a, const vec4& b);
	static void Cross(const vec4&a, const vec4& b);

	static inline vec4 GetZero()  { return vec4(0.f, 0.f, 0.f, 0.f); }
	static inline vec4 GetBaseI() { return vec4(1.f, 0.f, 0.f, 0.f); }
	static inline vec4 GetBaseJ() { return vec4(0.f, 1.f, 0.f, 0.f); }
	static inline vec4 GetBaseK() { return vec4(0.f, 0.f, 1.f, 0.f); }
	static inline vec4 GetBaseW() { return vec4(0.f, 0.f, 0.f, 1.f); }

private:
	float _data[4];

};