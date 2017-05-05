#include "core/geometry/sphere.h"
#include "core/math/mathutil.h"

Sphere::Sphere(const vec4& center, const float radius)
	: m_Center(center),
      m_Radius(radius)
{}

bool Sphere::IntersectsWith(const Ray& ray, float& outT)
{
	vec4 rayOrigin = ray.GetOrigin();
	vec4 rayDirection = ray.GetDirection();

	vec4 trace = rayOrigin - m_Center;
	
	const float b = 2 * vec4::Dot(trace, rayDirection);
	const float c = vec4::Dot(trace, trace) - m_Radius * m_Radius;
	
	float discriminant = b * b - 4 * c;
	discriminant = sqrt(discriminant);

	if (popLesserWithEpsilon(discriminant, 0.0f))
		return false;

	const float t1 = -b - discriminant;
	const float t2 = -b + discriminant;

	outT = (t1 < t2 && t1 > 0) ? t1 : t2;
	return true;
}

vec4 Sphere::GetNormal(const vec4& collisionPoint)
{
	vec4 res = collisionPoint - m_Center;
	res.Normalize();
	return res;
}