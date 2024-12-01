//
// Created by Mateusz Kwiatkowski on 30/11/2024.
//
#pragma once
#include <SFML/Graphics.hpp>
#include <array>

class TextAnnotations {
private:
    sf::Font font{};
    sf::Text* plot_label{};
    std::array<sf::Text*, 5>* y_ticks{};

private:
    void initialize_text(sf::Text* text, const sf::Vector2f& position, unsigned int char_size,
                         const std::string& str) const;
    void initialize_y_ticks(const sf::Vector2f& plot_size, const sf::Vector2f& plot_position,
                            const std::array<sf::RectangleShape*, 3>& lines);

public:
    TextAnnotations(const sf::Vector2f& plot_size, const sf::Vector2f& plot_position,
                     const std::array<sf::RectangleShape*, 3>& lines);
    ~TextAnnotations();
    friend class ExtendedRenderWindow;
};



