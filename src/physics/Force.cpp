#include "physics/Force.h"

Vec2 Force::generate_drag_force(const Particle& particle, const float k) {
  Vec2 drag_force = Vec2(0.0, 0.0);
  if(particle.velocity.magnitude_squared() > 0) {
    Vec2 direction = particle.velocity.unit_vector() * -1.0;
    float magnitude = k * particle.velocity.magnitude_squared();
    drag_force = direction * magnitude;
  }

  return drag_force;
}
