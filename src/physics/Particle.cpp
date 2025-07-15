#include <iostream>
#include "physics/Particle.h"

Particle::Particle(float x, float y, float mass) {
  this->position = Vec2(x, y);
  this->mass = mass;
  std::cout << "particle constructor called" << std::endl;
}

Particle::~Particle() {
  std::cout << "particle destructor called" << std::endl;
}

void Particle::integrate(const float dt) {
  this->velocity += this->acceleration * dt;
  this->position += this->velocity * dt;
}
