//
// Created by Mateusz Kwiatkowski on 07/01/2025.
//
#pragma once
#include <SFML/Graphics.hpp>

#include "Particle.h"

class SimulationWindow : public sf::RectangleShape {
private:
    sf::Text title {};
    Particle* particle {};
private:

public:
    SimulationWindow(const sf::Vector2f& pos, const sf::Vector2f& size);
    ~SimulationWindow();
    void test_particle() const {particle->move_particle(this->getGlobalBounds());}

    friend class ExtendedRenderWindow;
};
