#include "part.hpp"
#include "SFML/System/Vector2.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <time.h>
#include <vector>

Particles::Particles(int amount) {

  srand(time(NULL));

  // Center of the circle
  sf::Vector2f center(960, 540);

  // sf::Vector2f c1(480, 270);
  // sf::Vector2f c2(1640, 810);

  float radius = 200.0f; // Radius of the circle

  for (int i = 0; i < amount; i++) {
    Particle p;

    /*
    sf::Vector2f center(0.f, 0.f);
    bool decide = rand() % 2;
    if(decide){
    center += c1; }else{ center+= c2;
    }
    */

    p.particle.setRadius(1.f);
    p.velocity.x = 0.f;
    p.velocity.y = 0.f;
    p.mass = 5e12;

    float angle = (rand() % 360) * (M_PI / 180); // Convert degrees to radians
    float r = (rand() % static_cast<int>(radius)) + 1.0f; // Random radius within the circle

    // Convert polar coordinates to Cartesian coordinates
    float x = center.x + r * cos(angle);
    float y = center.y + r * sin(angle);

    p.particle.setPosition(x, y);

    // p.particle.setPosition(rand() % 1080 + 420, rand() % 1080); // square
    // populate
    p.particle.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
    particles_vec.push_back(p);
  }
}
