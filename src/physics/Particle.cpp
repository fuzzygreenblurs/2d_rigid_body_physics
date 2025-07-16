#include <iostream>
#include "physics/Particle.h"

Particle::Particle(float x, float y, float mass) {
  this->position = Vec2(x, y);

  this->mass = mass;
  if(mass != 0.0) {
    this->inv_mass = 1 / mass;
  } else {
    this->inv_mass = 0;
  }


  std::cout << "particle constructor called" << std::endl;
}

Particle::~Particle() {
  std::cout << "particle destructor called" << std::endl;
}

void Particle::add_force(const Vec2& force) {
  sum_forces += force; 
}

void Particle::clear_forces() {
  this->sum_forces = Vec2(0.0, 0.0); 
}

void Particle::integrate(const float dt) {
  acceleration = sum_forces * inv_mass;
  velocity += acceleration * dt;
  position += velocity * dt;
  clear_forces();
}
  
