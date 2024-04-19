#include "part.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <time.h>

Particles::Particles(int amount){

  srand(time(NULL));

  for(int i = 0; i < amount; i++){
    Particle p;

    p.particle.setRadius(2.5f);
    p.velocity.x = 0.f;
    p.velocity.y = 0.f;
    p.mass = 5e11;
    
    p.particle.setPosition(rand() % 100+ 860, rand() % 100 + 440);
    p.particle.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
    particles_vec.push_back(p);
  }
}
