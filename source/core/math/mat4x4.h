#pragma once
#include "core/math/vec4.h"
#include "core/math/mathutil.h"

__declspec(align(16)) class mat4x4
{
private:
	vec4 _data[4];

public:
	mat4x4();
	mat4x4(const vec4& rowI, const vec4& rowJ, const vec4& rowK, const vec4& rowW);
	mat4x4(const mat4x4& value);

	inline void SetRowI(const vec4& v) { _data[0] = v; }
	inline void SetRowJ(const vec4& v) { _data[1] = v; }
	inline void SetRowK(const vec4& v) { _data[2] = v; }
	inline void SetRowW(const vec4& v) { _data[3] = v; }

	void operator=(const mat4x4& value);
	inline const vec4 operator[] (const uint32_t row) const;
	//inline vec4& operator[] (const uint32_t row);

	mat4x4 GetTranspose() const;
	static void Tranpose(mat4x4& mat);

	mat4x4 operator*(mat4x4& lhs);

	static inline mat4x4 GetRotateXAxisMatrix(float rads)
	{
		return mat4x4(vec4(1.f, 0.f	     , 0.f       , 0.f),
					  vec4(0.f, cos(rads), -sin(rads), 0.f),
					  vec4(0.f, sin(rads),  cos(rads), 0.f),
			          vec4(0.f, 0.f      , 0.f       , 1.f));
	}

	static inline mat4x4 GetRotateYAxisMatrix(float rads)
	{
		return mat4x4(vec4(+cos(rads), 0.f, +sin(rads), 0.f),
					  vec4(       0.f, 1.f,        0.f, 0.f),
					  vec4(-sin(rads), 0.f, +cos(rads), 0.f),
					  vec4(		  0.f, 0.f,        0.f, 1.f));
	}

	static inline mat4x4 GetRotateZAxisMatrix(float rads)
	{
		return mat4x4(vec4(+cos(rads), -sin(rads), 0.f, 0.f),
					  vec4(+sin(rads), +cos(rads), 0.f, 0.f),
					  vec4(		  0.f,		  0.f, 1.f, 0.f),
					  vec4(	      0.f,        0.f, 0.f, 1.f));
	}
};