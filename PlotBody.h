//
// Created by Mateusz Kwiatkowski on 26/11/2024.
//

#pragma once
#include <SFML/Graphics.hpp>
#include <array>

class PlotBody final : public sf::RectangleShape {
private:
    std::array<sf::RectangleShape*, 3> lines{};
    // sf::RectangleShape* lines[3]{};

private:
    void initialize_lines();

public:
    PlotBody(const sf::Vector2f& plot_position, const sf::Vector2f& plot_size, float plot_body_proportion);
    ~PlotBody() override;

    const std::array<sf::RectangleShape*, 3>* get_lines() const {return &lines;}
    friend class ExtendedRenderWindow;
};
