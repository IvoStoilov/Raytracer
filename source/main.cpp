#include <iostream>
#include <fstream>

#include "core/camera/camera.h"

#include "core/gfx/color.h"

#include "core/math/vec4.h"
#include "core/math/mathutil.h"

#include "core/geometry/sphere.h"

using namespace std;

const uint32_t SCREEN_WIDTH = 512;
const uint32_t SCREEN_HEIGHT = 512;

int main()
{
	Camera c;
	Sphere s (vec4(0.5f * SCREEN_WIDTH, 0.5f * SCREEN_HEIGHT, 50, 1.f), 50.f);
	Sphere light(vec4(0.f, 256.f, 50.f, 1.f), 1.f);

	std::ofstream out("sphere.ppm");
	out << "P3\n" << SCREEN_WIDTH << " " << SCREEN_HEIGHT << " " << "255\n";

	Color pixColor = Color::BLACK;

	float t = 0.f;
	for (uint32_t x = 0; x < SCREEN_HEIGHT; ++x)
	{
		for (uint32_t y = 0; y < SCREEN_WIDTH; ++y)
		{
			pixColor = Color::BLACK;
			const Ray ray(vec4(x, y, 0, 1), vec4(0, 0, 1, 0));
			if (s.IntersectsWith(ray, t))
			{
				const vec4 collisionPoint = ray.GetPoint() + ray.GetDirection() * t;
				const vec4 collPointToLight = light.GetCenter() - collisionPoint;
				const vec4 normal = s.GetNormal(collisionPoint);

				const float alpha = vec4::Dot(collPointToLight.Normalize(), normal);
				pixColor = (Color::RED + Color::WHITE * alpha) * 0.5f;

			}

			out << (int)MathUtil::Clamp(0.f, 255.f, pixColor.GetR()) << " ";
			out << (int)MathUtil::Clamp(0.f, 255.f, pixColor.GetG()) << " ";
			out << (int)MathUtil::Clamp(0.f, 255.f, pixColor.GetB()) << " ";
			out << "\n";
		}
	}

	int a = 0;

	system("pause");
}