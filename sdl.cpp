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
    float m;
    float k;
    float b;
    float x0;
    float v0;
    float dt;
    float x_atual;
    float v_atual; 

  public:
    SystemModel(SDL_Renderer* renderer, SDL_Window* window, float m, float k, float b, float x0, float v0, float dt) : renderer(renderer), window(window) {

      // Carregando texturas
      // personagem
      texture = IMG_LoadTexture(renderer, "./capi.png");
      // fundo
      texture2 = IMG_LoadTexture(renderer, "./park.jpeg");

      // Quadrado onde a textura sera desenhada
      target.x = 0;
      target.y = 0;
      SDL_QueryTexture(texture, nullptr, nullptr, &target.w, &target.h);

      //setando variaveis iniciais
      this->m = m;
      this->k = k;
      this->b = b;
      this->x0 = x0;
      this->v0 = v0;
      this->dt = dt;
      x_atual = x0;
      v_atual = v0;
       
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
    float get_m(){
      return this->m;
    }
    float get_k(){
      return this->k;
    }
    float get_b(){
      return this->b;
    }
    float get_dt(){
      return this->dt;
    }
    float get_x_atual(){
      return this->x_atual;
    }
    void set_x_atual(float new_x){
      this->x_atual = new_x;
    }
    float get_v_atual(){
      return this->v_atual;
    }
    void set_v_atual(float new_v){
      this->v_atual = new_v;
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
    float a, f, x_anterior;
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
      //SDL_PumpEvents(); // atualiza estado do teclado
      //if (state[SDL_SCANCODE_LEFT]) model.set_target((-1)*1, 0);
      //if (state[SDL_SCANCODE_RIGHT]) model.set_target(1, 0);
      //if (state[SDL_SCANCODE_UP]) model.set_target(0, (-1)*1);
      //if (state[SDL_SCANCODE_DOWN]) model.set_target(0, 1);

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
      return this->rodando;
    }
    void calcular_forca(){
      f = -model.get_x_atual()*model.get_k() - model.get_b()*model.get_v_atual();
    }
    void estimar_aceleracao(){
      a = f/model.get_m();
    }
    void calcular_velocidade(){
      model.set_v_atual(model.get_v_atual() + a * model.get_dt());
    }
    void calcular_posicao(){  
      model.set_x_atual(model.get_x_atual() + model.get_v_atual() * model.get_dt());
      model.set_target(model.get_v_atual() * model.get_dt(), 0);
    }
    void update(){
      calcular_forca();
      estimar_aceleracao();   
      calcular_velocidade();
      calcular_posicao();              
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

  // Inicializando o submodelema de video do SDL
  if ( SDL_Init (SDL_INIT_VIDEO) < 0 ) {
    std::cout << SDL_GetError();
    return 1;
  }


  SystemModel model = SystemModel(renderer, window, 1, 1, 0, 1, 0, 0.1);
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
