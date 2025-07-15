#include "Application.h"

int main(int argc, char* argv[]) {
  
  Application app;
  app.setup();

  while(app.is_running()) {
    app.input();
    app.update();
    app.render();
  }
  
  app.destroy();

  return 0;
}
