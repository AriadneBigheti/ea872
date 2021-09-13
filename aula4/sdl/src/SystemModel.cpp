#include "SystemModel.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

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

}

