#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

struct Particle {
  sf::CircleShape particle;
  sf::Vector2f velocity;
  float mass;

void velocity_update(sf::Vector2f force) {
    sf::Vector2f acceleration = force / mass;
    float dt = .01f;
    velocity += acceleration * dt;
  }

  void pos_update() {
  particle.setPosition(particle.getPosition() + velocity*.1f);
  }
};

class Particles {
public:
  std::vector<Particle> particles_vec;

  Particles(int amount);
};
