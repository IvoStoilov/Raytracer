#include "world.h"
#include "core/camera/camera.h"

#include "core/geometry/sphere.h";
#include "core/geometry/plane.h";

#include "core/constants.h"

void World::InitWorld()
{
    m_Camera = new Camera();
    m_Camera->SetAspectRation(ASPECT_RATIO);
    m_Camera->SetPosition(vec4(0, 0, 10, 1));
    m_Camera->SetFOV(90);
    m_Camera->SetPitch(-90);
    m_Camera->SetYaw(120);
    m_Camera->InitCamera();
    m_Camera->FrameBegin();
}

World::~World()
{
    delete m_Camera;
}