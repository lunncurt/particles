#pragma once

#include </opt/homebrew/Cellar/glm/1.0.1/include/glm/glm.hpp>

class Particle {
public:
  Particle(const glm::vec2 &position, const glm::vec2 &velocity, float mass);

  glm::vec2 get_position() const { return position; }
  glm::vec2 get_velocity() const { return velocity; }
  float get_mass() const { return mass; }

  void setPosition(const glm::vec2 &newPosition) { position = newPosition; }
  void setVelocity(const glm::vec2 &newVelocity) { velocity = newVelocity; }
  void setMass(float newMass) { mass = newMass; }

private:
  glm::vec2 position;
  glm::vec2 velocity;
  float mass;
};
