#include "Application.h"
#include "physics/Constants.h"

bool Application::is_running() {
  return running;
}

void Application::setup() {
  running = Graphics::OpenWindow();

  Particle* small = new Particle(100, 100, 1.0);
  small->radius = 51;
  particles.push_back(small);

  
  Particle* big   = new Particle(300, 200, 3.0);
  big->radius = 12;
  particles.push_back(big);
}

void Application::input() {
  SDL_Event event;
  while(SDL_PollEvent(&event)) {
    switch(event.type) {
      
      case SDL_QUIT:
        running = false;
        break;

      case SDL_KEYDOWN:
        if(event.key.keysym.sym == SDLK_ESCAPE) {
          running = false;
        }

        break;
    }
  }
}

void Application::render() {
  Graphics::ClearScreen(0xFF056263);
  
  for(auto particle : particles) {
    Graphics::DrawFillCircle(
      particle->position.x, 
      particle->position.y, 
      particle->radius, 
      0xFFFFFFFF
    );
  }

  Graphics::RenderFrame();
}

void Application::update() {
  /*
  variable delta_time approach: delta_time changes dynamically between frames.
  this leads to non-deterministic behavior. maintaining a constant delta-time
  allows for determinism but couples the speed of the simulation with the FPS.
  */

  //static int should be zero-initialized by default
  static int prev_frame_end_time;

  int elapsed_ms = SDL_GetTicks() - prev_frame_end_time;
  int delay_ms = DESIRED_FRAME_DURATION_MS - elapsed_ms; 

  if(delay_ms > 0) {
    SDL_Delay(delay_ms);
  }

  float delta_time = (SDL_GetTicks() - prev_frame_end_time) / 1000.0f;
  if(delta_time > 0.016) {
    delta_time = 0.016;
  }

  prev_frame_end_time = SDL_GetTicks();

  /*
    framerate-independent movement: movement of particles is not tied to
    framerate. if the framerate drops, the particle is updated fewer times per second
    but it should traverse the same number of distance units/second 
  */
  for(auto particle : particles) {
    Vec2 wind = Vec2(1 * PIXELS_PER_METER, 0);
    particle->add_force(wind);
    particle->integrate(delta_time);
  }

  for(auto particle : particles) {
    Vec2 weight = Vec2(0, 9.81 * particle->mass * PIXELS_PER_METER);
    particle->add_force(weight);
    particle->integrate(delta_time);
  }

  for(auto particle : particles) {
    // limit the position to within the boundaries of the screen  
    if(particle->position.x - particle->radius <= 0) {
      particle->position.x = particle->radius;
      particle->velocity.x *= -1.0;
    } else if (particle->position.x + particle->radius >= Graphics::Width()) {
      particle->position.x = Graphics::Width() - particle->radius;
      particle->velocity.x *= -1.0;
    }

    if(particle->position.y - particle->radius <= 0) {
      particle->position.y = particle->radius;
      particle->velocity.y *= -1.0;
    } else if (particle->position.y + particle->radius >= Graphics::Height()) {
      particle->position.y = Graphics::Height() - particle->radius;
      particle->velocity.y *= -1.0; }
    }
  }

void Application::destroy() {
  for(auto particle : particles) {
    delete particle;
  }
  Graphics::CloseWindow();
}

