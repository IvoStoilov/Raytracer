#pragma once
#include "core/gfx/color.h"
#include "core/camera/ray.h"

class Shape
{
public:
   virtual bool IntersectsWith(const Ray& ray, float& t) = 0;
   virtual vec4 GetNormal(const vec4& collisionPoint) = 0;

   inline Color GetColor() const { return m_Color; }
   inline void SetColor(const Color& color) { m_Color = color; }
private:
   Color m_Color;
};