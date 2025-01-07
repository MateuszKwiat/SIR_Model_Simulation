//
// Created by Mateusz Kwiatkowski on 07/01/2025.
//

#include "Particle.h"

Particle::Particle(const sf::Vector2f &pos) {
    this->setPosition(pos);
    this->setRadius(5);
    this->setFillColor(sf::Color::Green);
}

void Particle::move_particle(const sf::Rect<float> &window) {
    const auto particle_rect = this->getGlobalBounds();
    constexpr float move_val = 0.5f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && particle_rect.left > window.left) {
        this->move(-move_val, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && particle_rect.left + particle_rect.width < window.left + window.width) {
        this->move(move_val, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && particle_rect.top > window.top) {
        this->move(0.f, -move_val);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && particle_rect.top + particle_rect.height < window.top + window.height) {
        this->move(0.f, move_val);
    }

}
