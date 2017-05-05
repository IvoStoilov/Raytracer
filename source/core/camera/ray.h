#pragma once
#include "core/math/vec4.h"

class Ray
{
public:
	Ray(const vec4& point, const vec4& direction)
		: m_Origin(point), m_Direction(direction)
	{}

	inline void SetOrigin(const vec4& value) { m_Origin = value; }
	inline void SetDirection(const vec4 value){ m_Direction = value; }

	inline vec4 GetOrigin() const { return m_Origin; }
	inline vec4 GetDirection() const { return m_Direction; }

private:
	vec4 m_Origin;
	vec4 m_Direction;
};