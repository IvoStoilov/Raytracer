#include "core/math/vec4.h"

vec4::vec4()
{	
	_data[0] = _data[1] = _data[2] = _data[3] = 0.0f;
}

vec4::vec4(float x, float y, float z, float w)
{
	_data[0] = x;
	_data[1] = y;
	_data[2] = z;
	_data[3] = w;
}

vec4::vec4(const vec4& value)
{
	_data[0] = value._data[0];
	_data[1] = value._data[1];
	_data[2] = value._data[2];
	_data[3] = value._data[3];
}

void vec4::operator= (const vec4& lhs)
{
	_data[0] = lhs._data[0];
	_data[1] = lhs._data[1];
	_data[2] = lhs._data[2];
	_data[3] = lhs._data[3];
}

void vec4::operator+= (const vec4& lhs)
{
	_data[0] += lhs._data[0];
	_data[1] += lhs._data[1];
	_data[2] += lhs._data[2];
	_data[3] += lhs._data[3];
}

vec4 vec4::operator- (const vec4& lhs) const
{
	return vec4(_data[0] - lhs._data[0],
		_data[1] - lhs._data[1],
		_data[2] - lhs._data[2],
		_data[3] - lhs._data[3]);
}

vec4 vec4::operator+ (const vec4& lhs) const
{
	return vec4(_data[0] + lhs._data[0],
				_data[1] + lhs._data[1],
				_data[2] + lhs._data[2],
				_data[3] + lhs._data[3]);
}

vec4 vec4::operator/(const float lhs) const
{
	return vec4(_data[0] / lhs,
				_data[1] / lhs,
				_data[2] / lhs,
				_data[3] / lhs);
}

vec4 vec4::operator*(const float lhs) const
{
	return vec4(_data[0] * lhs,
				_data[1] * lhs,
				_data[2] * lhs,
				_data[3] * lhs);
}

float& vec4::operator[] (uint32_t i)
{
	return _data[i];
}

float vec4::operator[](uint32_t i) const
{
	return _data[i];
}

float vec4::SquareLength() const
{
	return vec4::Dot(*this, *this);
}

float vec4::GetLength() const
{
	return sqrt(SquareLength());
}

vec4 vec4::Normalize() const
{
	float l = GetLength();
	return this->operator/(l);
}

void vec4::Print() const
{
	printf("(%.2f, %.2f, %.2f, %.2f)\n", _data[0], _data[1], _data[2], _data[3]);
}

float vec4::Dot(const vec4& a, const vec4& b)
{
	float res = 0.f;
	for (uint8_t i = 0; i < 4; ++i)
		res += a[i] * b[i];
	return res;
}

void vec4::Cross(const vec4&a, const vec4& b)
{
	//TODO : someday;
	//return Vec4::GetZero();
}