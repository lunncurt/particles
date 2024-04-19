#include "particle-system/part.hpp"
#include "particle-system/physics.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

int main() {

  sf::RenderWindow window(sf::VideoMode(1920, 1080), "Particle Sim");

  Particles p(80);

  sf::Clock clock;
  sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    sf::Time elapsedTime = clock.restart();
    if (elapsedTime < timePerFrame)
      sf::sleep(timePerFrame - elapsedTime);

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

    for (auto particle : p.particles_vec) {
      window.draw(particle.particle);
    }

    window.display();
  }

  return 0;
}
