#include "core/geometry/sphere.h"
#include "core/math/mathutil.h"

Sphere::Sphere(const vec4& center, const float radius)
   : m_Center(center),
      m_Radius(radius)
{}

bool Sphere::IntersectsWith(const Ray& ray, IntersectionInfo& outInfo)
{
    vec4 H = ray.GetOrigin() - m_Center;
    float A = 1.f; // ray length = 1;
    float B = 2 * vec4::Dot(H, ray.GetDirection());
    float C = H.GetLengthSqr() - m_Radius * m_Radius;

    double discr = B * B - 4 * A * C;
    if (discr < 0.f) return false;
    
    double p1 = (-B - sqrt(discr)) / 2 * A;
    double p2 = (-B + sqrt(discr)) / 2 * A;
    double pRes = -1.f;
    if (popGreaterWithEpsilon(p1, 0.f))
        pRes = p1;
    else if (popGreaterWithEpsilon(p2, 0.f))
        pRes = p2;

    outInfo.m_IntersectionPoint = ray.GetOrigin() + ray.GetDirection() * pRes;
    outInfo.m_Distance = (outInfo.m_IntersectionPoint - m_Center).GetLength();
    outInfo.m_Normal = GetNormal(outInfo.m_IntersectionPoint);
    outInfo.m_U = outInfo.m_V = 0; // TODO (istoilov) : Calculate real UV coords;

    return popGreaterWithEpsilon(pRes, 0.f);
}

vec4 Sphere::GetNormal(const vec4& collisionPoint)
{
   vec4 res = collisionPoint - m_Center;
   res.Normalize();
   return res;
}