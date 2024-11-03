#pragma once

#include <SFML/Graphics.hpp>

class Slider {
private:
    float* value;
    sf::RectangleShape* slider{};
    sf::RectangleShape* slider_body{};
    sf::RectangleShape* slider_range{};
    sf::Font font{};
    sf::Text* label{};
    sf::Text* range_low{};
    sf::Text* range_high{};

private:
    void initialize_slider_body(const sf::RenderWindow& window);
    void initialize_slider_range();
    void initialize_slider();
    void initialize_texts();
    void initialize_single_text(sf::Text& text, const std::string& str, const sf::Vector2f& position, unsigned int char_size) const;

public:
    explicit Slider(const sf::RenderWindow& window, float* val);
    void update(float& x);
    ~Slider();

    friend class ExtendedRenderWindow;
};