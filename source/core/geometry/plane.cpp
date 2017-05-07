#include "core/math/mathutil.h"
#include "core/geometry/plane.h"

bool Plane::IntersectsWith(const Ray& ray, float& t)
{
	float denom = vec4::Dot(m_Normal, ray.GetDirection());
	if (!popEqualNullWithEpsilon(denom))
	{
		t = - (m_D + vec4::Dot(m_Normal, ray.GetOrigin())) / denom;
		return popGreaterWithEpsilon(t, 0.f);
	}
	
	return false;
}