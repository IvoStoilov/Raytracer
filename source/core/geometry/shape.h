#pragma once
#include "core/gfx/color.h"
#include "core/camera/ray.h"

class Shape
{
public:
	virtual bool IntersectsWith(const Ray& ray, float& t) = 0;
	virtual vec4 GetNormal(const vec4& collisionPoint) = 0;
private:
	Color m_Color;
};