#include "SDL.h"

#include <iostream>
#include <fstream>
#include "profilingtools/profilemanager.h"

#include "core/camera/camera.h"

#include "core/gfx/color.h"

#include "core/math/mat4x4.h"
#include "core/math/vec4.h"
#include "core/math/mathutil.h"

#include "core/geometry/sphere.h"
#include "core/geometry/plane.h"

#include "core/constants.h"

#include "window\sdl\sdlwindow.h"
using namespace std;

SDL_Window* m_window;
SDL_Renderer* m_renderer;


bool init(const char* title, int x_pos, int y_pos, int width, int height, int windowFlags, int renderFlags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		m_window = SDL_CreateWindow(title, x_pos, y_pos, width, height, windowFlags);

		if (m_window != nullptr)
		{
			m_renderer = SDL_CreateRenderer(m_window, -1, renderFlags);

			SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);

			if (m_renderer != nullptr)
			{
				SDL_RenderClear(m_renderer);

				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	return false;
}

int main(int argc, char** arvg)
{
	//Camera c;
	//c.SetPosition(vec4(35, 60, 20, 1));
	//c.SetFOV(90);
	////c.SetPitch(-80);
	//c.SetYaw(0);
	//c.InitializeCamera();

	//Sphere s (vec4(10, 0, 0, 1), 5.f);
	//Plane p(vec4(0.f, 0.f, -1.f, 0.f), 0.f);
	//Sphere light(vec4(0.f, 10.f, 100.f, 1.f), 1.f);

	//std::ofstream out("sphere.ppm");
	//out << "P3\n" << SCREEN_WIDTH << " " << SCREEN_HEIGHT << " " << "255\n";

	//Color pixColor = Color::BLACK;

	//float t = 0.f;
	//for (uint32_t y = 0; y < SCREEN_HEIGHT; ++y)
	//{
	//	for (uint32_t x = 0; x < SCREEN_WIDTH; ++x)
	//	{
	//		pixColor = Color::BLACK;
	//		Ray ray = c.GetScreenRay(x, y);
	//		if (s.IntersectsWith(ray, t))
	//		{
	//			const vec4 collisionPoint = ray.GetOrigin() + ray.GetDirection() * t;
	//			const vec4 collPointToLight = light.GetCenter() - collisionPoint;
	//			const vec4 normal = s.GetNormal(collisionPoint);

	//			const float alpha = vec4::Dot(collPointToLight.GetNormalized(), normal);
	//			pixColor = (Color::RED + Color::WHITE * alpha) * 0.5f;

	//		}

	//		if (p.IntersectsWith(ray, t))
	//		{
	//			const vec4 collisionPoint = ray.GetOrigin() + ray.GetDirection() * t;
	//			const vec4 collPointToLight = light.GetCenter() - collisionPoint;
	//			const vec4 normal = p.GetNormal(collisionPoint);

	//			const float alpha = vec4::Dot(collPointToLight.GetNormalized(), normal);
	//			pixColor = (Color::GREEN + Color::WHITE * alpha) * 0.5f;
	//		}

	//		out << (int)MathUtil::Clamp(0.f, 255.f, pixColor.GetR()) << " ";
	//		out << (int)MathUtil::Clamp(0.f, 255.f, pixColor.GetG()) << " ";
	//		out << (int)MathUtil::Clamp(0.f, 255.f, pixColor.GetB()) << " ";
	//		out << "\n";
	//	}
	//}
	/*double frameStart = 0.f;
	double frameTime = 0.f;
	float DELAY_TIME = 16.f;

	init("Welcome", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
	while (true)
	{
		Uint32 currentTimeTicks = SDL_GetTicks();

		float deltaTime = (currentTimeTicks - frameStart) * 0.001f;

		frameStart = currentTimeTicks;

		frameTime = SDL_GetTicks() - frameStart;

		if (frameTime < DELAY_TIME)
		{
			SDL_Delay((int)DELAY_TIME - frameTime);
		}
	}*/
   
    SDLWindow win;
    win.Initialize("Raytracer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT);

    while (win.IsRunning())
    {
        win.Update();
    }

	return 1;
}