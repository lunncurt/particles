#pragma once

#include "SFML/System/Vector2.hpp"
#include "part.hpp"
#include <SFML/System.hpp>

sf::Vector2f gravitational_force(const Particle &p, const Particle &q);
