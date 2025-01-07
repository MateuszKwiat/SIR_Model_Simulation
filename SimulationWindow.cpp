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
    this->initlialize_particles(pos, size, particle_radius);
}

SimulationWindow::~SimulationWindow() {
    for (const auto & particle : particles) {
        delete particle;
    }
}

void SimulationWindow::initlialize_particles(const sf::Vector2f& pos, const sf::Vector2f& size, float particle_radius) {
    constexpr float rotation_arc = 10.f;
    std::uniform_real_distribution<float> initial_rotation_distribution(0.f, 360.f);
    x_distribution = new std::uniform_real_distribution<float> (pos.x, pos.x + size.x - 2.f * particle_radius);
    y_distribution = new std::uniform_real_distribution<float> (pos.y, pos.y + size.y - 2.f * particle_radius);
    angle_distribution = new std::uniform_real_distribution<float> (-rotation_arc / 2, rotation_arc / 2);

    for (auto & particle : particles) {
        const auto initial_velocity = sf::Vector2f(0.f, 0.5f).
        rotatedBy(sf::Angle(sf::degrees(initial_rotation_distribution.operator()(*rng_pointer))));

        particle = new Particle(particle_radius, sf::Vector2f(x_distribution->operator()(*rng_pointer),
                                                                  y_distribution->operator()(*rng_pointer)), initial_velocity);
    }
}


void SimulationWindow::update() const {
    for (const auto & particle : particles) {
        sf::Angle angle = sf::degrees(angle_distribution->operator()(*rng_pointer));
        particle->update(angle, this->getGlobalBounds());
    }
}
