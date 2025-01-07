//
// Created by Mateusz Kwiatkowski on 07/01/2025.
//

#pragma once
#include <SFML/Graphics.hpp>

class Particle : public sf::CircleShape {
private:

public:
    Particle(const sf::Vector2f& pos);
    void move_particle(const sf::Rect<float>& window);
};

