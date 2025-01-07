//
// Created by Mateusz Kwiatkowski on 07/01/2025.
//

#include "SimulationWindow.h"

SimulationWindow::SimulationWindow(const sf::Vector2f& pos, const sf::Vector2f& size, const float particle_radius,
                                   std::mt19937& rng) {
    this->setPosition(pos);
    this->setSize(size);
    this->setFillColor(sf::Color::Black);
    this->setOutlineColor(sf::Color::White);
    this->setOutlineThickness(1);

    rng_pointer = &rng;
    x_distribution = new std::uniform_real_distribution<float> (pos.x, pos.x + size.x - 2.f * particle_radius);
    y_distribution = new std::uniform_real_distribution<float> (pos.y, pos.y + size.y - 2.f * particle_radius);
    movement_distribution = new std::uniform_real_distribution<float> (-1.f, 1.f);

    for (auto & particle : particles) {
        particle = new Particle(particle_radius, sf::Vector2f(x_distribution->operator()(*rng_pointer),
                                                                  y_distribution->operator()(*rng_pointer)));
    }
}

SimulationWindow::~SimulationWindow() {
    for (const auto & particle : particles) {
        delete particle;
    }
}

void SimulationWindow::update() const {
    auto move_vector = sf::Vector2f();
    for (const auto & particle : particles) {
        move_vector.x = movement_distribution->operator()(*rng_pointer);
        move_vector.y = movement_distribution->operator()(*rng_pointer);
        particle->update(move_vector, this->getGlobalBounds());
    }
}
