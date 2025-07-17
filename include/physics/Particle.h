#pragma once


#include "Vec2.h"

struct Particle {
  float radius;
  Vec2 position;
  Vec2 velocity;
  Vec2 acceleration;
  Vec2 sum_forces;
  float mass;
  float inv_mass;

  Particle(float x, float y, float mass);
  ~Particle();
  void integrate(const float dt);
  void clear_forces();
  void add_force(const Vec2& force);
};
