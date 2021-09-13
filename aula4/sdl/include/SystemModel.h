#ifndef _SystemModel_
#define _SystemModel_

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
        SystemModel(float m, float k, float b, float y0, float v0, float dt);
        float get_m();
        float get_k();
        float get_b();
        float get_y0();
        float get_v0();
        float get_dt();
        float get_y_atual();
        void set_y_atual(float y);
        float get_v_atual();
        void set_v_atual(float v);
};

#endif