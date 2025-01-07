//
// Created by Mateusz Kwiatkowski on 07/01/2025.
//
#pragma once
#include <SFML/Graphics.hpp>

class SimulationWindow : public sf::RectangleShape {
private:
    sf::Font font;
    sf::Text title;

private:
    void initialize_title(const std::string& title);

public:
    SimulationWindow(const sf::Vector2f& pos, const sf::Vector2f& size, const std::string& title);
};
