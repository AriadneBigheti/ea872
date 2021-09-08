
#include <memory>
#include <iostream>

//Model

class SystemModel{
    private:
        float m;
        float k;
        float b;
        float x0;
        float v0;
        float dt;
    public:
        SystemModel(float m, float k, float b, float x0, float v0, float dt){
             this->m = m;
             this->k = k;
             this->b = b;
             this->x0 = x0;
             this->v0 = v0;
             this->dt = dt;
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
        float get_x0(){
            return this->x0;
        }
        float get_v0(){
            return this->v0;
        }
        float get_dt(){
            return this->dt;
        }

};

//View

class SystemView{


}


//Controller

class SystemController{
    private:
        float a, f, x_atual, v_atual, x_anterior;
        Sistema sist;
    public:
        SystemController(Sistema sist){
            this->sist = sist;
            x_atual = sist.get_x0();
            v_atual = sist.get_v0();

        }
        
        void calcular_forca(){
            f = -x_atual*sist.get_k() - sist.get_b()*v_atual;
        }
        void estimar_aceleracao(){
            a = f/sist.get_m();

        }
        void calcular_velocidade(){
            v_atual = v_atual + a * sist.get_dt();

        }
        void calcular_posicao(){  
            x_atual = x_atual + v_atual * sist.get_dt();

        }

        void imprimir_posicoes(){
            for(int i=0; i<100; i++)
            {
                calcular_forca();
                estimar_aceleracao();   
                calcular_velocidade();
                calcular_posicao();

                std::cout << "Posicao: " << x_atual << std::endl;
            }
        }
};


///
 class Main{

    std::unique_ptr<sist> sist (SystemModel(1, 1, 0, 1, 0, 0.1));
    std::unique_ptr<Equacoes> equacoes (SystemController(sist));

}