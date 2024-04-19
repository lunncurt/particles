#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

struct Particle {
  sf::CircleShape particle;
  sf::Vector2f velocity;
  float mass;

  void velocity_update(sf::Vector2f &force) {
    sf::Vector2f acceleration = force / mass;
    velocity += acceleration;
  }

  void pos_update() {
    const float scale = 0.0025f;
    particle.setPosition(particle.getPosition() + velocity * scale);
  }
};

class Particles {
public:
  std::vector<Particle> particles_vec;

  Particles(int amount);
};
