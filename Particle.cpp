//
// Created by Mateusz Kwiatkowski on 07/01/2025.
//

#include "Particle.h"

Particle::Particle(const float radius, const sf::Vector2f &pos) {
    this->setPosition(pos);
    this->setRadius(radius);
    this->setFillColor(sf::Color(68, 107, 118, 255));
}

void Particle::update(const sf::Vector2f& vec, const sf::Rect<float>& window_rect) {
    const auto particle_rect = this->getGlobalBounds();
    auto move_vec = sf::Vector2f();

    if (particle_rect.left + vec.x > window_rect.left &&
        particle_rect.left + vec.x + particle_rect.width < window_rect.left + window_rect.width) {
        move_vec.x = vec.x;
    }
    else {
        move_vec.x = 0.f;
    }
    if (particle_rect.top + vec.y > window_rect.top &&
        particle_rect.top + vec.y + particle_rect.height < window_rect.top + window_rect.height) {
        move_vec.y = vec.y;
        }
    else {
        move_vec.y = 0.f;
    }

    this->move(move_vec);
}
