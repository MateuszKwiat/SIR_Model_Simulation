//
// Created by Mateusz Kwiatkowski on 07/01/2025.
//

#include "Particle.h"

Particle::Particle(const float radius, const sf::Vector2f &pos, const sf::Vector2f& velocity) : velocity(velocity) {
    this->setPosition(pos);
    this->setRadius(radius);
    this->setFillColor(sf::Color(68, 107, 118, 255));
}

void Particle::update(const sf::Angle& angle, const sf::Rect<float>& window_rect) {
    const auto particle_rect = this->getGlobalBounds();
    velocity = velocity.rotatedBy(angle);

    if (particle_rect.position.x + velocity.x <= window_rect.position.x ||
        particle_rect.position.x + velocity.x + particle_rect.size.x >= window_rect.position.x + window_rect.size.x) {
        velocity.x = -velocity.x;
        }
    if (particle_rect.position.y + velocity.y <= window_rect.position.y ||
        particle_rect.position.y + velocity.y + particle_rect.size.y >= window_rect.position.y + window_rect.size.y) {
        velocity.y = -velocity.y;
    }

    this->move(velocity);
}
