#pragma once

#include "Graphics.h"
#include "physics/Particle.h"
#include "physics/Vec2.h"
#include <vector>

class Application {
  private:
    bool running = false;
    std::vector<Particle*> particles;
    Vec2 push_force = Vec2(0.0, 0.0); 
    SDL_Rect liquid;
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
