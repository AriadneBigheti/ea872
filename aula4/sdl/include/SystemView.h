#include "SystemModel.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


#ifndef _SystemView_
#define _SystemView_

class SystemView{
  private:
  SystemModel &model;
  SDL_Renderer* renderer;
  SDL_Window* window;    
  SDL_Rect target;
  SDL_Texture *texture;
  SDL_Texture *texture2;

  public:
    SystemView(SystemModel &model);
    void renderizar();
    void destruir();
};

#endif