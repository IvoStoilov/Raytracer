#pragma once
#include <vector>
#include "core/geometry/geometry.h"

class Camera;
class World
{
public:
    ~World();

    void InitWorld();

    inline void AddObject(Object* obj) { m_Objects.push_back(obj); }
    inline std::vector<Object*>& GetObjects() { return m_Objects; }
    inline Camera* GetCamera() { return m_Camera; }

private:
    std::vector<Object*> m_Objects;
    Camera* m_Camera;
};