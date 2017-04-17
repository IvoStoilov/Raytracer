#pragma once
#include "core/camera/camera.h"
#include "core/math/mathutil.h"

void Camera::InitializeCamera()
{
	float x2d = -m_AspectRatio;
	float y2d = +1;

	float wantedAngle = MathUtil::ToRads(m_FOV / 2.f);
	float wantedLength = tan(wantedAngle);
	float currentLengthSqr = MathUtil::Sqr(m_AspectRatio) + MathUtil::Sqr(1.f);


}