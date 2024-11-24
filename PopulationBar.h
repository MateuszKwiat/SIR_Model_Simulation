//
// Created by Mateusz Kwiatkowski on 21/11/2024.
//

#pragma once
#include <SFML/Graphics.hpp>

class PopulationBar : public sf::RectangleShape {
public:
    PopulationBar(const sf::Vector2f& size, const sf::Color& color);
    ~PopulationBar() override = default;
    void update(const sf::Vector2f& size);
};


