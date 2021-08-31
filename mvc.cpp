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
        float x_atual;
    public:
        SystemModel(float m, float k, float b, float x0, float v0, float dt){
             this->m = m;
             this->k = k;
             this->b = b;
             this->x0 = x0;
             this->v0 = v0;
             this->dt = dt;
             x_atual = x0;
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
        float get_x_atual(){
            return this->x_atual;
        }
        void set_x_atual(float new_x){
            this->x_atual = new_x;
        }

};

//View

class SystemView{
    private:
        SystemModel &model;
    public:
        SystemView(SystemModel &model) : model(model){
        }
        void render(){
            std::cout << "Posicao: " << model.get_x_atual() << std::endl;
        }

};


//Controller

class SystemController{
    private:
        float a, f, v_atual, x_anterior;
        SystemModel &sist;
    public:
        SystemController(SystemModel &model) : sist(model){
            v_atual = sist.get_v0();

        }
        
        void calcular_forca(){
            f = -sist.get_x_atual()*sist.get_k() - sist.get_b()*v_atual;
        }
        void estimar_aceleracao(){
            a = f/sist.get_m();

        }
        void calcular_velocidade(){
            v_atual = v_atual + a * sist.get_dt();

        }
        void calcular_posicao(){  
            sist.set_x_atual(sist.get_x_atual() + v_atual * sist.get_dt());

        }

        void update(){
            calcular_forca();
            estimar_aceleracao();   
            calcular_velocidade();
            calcular_posicao();              
        }
};


///
int main(){
    SystemModel model(1, 1, 0, 1, 0, 0.1);
    SystemView view(model);
    SystemController controller(model);

    for(int i=0; i<100; i++){
        controller.update();
        view.render();
    }

    return 0;   
}