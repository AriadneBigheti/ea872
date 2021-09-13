#include "SystemModel.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#ifndef _SystemController_
#define _SystemController_
class SystemController {

    private:
      float a, f;
      SystemModel &model;
      bool rodando;
      // Variaveis para verificar eventos
      SDL_Event evento; // eventos discretos
      const Uint8* state;  // estado do teclado

    public:
      SystemController(SystemModel &model);
      void polling();  
      bool get_rodando();
      void calcular_forca();
      void estimar_aceleracao();
      void calcular_velocidade();
      void calcular_posicao();
      void update();
};
#endif
