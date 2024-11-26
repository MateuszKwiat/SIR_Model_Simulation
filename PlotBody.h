//
// Created by Mateusz Kwiatkowski on 26/11/2024.
//

#pragma once
#include <SFML/Graphics.hpp>

class PlotBody final : public sf::RectangleShape {
private:
    sf::RectangleShape* lines[3];

private:
    void initialize_lines();

public:
    PlotBody(const sf::Vector2f& plot_position, const sf::Vector2f& plot_size, float plot_body_proportion);
    ~PlotBody() override = default;

    friend class ExtendedRenderWindow;
};
