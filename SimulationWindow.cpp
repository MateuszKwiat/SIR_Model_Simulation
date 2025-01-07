//
// Created by Mateusz Kwiatkowski on 07/01/2025.
//

#include "SimulationWindow.h"

SimulationWindow::SimulationWindow(const sf::Vector2f& pos, const sf::Vector2f& size, const std::string& title) {
    this->setPosition(pos);
    this->setSize(size);
    this->setFillColor(sf::Color::Black);
    this->setOutlineColor(sf::Color::White);
    this->setOutlineThickness(1);
}

void SimulationWindow::initialize_title(const std::string& title) {

}
