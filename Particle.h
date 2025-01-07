//
// Created by Mateusz Kwiatkowski on 07/01/2025.
//

#pragma once
#include <SFML/Graphics.hpp>

class Particle final : public sf::CircleShape {
private:
    sf::Vector2f velocity;
public:
    Particle(float radius, const sf::Vector2f& pos, const sf::Vector2f& velocity);
    void update(const sf::Angle& angle, const sf::Rect<float>& window_rect);
};

