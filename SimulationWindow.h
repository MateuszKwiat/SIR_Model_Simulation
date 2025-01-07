//
// Created by Mateusz Kwiatkowski on 07/01/2025.
//
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <random>
#include <array>

#include "Particle.h"

class SimulationWindow : public sf::RectangleShape {
private:
    sf::Text title;
    std::array<Particle*, 120> particles {};
    std::mt19937* rng_pointer;
    std::uniform_real_distribution<float>* x_distribution {};
    std::uniform_real_distribution<float>* y_distribution {};
    std::uniform_real_distribution<float>* movement_distribution {};

private:
    void initlialize_particles(const sf::Vector2f& pos, const sf::Vector2f& size, float particle_radius);

public:
    SimulationWindow(const sf::Vector2f& pos, const sf::Vector2f& size, float particle_radius, std::mt19937& rng);
    ~SimulationWindow() override;
    void update() const;
    friend class ExtendedRenderWindow;
};
