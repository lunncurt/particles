#include "particle-system/part.hpp"
#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

int main() {

  srand(time(NULL));

  sf::RenderWindow window(sf::VideoMode(1920, 1080), "Particle Sim");

  Particles p(10000);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear(sf::Color::Black);

    for (const auto &particle : p.particles_vec) {
      window.draw(particle.particle);
    }

        window.display();
  }

  return 0;
}
