#pragma once
#include "core/math/vec4.h"

class Ray
{
public:
	Ray(const vec4& point, const vec4& direction)
		: m_Point(point), m_Direction(direction)
	{}

	inline vec4 GetPoint() const { return m_Point; }
	inline vec4 GetDirection() const { return m_Direction; }

private:
	vec4 m_Point;
	vec4 m_Direction;
};