#include "SystemView.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

using namespace std;

const int SCREEN_WIDTH = 840;
const int SCREEN_HEIGHT = 680;

//View
class SystemView{
  private:
  SystemModel &model;
  SDL_Renderer* renderer;
  SDL_Window* window;    
  SDL_Rect target;
  SDL_Texture *texture;
  SDL_Texture *texture2;

  public:
    SystemView(SystemModel &model) : model(model){

      // Inicializando o submodelema de video do SDL
      if ( SDL_Init (SDL_INIT_VIDEO) < 0 ) {
        std::cout << SDL_GetError();
      }

      // Criando uma janela
      this->window = nullptr;
      this->window = SDL_CreateWindow("Demonstracao do SDL2",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN);
      if (window==nullptr) { // Em caso de erro...
        std::cout << SDL_GetError();
        SDL_Quit();
      }


      // Inicializando o renderizador
      this->renderer = SDL_CreateRenderer(
        this->window, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
      if (renderer==nullptr) { // Em caso de erro...
          SDL_DestroyWindow(window);
          std::cout << SDL_GetError();
          SDL_Quit();
        }


      // Carregando texturas
      // personagem
      this->texture = IMG_LoadTexture(this->renderer, "../assets/spaceship1.png");
      // fundo
      this->texture2 = IMG_LoadTexture(this->renderer, "../assets/purplegalaxy.jpg");

      // Quadrado onde a textura sera desenhada
      target.y = model.get_y0();
      target.x = SCREEN_WIDTH/2 - 50;
      SDL_QueryTexture(texture, nullptr, nullptr, &target.w,  &target.h);

   }

    void renderizar(){
        // Desenhar a cena
      target.y = model.get_y_atual()*50;
      SDL_RenderClear(renderer);
      SDL_RenderCopy(renderer, texture2, nullptr, nullptr);
      SDL_RenderCopy(renderer, texture, nullptr, &target);
      SDL_RenderPresent(renderer);

      // Delay para diminuir o framerate
      SDL_Delay(10);
    }
    void destruir(){
      SDL_DestroyTexture(texture);
      SDL_DestroyRenderer(renderer);
      SDL_DestroyWindow(window);
      SDL_Quit();
    }
}