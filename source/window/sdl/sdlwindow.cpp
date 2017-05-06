#include <stdio.h>

#include "window/sdl/sdlwindow.h"

Uint32 rmask = 0xff000000;
Uint32 gmask = 0x00ff0000;
Uint32 bmask = 0x0000ff00;
Uint32 amask = 0x000000ff;

SDLWindow::SDLWindow() :
    m_Running(true),
    m_Screen(nullptr),
    m_Window(nullptr)
{
}

bool SDLWindow::Initialize(const char* title, int x_pos, int y_pos, int width, int height)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Unable to init SDL : %s\n", SDL_GetError());
        return false;

    }
    m_Window = SDL_CreateWindow(title, x_pos, y_pos, width, height, 0);

    if (m_Window == nullptr)
    {
        printf("Unable to create SDL_Window: %s\n", SDL_GetError());
        return false;
    }

    m_Screen = SDL_CreateRGBSurface(0, width, height, 32, rmask, gmask, bmask, amask);

    if (m_Screen == nullptr)
    {
        printf("Unable to create SDL_Screen: %s\n", SDL_GetError());
        return false;
    }

    return true;
}

void SDLWindow::Update()
{
   SDL_Event event;
   while (SDL_PollEvent(&event))
   {
      switch (event.type)
      {
         case SDL_QUIT:
         {
            m_Running = false;
         }break;

         case SDL_KEYDOWN:
         {
            if (event.key.keysym.sym == SDLK_ESCAPE)
                m_Running = false;
         }break;
      }
   }
}

SDLWindow::~SDLWindow()
{
    SDL_DestroyWindow(m_Window);
    SDL_Quit();
}