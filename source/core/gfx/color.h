#pragma once
#include <stdint.h>
#include "core/math/vec4.h"

//RGBA implementation
class Color
{
public:
   static Color RED;
   static Color GREEN;
   static Color BLUE;

   static Color WHITE;
   static Color BLACK;

public:
   Color();
   Color(const vec4& rgbaVector);
   Color(float r, float g, float b);
   Color(float r, float g, float b, float a);

   void operator= (const Color& lhs);

   Color operator+(const Color& lhs) const;

   Color operator* (const float lhs) const;

   inline float GetR() const { return m_ColorVector[0]; }
   inline float GetG() const { return m_ColorVector[1]; }
   inline float GetB() const { return m_ColorVector[2]; }
   inline float GetA() const { return m_ColorVector[3]; }

   uint32_t ToARGBHex() const;

private:
   vec4 m_ColorVector;
};