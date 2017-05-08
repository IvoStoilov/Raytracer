#pragma once
#include "core/camera/camera.h"

#include "core/math/mathutil.h"
#include "core/math/mat4x4.h"

#include "core/constants.h"

void Camera::InitializeCamera()
{
   float x2d = -m_AspectRatio;
   float y2d = +1;

   float wantedAngle = MathUtil::ToRads(m_FOV / 2.f);
   float wantedLength = tan(wantedAngle);
   float currentLength = sqrt(MathUtil::Sqr(m_AspectRatio) + MathUtil::Sqr(1.f));
   
   float ratio = wantedLength / currentLength;

   m_TopLeft	  = vec4(+ratio * x2d, +ratio * y2d, 1.f, 0.f);
   m_TopRight	  = vec4(-ratio * x2d, +ratio * y2d, 1.f, 0.f);
   m_BottomRight = vec4(-ratio * x2d, -ratio * y2d, 1.f, 0.f);

   mat4x4 rotation = mat4x4::GetRotateXAxisMatrix(MathUtil::ToRads(m_Pitch))*
                 mat4x4::GetRotateYAxisMatrix(MathUtil::ToRads(m_Yaw  ))*
                 mat4x4::GetRotateZAxisMatrix(MathUtil::ToRads(m_Roll ));

   m_TopLeft     *= rotation;
   m_TopRight    *= rotation;
   m_BottomRight *= rotation;

   m_TopLeft	  += m_Position;
   m_TopRight	  += m_Position;
   m_BottomRight += m_Position;
}

Ray Camera::GetScreenRay(uint32_t x, uint32_t y)
{
    vec4 throughPoint = m_TopLeft + (m_TopRight - m_TopLeft) * ((float)x / SCREEN_WIDTH)
                                  + (m_BottomRight - m_TopRight) * ((float)y / SCREEN_HEIGHT);

    vec4 rayDirection = throughPoint - m_Position;
   rayDirection.Normalize();

   return Ray(m_Position, rayDirection);
}

vec4 Camera::GetSight() const
{
    //TODO (istoilov) : Fix this after Transform is implemented
    vec4 middle = m_TopLeft + (m_TopRight - m_TopLeft) * (0.5f / SCREEN_WIDTH)
        + (m_BottomRight - m_TopRight) * (0.5f / SCREEN_HEIGHT);

    return (middle - m_Position).GetNormalized();
}

Camera::Camera() :
   m_Position(vec4(0.f, 0.f, 0.f, 1.f)),
   m_Pitch(0.f),
   m_Yaw(0.f),
   m_Roll(0.f),
   m_FOV(45.f),
   m_AspectRatio(1.777f)
{}