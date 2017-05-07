#pragma once
#include <vector>
#include <core/geometry/shape.h>

class Camera;
class World
{
public:
    ~World();

    void InitWorld();

    inline void AddObject(Shape* shape) { m_Objects.push_back(shape); }
    inline std::vector<Shape*>& GetObjects() { return m_Objects; }
    inline Camera* GetCamera() { return m_Camera; }

private:
    std::vector<Shape*> m_Objects;
    Camera* m_Camera;
};