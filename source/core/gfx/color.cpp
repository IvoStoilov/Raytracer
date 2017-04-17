#include "Color.h"

Color Color::RED = Color(255, 0, 0);
Color Color::GREEN = Color(0, 255, 0);
Color Color::BLUE = Color(0, 0, 255);

Color Color::BLACK = Color(0, 0, 0);
Color Color::WHITE = Color(255, 255, 255);

Color::Color()
{
	m_ColorVector[0] = 0;
	m_ColorVector[1] = 0;
	m_ColorVector[2] = 0;
	m_ColorVector[3] = 0;
}

Color::Color(float r, float g, float b, float a)
{
	m_ColorVector[0] = r;
	m_ColorVector[1] = g;
	m_ColorVector[2] = b;
	m_ColorVector[3] = a;
}

Color::Color(float r, float g, float b)
{
	m_ColorVector[0] = r;
	m_ColorVector[1] = g;
	m_ColorVector[2] = b;
	m_ColorVector[3] = 1.f;
}

Color::Color(const vec4& colorVector)
{
	m_ColorVector[0] = colorVector[0];
	m_ColorVector[1] = colorVector[1];
	m_ColorVector[2] = colorVector[2];
	m_ColorVector[3] = colorVector[3];
}

void Color::operator=(const Color& lhs)
{
	m_ColorVector[0] = lhs.m_ColorVector[0];
	m_ColorVector[1] = lhs.m_ColorVector[1];
	m_ColorVector[2] = lhs.m_ColorVector[2];
	m_ColorVector[3] = lhs.m_ColorVector[3];
}

Color Color::operator*(const float lhs) const
{
	return Color(m_ColorVector * lhs);
}

Color Color::operator+(const Color& lhs) const
{
	return Color(m_ColorVector + lhs.m_ColorVector);
}