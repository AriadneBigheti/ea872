#include "SystemController.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>


//Controller
class SystemController{
  private:
    float a, f;
    SystemModel &model;
    bool rodando;
    // Variaveis para verificar eventos
    SDL_Event evento; // eventos discretos
    const Uint8* state;  // estado do teclado

  
  public:
  // Polling de eventos

    SystemController(SystemModel &model) : model(model){
        this->rodando = true;
        this->state = SDL_GetKeyboardState(nullptr);
        f = 0;
        a = 0;

    }

    void polling(){
      //SDL_PumpEvents(); // atualiza estado do teclado
      //if (state[SDL_SCANCODE_LEFT]) model.set_target((-1)*1, 0);
      //if (state[SDL_SCANCODE_RIGHT]) model.set_target(1, 0);
      //if (state[SDL_SCANCODE_UP]) model.set_target(0, (-1)*1);
      //if (state[SDL_SCANCODE_DOWN]) model.set_target(0, 1);


      while (SDL_PollEvent(&evento)) {
        if (evento.type == SDL_QUIT) {
          this->rodando = false;
        }
        // Exemlos de outros eventos.
        // Que outros eventos poderiamos ter e que sao uteis?
        //if (evento.type == SDL_KEYDOWN) {
        //}
        //if (evento.type == SDL_MOUSEBUTTONDOWN) {
        ///}
      }
    }  
    bool get_rodando(){
      return this->rodando;
    }

        void calcular_forca(){
            f = -model.get_y_atual()*model.get_k() - model.get_b()*model.get_v_atual();
        }
        void estimar_aceleracao(){
            a = f/model.get_m();

        }
        void calcular_velocidade(){
            model.set_v_atual( a * model.get_dt());

        }
        void calcular_posicao(){  
            model.set_y_atual(model.get_v_atual() * model.get_dt());

        }

        void update(){
            calcular_forca();
            estimar_aceleracao();   
            calcular_velocidade();
            calcular_posicao();              
        }    
    
}
