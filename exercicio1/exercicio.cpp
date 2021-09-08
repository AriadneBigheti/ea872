#include <iostream>
#include <memory>

class Coord{
    private:
        int x,y;
   
    public:
        void new_coordinates(int new_x, int new_y);
};

void Coord::new_coordinates ( int new_x, int new_y){
    x = new_x;
    y = new_y;
}

class Cube{

    private:
        int x,y,z;
    
    public:
        void new_coordinates (int new_x, int new_y, int new_z);
    
        void print_volume();
};


void Cube::new_coordinates (int new_x, int new_y, int new_z){
    x = new_x;
    y = new_y;
    z = new_z;
}

void Cube::print_volume(){
    int result = x * y * z;
    std::cout << result << std::endl;
}


int main() {
  std::unique_ptr<Coord> c1 (new Coord);
  std::unique_ptr<Cube> c2 (new Cube);

  c1->new_coordinates(50, 10);
  c2->new_coordinates(10, 20, 30);
  c2->print_volume();

  return 0;
}