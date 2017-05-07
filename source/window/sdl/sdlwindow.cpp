#include <stdio.h>

#include "window/sdl/sdlwindow.h"

//Uint32 rmask = 0xff000000;
//Uint32 gmask = 0x00ff0000;
//Uint32 bmask = 0x0000ff00;
//Uint32 amask = 0x000000ff;

SDLWindow::SDLWindow() :
    m_Running(true),
    m_Screen(nullptr),
    m_Window(nullptr)
{
}

bool SDLWindow::Initialize(const char* title, int x_pos, int y_pos, int width, int height)
{
    m_Width = width;
    m_Height = height;

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

    m_Screen = SDL_GetWindowSurface(m_Window);
    //pixel masks :
    //0xff000000 - alpha
    //0x00ff0000 - r
    //0x0000ff00 - g
    //0x000000ff - b

    if (m_Screen == nullptr)
    {
        printf("Unable to create SDL_Screen: %s\n", SDL_GetError());
        return false;
    }

    m_FrameBuffer = (uint32_t*)malloc(m_Width * m_Height * sizeof(uint32_t));

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

   SDL_memcpy(m_Screen->pixels, m_FrameBuffer, m_Width * m_Height * sizeof(uint32_t));
   SDL_UpdateWindowSurface(m_Window);
}

SDLWindow::~SDLWindow()
{
    free(m_FrameBuffer);
    SDL_VideoQuit();
    SDL_DestroyWindow(m_Window);
    SDL_Quit();
}