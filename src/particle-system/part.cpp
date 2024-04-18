#include "part.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <time.h>

Particles::Particles(int amount){

  srand(time(NULL));

  for(int i = 0; i < amount; i++){
    Particle p;

    p.particle.setRadius(0.5f);
    p.velocity.x = 0.f;
    p.velocity.y = 0.f;
    p.mass = 0.f;
    
    p.particle.setPosition(rand() % 1900, rand() % 1060);
    p.particle.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
    particles_vec.push_back(p);
  }
}
