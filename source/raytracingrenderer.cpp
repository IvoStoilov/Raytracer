#include "raytracingrenderer.h"
#include "world.h"

#include "core/gfx/color.h"

#include "core/math/mat4x4.h"
#include "core/math/vec4.h"
#include "core/math/mathutil.h"

#include "core/geometry/sphere.h"
#include "core/geometry/plane.h"

#include "core/constants.h"

#include "core/camera/camera.h"

#include <vector>

void RaytracingRenderer::Render()
{
    std::vector<Shape*>& worldObjects = m_World->GetObjects();
    Camera* camera = m_World->GetCamera();

    Color pixColor = Color::BLACK;

    float t = 0.f;
   
    for (uint32_t y = 0; y < SCREEN_HEIGHT; ++y)
    {
        for (uint32_t x = 0; x < SCREEN_WIDTH; ++x)
        {
            pixColor = Color(0.f, 0.f, 0.f, 0.f);
            float tMin = 1000000000.f;
            for (Shape* obj : worldObjects)
            {
                Ray ray = camera->GetScreenRay(x, y);

                if (obj->IntersectsWith(ray, t) && t < tMin)
                {
                    const vec4 collisionPoint = ray.GetOrigin() + ray.GetDirection() * t;
                    //const vec4 collPointToLight = light.GetCenter() - collisionPoint;
                    //const vec4 normal = s.GetNormal(collisionPoint);

                    //const float alpha = vec4::Dot(collPointToLight.GetNormalized(), normal);
                    pixColor = obj->GetColor();

                    tMin = t;
                }
            }

            uint32_t colorHex = pixColor.ToARGBHex();
            m_FrameBuffer[y * SCREEN_WIDTH + x] = colorHex;
        }
    }
}
