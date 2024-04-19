#include "particle-system/part.hpp"
#include "particle-system/physics.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

int main() {

  sf::RenderWindow window(sf::VideoMode(1920, 1080), "Particle Sim");

  Particles p(1050);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear(sf::Color::Black);

    for (auto &particle : p.particles_vec) {
      sf::Vector2f total_force(0.f, 0.f);
      for (const auto &inner : p.particles_vec) {
        if(&particle == &inner) continue;

        total_force += gravitational_force(particle, inner);
      }
      particle.velocity_update(total_force);
      particle.pos_update();
    }

    for (auto &particle : p.particles_vec) {
      window.draw(particle.particle);
    }

    window.display();
  }

  return 0;
}
