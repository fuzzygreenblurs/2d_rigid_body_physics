#pragma once


#include "Vec2.h"

struct Particle {
  float radius;
  Vec2 position;
  Vec2 velocity;
  Vec2 acceleration;

  float mass;
  Particle(float x, float y, float mass);
  ~Particle();
};
