#pragma once

#include "SFML/Graphics/CircleShape.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

struct Particle {
  sf::CircleShape particle;
  sf::Vector2f velocity;
  float mass;
};

class Particles {
public:
  std::vector<Particle> particles_vec;

  Particles(int amount);
};
