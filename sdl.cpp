#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Model
class SystemModel{
  private:
    SDL_Renderer* renderer;
    SDL_Window* window;
    SDL_Texture *texture;
    SDL_Texture *texture2;
    SDL_Rect target;
    
  public:
    SystemModel(SDL_Renderer* renderer, SDL_Window* window) : renderer(renderer), window(window) {

      // Carregando texturas
      // personagem
      texture = IMG_LoadTexture(renderer, "./capi.png");
      // fundo
      texture2 = IMG_LoadTexture(renderer, "./park.jpeg");

      // Quadrado onde a textura sera desenhada
      target.x = 0;
      target.y = 0;
      SDL_QueryTexture(texture, nullptr, nullptr, &target.w, &target.h);
          
    }
   
    SDL_Renderer* get_renderer(){
      return this->renderer;
    }
    SDL_Window* get_window(){
      return this->window;
    }
    SDL_Texture* get_texture(){
      return this->texture;
    }
    SDL_Texture* get_texture2(){
      return this->texture2;
    }
    SDL_Rect* get_target(){
      return &this->target;
    }
    void set_target(int x, int y){
      this->target.x += x;
      this->target.y += y;
    }


};

//View
class SystemView{
  private:
  SystemModel &model;
  public:
    SystemView(SystemModel &model) : model(model){
    }

    void renderizar(){
        // Desenhar a cena
      SDL_RenderClear(model.get_renderer());
      SDL_RenderCopy(model.get_renderer(), model.get_texture2(), nullptr, nullptr);
      SDL_RenderCopy(model.get_renderer(), model.get_texture(), nullptr, (model).get_target());
      SDL_RenderPresent(model.get_renderer());

      // Delay para diminuir o framerate
      SDL_Delay(10);
    }
    void destruir(){
      SDL_DestroyTexture(model.get_texture());
      SDL_DestroyRenderer(model.get_renderer());
      SDL_DestroyWindow(model.get_window());
      SDL_Quit();
    }
};




//Controller
class SystemController{
  private:
    bool rodando;
    // Variaveis para verificar eventos
    SDL_Event evento; // eventos discretos
    const Uint8* state;  // estado do teclado

  SystemModel &model;
  
  public:
  // Polling de eventos

    SystemController(SystemModel &model) : model(model){
        this->rodando = true;
        this->state = SDL_GetKeyboardState(nullptr);
    }

    void polling(){
      SDL_PumpEvents(); // atualiza estado do teclado
      if (state[SDL_SCANCODE_LEFT]) model.set_target((-1)*1, 0);
      if (state[SDL_SCANCODE_RIGHT]) model.set_target(1, 0);
      if (state[SDL_SCANCODE_UP]) model.set_target(0, (-1)*1);
      if (state[SDL_SCANCODE_DOWN]) model.set_target(0, 1);


      while (SDL_PollEvent(&evento)) {
        if (evento.type == SDL_QUIT) {
          this->rodando = false;
        }
        // Exemplos de outros eventos.
        // Que outros eventos poderiamos ter e que sao uteis?
        //if (evento.type == SDL_KEYDOWN) {
        //}
        //if (evento.type == SDL_MOUSEBUTTONDOWN) {
        //}
      }
    }  
    bool get_rodando(){
      return get_rodando();
    }
    
};

int main() {
  SDL_Renderer* renderer;
  SDL_Window* window;

  // Criando uma janela
  window = nullptr;
  window = SDL_CreateWindow("Demonstracao do SDL2",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    SDL_WINDOW_SHOWN);
  if (window==nullptr) { // Em caso de erro...
    std::cout << SDL_GetError();
    SDL_Quit();
    return 1;
  }
    // Inicializando o renderizador
  renderer = SDL_CreateRenderer(
    window, -1,
    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (renderer==nullptr) { // Em caso de erro...
    SDL_DestroyWindow(window);
    std::cout << SDL_GetError();
    SDL_Quit();
    return 1;
  }

  // Inicializando o subsistema de video do SDL
  if ( SDL_Init (SDL_INIT_VIDEO) < 0 ) {
    std::cout << SDL_GetError();
    return 1;
  }


  SystemModel model = SystemModel(renderer, window);
  SystemView view = SystemView(model);
  SystemController controller = SystemController(model);


  // Laco principal do jogo
  while(controller.get_rodando()) {
    controller.polling();
    view.renderizar();
  }

  view.destruir();
  
  return 0;
}
