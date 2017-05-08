#include "core/math/mathutil.h"
#include "core/geometry/plane.h"

bool Plane::IntersectsWith(const Ray& ray, IntersectionInfo& outInfo)
{
    float t = 0.f;
    float denom = vec4::Dot(m_Normal, ray.GetDirection());
    if (!popEqualNullWithEpsilon(denom))
    {
        t = -(m_D + vec4::Dot(m_Normal, ray.GetOrigin())) / denom;
        outInfo.m_IntersectionPoint = ray.GetOrigin() + ray.GetDirection() * t;
        outInfo.m_Distance = (outInfo.m_IntersectionPoint - ray.GetOrigin()).GetLength();
        outInfo.m_Normal = GetNormal(outInfo.m_IntersectionPoint);
        outInfo.m_U = outInfo.m_IntersectionPoint[0];
        outInfo.m_V = outInfo.m_IntersectionPoint[1];

        return popGreaterWithEpsilon(t, 0.f);
    }

    return false;
}