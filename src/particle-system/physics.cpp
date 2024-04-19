#include "physics.hpp"
#include "SFML/System/Vector2.hpp"
#include "part.hpp"
#include <cmath>

/*
 * old grav equation
  sf::Vector2f gravitational_force(const Particle &p, const Particle &q) {
  sf::Vector2f force(0.f, 0.f);

  float x1 = p.particle.getPosition().x;
  float x2 = q.particle.getPosition().x;

  float y1 = p.particle.getPosition().y;
  float y2 = q.particle.getPosition().y;

  float distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)) * 5.f + 100;
  float g_constant = 6.67430e-11;
  float f_mag = g_constant * p.mass * q.mass * (1 / (distance * distance));

  if (f_mag != 0.f) {
    sf::Vector2f displacement =
        q.particle.getPosition() - p.particle.getPosition();
    sf::Vector2f f_dir = displacement / distance;

    force = f_dir * f_mag;
  }

  return force;
}
*/

sf::Vector2f gravitational_force(const Particle &p, const Particle &q) {
  const sf::Vector2f ppos = p.particle.getPosition();
  const sf::Vector2f qpos = q.particle.getPosition();

  const sf::Vector2f displacement = qpos - ppos;
  const float distance =
      displacement.x * displacement.x + displacement.y * displacement.y + 500.f;

  const float g_const = 6.67430e-11;
  const float f_mag = g_const * p.mass * q.mass / distance;

  return displacement / std::sqrt(distance) * f_mag;
}
