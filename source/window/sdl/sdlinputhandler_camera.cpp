#include "window/sdl/sdlinputhandler_camera.h"
#include "core/camera/camera.h"
#include <SDL.h>

void InputHandler_Camera::UpdateSDLEvents()
{
    SDL_Event event;
    switch (SDL_PollEvent(&event))
    {
        case SDL_KEYDOWN:
        {
                            switch (event.key.keysym.sym)
                            {
                            case SDLK_w: { m_MoveForwardPressed = true; break; }
                            case SDLK_s: { m_MoveBackwardPressed = true; break; }
                            case SDLK_a: { m_RotateLeftPressed = true; break; }
                            case SDLK_d: { m_RotateRightPressed = true; break; }
                            case SDLK_q: { m_RotateUpPressed = true; break; }
                            case SDLK_e: { m_RotateDownPressed = true; break; }
                            }
        }break;
        case SDL_KEYUP:
        {
                          switch (event.key.keysym.sym)
                          {
                          case SDLK_w: { m_MoveForwardPressed  = false; break; }
                          case SDLK_s: { m_MoveBackwardPressed = false; break; }
                          case SDLK_a: { m_RotateLeftPressed   = false; break; }
                          case SDLK_d: { m_RotateRightPressed  = false; break; }
                          case SDLK_q: { m_RotateUpPressed     = false; break; }
                          case SDLK_e: { m_RotateDownPressed   = false; break; }
                          }
        }break;
    }
}

void InputHandler_Camera::Update(float dt)
{
    UpdateSDLEvents();

    vec4 sight = m_Camera->GetSight();
    vec4 newPos = m_Camera->GetPosition() + sight * m_MoveSpeed * dt * m_MoveForwardPressed 
                                          + sight * -1 * m_MoveSpeed * dt * m_MoveBackwardPressed;
    m_Camera->SetPosition(newPos);


    float newYaw = m_RotationSpeed * dt * m_RotateLeftPressed + -m_RotationSpeed * dt * m_RotateRightPressed;

    m_Camera->AddYaw(newYaw);

    float newPitch = m_RotationSpeed * dt * m_RotateUpPressed + -m_RotationSpeed * dt * m_RotateDownPressed;

    m_Camera->AddPitch(newPitch);

}






