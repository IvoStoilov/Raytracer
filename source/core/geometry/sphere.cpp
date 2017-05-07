#include "core/geometry/sphere.h"
#include "core/math/mathutil.h"

Sphere::Sphere(const vec4& center, const float radius)
	: m_Center(center),
      m_Radius(radius)
{}

bool Sphere::IntersectsWith(const Ray& ray, float& outT)
{
    vec4 H = ray.GetOrigin() - m_Center;
    float A = 1.f; // ray length = 1;
    float B = 2 * vec4::Dot(H, ray.GetDirection());
    float C = H.GetLengthSqr() - m_Radius * m_Radius;

    double discr = B * B - 4 * A * C;
    if (discr < 0.f) return false;
    
    double p1 = (-B - sqrt(discr)) / 2 * A;
    double p2 = (-B + sqrt(discr)) / 2 * A;

    if (p1 > 0.f)
    {
        outT = p1;
        return true;
    }
    else if (p2 > 0.f)
    {
        outT = p2;
        return true;
    }

    return false;

}

vec4 Sphere::GetNormal(const vec4& collisionPoint)
{
	vec4 res = collisionPoint - m_Center;
	res.Normalize();
	return res;
}