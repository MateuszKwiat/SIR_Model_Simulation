//
// Created by Mateusz Kwiatkowski on 30/11/2024.
//
#pragma once
#include "PopulationBar.h"
#include <SFML/Graphics.hpp>
#include <array>

class TextAnnotations {
private:
    sf::Text* plot_label = nullptr;
    std::array<sf::Text*, 5>* y_ticks = nullptr;
    sf::Text* susceptible_label = nullptr;
    sf::Text* infectious_label = nullptr;
    sf::Text* recovered_label = nullptr;

private:
    void initialize_text(sf::Text* text, const sf::Vector2f& position, unsigned int char_size,
                         const std::string& str, const sf::Font& font) const;

    void initialize_y_ticks(const sf::Vector2f& plot_size, const sf::Vector2f& plot_position,
                            const std::array<sf::RectangleShape*, 3>& lines, const sf::Font& font);

    void initialize_labels(const std::array<PopulationBar, 3>& population_bars, const sf::Vector2f& plot_body_size,
                           const sf::Vector2f& plot_size, const sf::Font& font) const;

public:
    TextAnnotations(const sf::Vector2f& plot_size,
                    const sf::Vector2f& plot_position,
                    const std::array<sf::RectangleShape*, 3>& lines,
                    const std::array<PopulationBar, 3>& population_bars,
                    const sf::Vector2f& plot_body_size,
                    const sf::Font& font);

    ~TextAnnotations();
    friend class ExtendedRenderWindow;
};



