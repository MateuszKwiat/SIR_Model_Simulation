//
// Created by Mateusz Kwiatkowski on 21/11/2024.
//

#include "PopulationBar.h"

PopulationBar::PopulationBar(const sf::Vector2f& size, const sf::Color& color) {
    this->setSize(size);
    this->setFillColor(color);
}

void PopulationBar::update(const sf::Vector2f& size) {
    this->setSize(size);
}