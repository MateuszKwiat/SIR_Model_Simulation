//
// Created by Mateusz Kwiatkowski on 30/11/2024.
//
#pragma once
#include "PopulationBar.h"
#include <SFML/Graphics.hpp>
#include <array>

class TextAnnotations {
private:
    sf::Font font{};
    sf::Text* plot_label{};
    std::array<sf::Text*, 5>* y_ticks{};
    sf::Text* susceptible_label{};
    sf::Text* infectious_label{};
    sf::Text* recovered_label{};

private:
    void initialize_text(sf::Text* text, const sf::Vector2f& position, unsigned int char_size,
                         const std::string& str) const;

    void initialize_y_ticks(const sf::Vector2f& plot_size, const sf::Vector2f& plot_position,
                            const std::array<sf::RectangleShape*, 3>& lines);

    void initialize_labels(const std::array<PopulationBar, 3>& population_bars, const sf::Vector2f& plot_body_size,
                           const sf::Vector2f& plot_size);

public:
    TextAnnotations(const sf::Vector2f& plot_size,
                    const sf::Vector2f& plot_position,
                    const std::array<sf::RectangleShape*, 3>& lines,
                    const std::array<PopulationBar, 3>& population_bars,
                    const sf::Vector2f& plot_body_size);

    ~TextAnnotations();
    friend class ExtendedRenderWindow;
};



