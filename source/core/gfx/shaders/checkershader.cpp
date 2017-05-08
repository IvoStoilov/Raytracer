#include "core/gfx/shaders/checkershader.h"
#include "core/geometry/geometry.h"

Color CheckerShader::Shade(IntersectionInfo& info)
{
    int x = (int)floor(info.m_U / 5.f);
    int y = (int)floor(info.m_V / 5.f);

    if ((x + y) % 2 == 0)
        return m_Color1;
    else
        return m_Color2;
}