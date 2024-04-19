#include "physics.hpp"
#include "SFML/System/Vector2.hpp"
#include "part.hpp"
#include <cmath>

sf::Vector2f gravitational_force(Particle p, Particle q) {
  sf::Vector2f force(0.f, 0.f);

  float x1 = p.particle.getPosition().x;
  float x2 = q.particle.getPosition().x;

  float y1 = p.particle.getPosition().y;
  float y2 = q.particle.getPosition().y;

  float distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
  float g_constant = 6.67430e-11;
  float f_mag = g_constant * p.mass * q.mass * (1 / (distance * distance));

  if(f_mag != 0.f){
    sf::Vector2f displacement = q.particle.getPosition() - p.particle.getPosition();
    sf::Vector2f f_dir = displacement / distance;

    force = f_dir * f_mag;
  }

  return force;
}
