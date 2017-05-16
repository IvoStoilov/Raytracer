#include "SDL.h"

#include <iostream>
#include <fstream>

#include "profilingtools/profilemanager.h"

#include "core/camera/camera.h"

#include "core/gfx/color.h"
#include "core/gfx/shaders/checkershader.h"
#include "core/gfx/shaders/baseshader.h"

#include "core/geometry/sphere.h"
#include "core/geometry/plane.h"

#include "core/constants.h"

#include "window/sdl/sdlwindow.h"
#include "window/sdl/sdlinputhandler_camera.h"
#include "raytracingrenderer.h"
#include "world.h"

using namespace std;


int main(int argc, char** argv)
{
    Object objSphere;
    Sphere s (vec4(10, 10, 10, 1), 1.f);
    Shader baseShader;
    objSphere.SetGeometry(&s);
    objSphere.SetShader(&baseShader);

    Object objPlane;
    Plane p(vec4(0.f, 0.f, 1.f, 0.f), 0);
    CheckerShader cs_shader(Color(1.f, 1.f, 0.f, 0.f), Color(0.f, 0.f, 1.f, 0.f));
    objPlane.SetGeometry(&p);
    objPlane.SetShader(&cs_shader);

    Sphere light(vec4(0.f, 10.f, 100.f, 1.f), 1.f);

    World world;
    world.InitWorld();
    world.AddObject(&objPlane);
    world.AddObject(&objSphere);
    
    InputHandler_Camera input(world.GetCamera());

    SDLWindow win;
    win.Initialize("Raytracer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT);

    RaytracingRenderer renderer;
    renderer.SetFrameBuffer(win.GetFrameBuffer());
    renderer.SetWorld(&world);

    double frameStart = 0.f;
    double frameTime = 0.f;

    while (win.IsRunning())
    {
        Uint32 currentTimeTicks = SDL_GetTicks();

        float dt = (currentTimeTicks - frameStart) * 0.001f;

        frameStart = currentTimeTicks;

        input.Update(dt);
        
        renderer.Render();

        win.Update();

        frameTime = SDL_GetTicks() - frameStart;

        printf("Frame time : %.2f ms.\n", frameTime);

        if (frameTime < MS_PER_FRAME)
        {
            SDL_Delay((int)MS_PER_FRAME - frameTime);
        }
    }
    
    return 0;
}