#pragma once

#include "Vec2.h"
#include "Particle.h"

struct Force {
  // drag force formula simplified into one coefficient k
  static Vec2 generate_drag_force(const Particle& particle, const float k);
};
