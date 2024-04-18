#pragma once

#include "SFML/Graphics/Glsl.hpp"
#include <SFML/Graphics.hpp>

class Particle {
public:
  Particle(const sf::CircleShape part, sf::Glsl::Vec2 position,
           sf::Glsl::Vec2 velocity, float mass);

  sf::Glsl::Vec2 get_position() const { return position; };
  sf::Glsl::Vec2 get_velocity() const { return velocity; };
  float get_mass() const { return mass; };

  void set_position(const sf::Glsl::Vec2 &newPosition) {
    position = newPosition;
  };
  void set_velocity(const sf::Glsl::Vec2 &newVelocity) {
    velocity = newVelocity;
  };
  void set_mass(float newMass) { mass = newMass; };

private:
  sf::Glsl::Vec2 position;
  sf::Glsl::Vec2 velocity;
  float mass;
};
