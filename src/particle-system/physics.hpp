#pragma once

#include "SFML/System/Vector2.hpp"
#include "part.hpp"
#include <SFML/System.hpp>

sf::Vector2f gravitational_force(Particle p, Particle q);
