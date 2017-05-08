#pragma once
#include "core/geometry/geometry.h"

#include "core/math/vec4.h"

class Plane : public Geometry
{
public:
    Plane(const vec4& normal, float d) :
        m_Normal(normal),
        m_D(d)
    {}

    virtual bool IntersectsWith(const Ray& r, IntersectionInfo& outInfo) override;
    virtual vec4 GetNormal(const vec4& collisionPoint) override { return m_Normal; }

private:
    vec4 m_Normal;
    float m_D;
};