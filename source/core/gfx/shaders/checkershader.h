#pragma once
#include "core/gfx/shaders/baseshader.h"

class IntersectionInfo;
class CheckerShader : public Shader
{
public:
    CheckerShader() {};
    CheckerShader(Color& c1, Color& c2) :
        m_Color1(c1),
        m_Color2(c2)
    {}

    inline void SetColor1(Color& color) { m_Color1 = color;}
    inline void SetColor2(Color& color) { m_Color2 = color;}

    virtual Color Shade(IntersectionInfo& info) override;

private:
    Color m_Color1;
    Color m_Color2;
};