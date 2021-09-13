#include "SystemModel.h"
#include "SystemView.h"
#include "SystemController.h"
#include <iostream>

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