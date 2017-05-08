#pragma once
#include "core/geometry/geometry.h"
#include "core/math/vec4.h"

class Sphere : public Geometry
{
public:
   Sphere(const vec4& center, const float radius);

   virtual bool IntersectsWith(const Ray& ray, IntersectionInfo& outInfo) override;
   virtual vec4 GetNormal(const vec4& collisionPoint) override;

   inline vec4 GetCenter() const { return m_Center; }
   inline float GetRadius() const { return m_Radius; }

private:
   vec4 m_Center;
   float m_Radius;
};
