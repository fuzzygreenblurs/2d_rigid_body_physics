#pragma once

#include "Graphics.h"
#include "physics/Particle.h"
#include <vector>

class Application {
  private:
    bool running = false;
    std::vector<Particle*> particles;
//    Particle* particle;

  public:
    Application() = default;
    ~Application() = default;

    bool is_running();
    void setup();
    void input();
    void update();
    void render();
    void destroy();
};
