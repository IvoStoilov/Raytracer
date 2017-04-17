#pragma once

#include "core/math/vec4.h"

class Camera
{
public:
	void InitializeCamera();

	inline void SetYaw(const float degree)  { m_Yaw = degree; }
	inline void SetPitch(const float degree){ m_Pitch = degree; }
	inline void SetRoll(const float degree) { m_Pitch = degree; }
	inline void SetFOV(const float degree)  { m_FOV = degree; }
	inline void SetAspectRation(const float value) { m_AspectRatio = value; }

	//In degrees
	inline float GetYaw()	const { return m_Yaw; }
	//In degrees
	inline float GetPitch() const { return m_Pitch; }
	//In degrees
	inline float GetRoll()	const { return m_Roll; }
private:
	vec4 m_TopRight;
	vec4 m_TopLeft;
	vec4 m_BottomRight;

	vec4 m_Position;

// TODO : istoilov - Move to seperate Data class after implementing serealizing
	float m_Yaw;	// Stored in Degreese
	float m_Pitch;	// Stored in Degreese
	float m_Roll;	// Stored in Degreese
	float m_FOV;    // Stored in Degreese
	float m_AspectRatio;
};