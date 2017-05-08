#pragma once

class Camera;
class InputHandler
{
public:
	virtual void UpdateSDLEvents() = 0;
	virtual void Update(float dt) = 0;
};

class InputHandler_Camera : public InputHandler
{
public:
	InputHandler_Camera(Camera* c);

	virtual void UpdateSDLEvents() override;
	virtual void Update(float dt) override;

private:
	Camera* m_Camera;

	float m_MoveSpeed;
	float m_RotationSpeed;
	
	bool m_MoveForwardPressed;
	bool m_MoveBackwardPressed;
	bool m_RotateLeftPressed;
	bool m_RotateRightPressed;
	bool m_RotateUpPressed;
	bool m_RotateDownPressed;
};