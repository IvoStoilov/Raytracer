#pragma once
#include <stdint.h>

class World;
class RaytracingRenderer
{
public:
    inline void SetFrameBuffer(uint32_t* frameBuffer) { m_FrameBuffer = frameBuffer; }
    inline void SetWorld(World* world) { m_World = world; }
    void Render();

private:
    uint32_t* m_FrameBuffer;
    World*    m_World;
};