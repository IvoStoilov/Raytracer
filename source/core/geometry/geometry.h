#pragma once
#include "core/gfx/color.h"
#include "core/camera/ray.h"
#include <string.h>

struct IntersectionInfo
{
    vec4 m_IntersectionPoint;
    vec4 m_Normal;
    float m_Distance;
    float m_U;
    float m_V;

    inline void operator= (IntersectionInfo& other) { memcpy(this, &other, sizeof(IntersectionInfo)); }
};

class Shader;
class Texture;
class Geometry;
class Object
{
public:
    inline void SetGeometry (Geometry *value) { m_Geometry = value; }
    inline void SetShader   (Shader *value)   { m_Shader = value; }
    inline void SetTexture  (Texture *value)  { m_Texture = value; }

    inline Geometry* GetGeometry() const { return m_Geometry; }
    inline Shader* GetShader() const { return m_Shader; }
    inline Texture* GetTexture() const { return m_Texture; }
private:
    Geometry* m_Geometry;
    Shader*   m_Shader;
    Texture*  m_Texture;
};

class Geometry
{
public:
   virtual bool IntersectsWith(const Ray& ray, IntersectionInfo& outInfo) = 0;
   virtual vec4 GetNormal(const vec4& collisionPoint) = 0;
};