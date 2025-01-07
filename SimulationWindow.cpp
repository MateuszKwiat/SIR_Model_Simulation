//
// Created by Mateusz Kwiatkowski on 07/01/2025.
//

#include "SimulationWindow.h"

SimulationWindow::SimulationWindow(const sf::Vector2f& pos, const sf::Vector2f& size) {
    this->setPosition(pos);
    this->setSize(size);
    this->setFillColor(sf::Color::Black);
    this->setOutlineColor(sf::Color::White);
    this->setOutlineThickness(1);

    particle = new Particle(sf::Vector2f(pos.x + size.x / 2.f, pos.y + size.y / 2.f));
}

SimulationWindow::~SimulationWindow() {
    delete particle;
}
