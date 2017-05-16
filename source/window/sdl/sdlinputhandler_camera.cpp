#include "window/sdl/sdlinputhandler_camera.h"
#include "core/camera/camera.h"
#include "core/math/vec4.h"
#include <SDL.h>

void InputHandler_Camera::UpdateSDLEvents()
{
    const Uint8* state = SDL_GetKeyboardState(nullptr);

    m_MoveForwardPressed = (bool)state[SDL_SCANCODE_W];
    m_MoveBackwardPressed = (bool)state[SDL_SCANCODE_S];
    m_RotateLeftPressed = (bool)state[SDL_SCANCODE_A];
    m_RotateRightPressed = (bool)state[SDL_SCANCODE_D];
    m_RotateUpPressed = (bool)state[SDL_SCANCODE_Q];
    m_RotateDownPressed = (bool)state[SDL_SCANCODE_E];
}


void InputHandler_Camera::Update(float dt)
{
    UpdateSDLEvents();

    vec4 sight = m_Camera->GetSight();
    vec4 newPos = m_Camera->GetPosition() + sight * m_MoveSpeed * dt * m_MoveForwardPressed
        + sight * -1 * m_MoveSpeed * dt * m_MoveBackwardPressed;
    m_Camera->SetPosition(newPos);

    float newPitch = m_RotationSpeed * dt * m_RotateUpPressed + -m_RotationSpeed * dt * m_RotateDownPressed;

    m_Camera->RotatePitch(newPitch);

    float newYaw = m_RotationSpeed * dt * m_RotateLeftPressed + -m_RotationSpeed * dt * m_RotateRightPressed;

    m_Camera->RotateYaw(newYaw);

    m_Camera->GetPosition().Print();
    printf("Pitch : %.2f\nYaw : %.2f\nRoll : %.2f\n", m_Camera->GetPitch(), m_Camera->GetYaw(), m_Camera->GetRoll());

}






