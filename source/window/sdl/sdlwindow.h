#pragma once

#include "SDL.h"

class SDLWindow
{
public:
    SDLWindow();
    ~SDLWindow();

    bool Initialize(const char* title, int x_pos, int y_pos, int width, int height);
    void Update();

    inline bool IsRunning() const { return m_Running; }

private:
    bool m_Running;

    SDL_Surface* m_Screen;
    SDL_Window* m_Window;
};