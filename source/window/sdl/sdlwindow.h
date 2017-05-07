#pragma once

#include "SDL.h"

class SDLWindow
{
public:
    SDLWindow();
    ~SDLWindow();

    bool Initialize(const char* title, int x_pos, int y_pos, int width, int height);
    void Update();

    inline uint32_t* GetFrameBuffer() const { return m_FrameBuffer; }
    inline bool IsRunning() const { return m_Running; }

private:
    bool m_Running;

    uint32_t m_Width;
    uint32_t m_Height;

    uint32_t* m_FrameBuffer;
    SDL_Surface* m_Screen;
    SDL_Window* m_Window;
};