//
// Created by Mateusz Kwiatkowski on 26/11/2024.
//

#pragma once
#include <SFML/Graphics.hpp>

class PlotBody final : public sf::RectangleShape {

    public:
    PlotBody(const sf::Vector2f& plot_position, const sf::Vector2f& plot_size, float plot_body_proportion);
    ~PlotBody() override = default;
};
