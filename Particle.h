//
// Created by Mateusz Kwiatkowski on 07/01/2025.
//

#pragma once
#include <SFML/Graphics.hpp>

class Particle : public sf::CircleShape {
private:

public:
    Particle(float radius, const sf::Vector2f& pos);
    void update(const sf::Vector2f& vec, const sf::Rect<float>& window);
};

