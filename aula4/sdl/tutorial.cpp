#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

const int SCREEN_WIDTH = 840;
const int SCREEN_HEIGHT = 680;

//Model
class SystemModel{
    private:
        float m;
        float k;
        float b;
        float y0;
        float v0;
        float dt;
        float y_atual;
        float v_atual;
    public:
        SystemModel(float m, float k, float b, float y0, float v0, float dt){
             this->m = m;
             this->k = k;
             this->b = b;
             this->y0 = y0;
             this->v0 = v0;
             this->dt = dt;
             y_atual = y0;
             v_atual = v0;
        }
        float get_m(){
            return this->m;
        }
        float get_k(){
            return this->k;
        }
        float get_b(){
            return this->b;
        }
        float get_y0(){
            return this->y0;
        }
        float get_v0(){
            return this->v0;
        }
        float get_dt(){
            return this->dt;
        }
        float get_y_atual(){
            return this->y_atual;
        }
        void set_y_atual(float y){
            this->y_atual += y;
        }
        float get_v_atual(){
          return this->v_atual;
        }
        void set_v_atual(float v){
          this->v_atual += v;
        }

};


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
      this->texture = IMG_LoadTexture(this->renderer, "./spaceship1.png");
      // fundo
      this->texture2 = IMG_LoadTexture(this->renderer, "./purplegalaxy.jpg");

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
};




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
    
};

int main() {
  
  SystemModel model = SystemModel(1, 1, 0, -7, -1, 0.05);
  SystemView view = SystemView(model);
  SystemController controller = SystemController(model);


  // Laco principal do jogo
  while(controller.get_rodando()) {
    controller.polling();
    controller.update();
    view.renderizar();
  }

  view.destruir();
  
  return 0;
}