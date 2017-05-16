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
    InputHandler_Camera(Camera* c) :
        m_Camera(c),
        m_MoveSpeed(50.f),
        m_RotationSpeed(5.f)
    {
        m_MoveForwardPressed  = false;
        m_MoveBackwardPressed = false;
        m_RotateLeftPressed   = false;
        m_RotateRightPressed  = false;
        m_RotateUpPressed     = false;
        m_RotateDownPressed   = false;
    }

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