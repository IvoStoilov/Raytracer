#include "raytracingrenderer.h"
#include "world.h"

#include "core/gfx/color.h"
#include "core/gfx/shaders/baseshader.h"

#include "core/math/mat4x4.h"
#include "core/math/vec4.h"
#include "core/math/mathutil.h"

#include "core/constants.h"

#include "core/camera/camera.h"
#include "core/geometry/geometry.h"

void RaytracingRenderer::Render()
{
    std::vector<Object*>& worldObjects = m_World->GetObjects();
    Camera* camera = m_World->GetCamera();
   
    for (uint32_t y = 0; y < SCREEN_HEIGHT; ++y)
    {
        for (uint32_t x = 0; x < SCREEN_WIDTH; ++x)
        {
            Object* closestObject = nullptr;
            IntersectionInfo closestInfo;
            float minDistance = INF;
            
            for (Object* obj : worldObjects)
            {
                Ray ray = camera->GetScreenRay(x, y);
                IntersectionInfo info;
                if (!obj->GetGeometry()->IntersectsWith(ray, info))
                    continue;

                if (popLesserWithEpsilon(info.m_Distance, minDistance))
                {
                    minDistance = info.m_Distance;
                    closestObject = obj;
                    closestInfo = info;
                }
            }

            Color pixColor;
            if (closestObject == nullptr)
                pixColor = Color(0.f, 0.f, 0.f, 0.f); // TODO : background
            else
                pixColor = closestObject->GetShader()->Shade(closestInfo);

            uint32_t colorHex = pixColor.ToARGBHex();
            m_FrameBuffer[y * SCREEN_WIDTH + x] = colorHex;
        }
    }
}
