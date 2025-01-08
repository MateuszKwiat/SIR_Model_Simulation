//
// Created by Mateusz Kwiatkowski on 08/01/2025.
//
#pragma once
#include <SFML/Graphics.hpp>

class Button final : public sf::RectangleShape {
private:
    sf::Text* text = nullptr;
    sf::Color not_pressed_color{};
    sf::Color pressed_color{};
    bool got_pressed{};

public:
    Button(const sf::Vector2f& position, const sf::Vector2f& size, const std::string& str, const sf::Font& font);
    ~Button() override;
    bool is_pressed(const sf::RenderWindow& window);

    friend class ExtendedRenderWindow;
};
