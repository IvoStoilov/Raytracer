#pragma once
#include "core/gfx/color.h"
#include "core/geometry/geometry.h"

class Shader
{
public:
    virtual Color Shade(IntersectionInfo& info) { return Color(1.f, 0.f, 1.f); };
};