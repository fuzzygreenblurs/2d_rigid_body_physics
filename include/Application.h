#pragma once

#include "Graphics.h"
#include "physics/Particle.h"

class Application {
  private:
    bool running = false;
    Particle* particle;

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
