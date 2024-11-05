#pragma once

#include <SFML/Graphics.hpp>

class Slider {
private:
    float* value;
    float low;
    float high;
    sf::RectangleShape* slider{};
    sf::RectangleShape* slider_body{};
    sf::RectangleShape* slider_range{};
    sf::Font font{};
    sf::Text* label{};
    sf::Text* range_low{};
    sf::Text* range_high{};

private:
    void initialize_slider_body(const sf::RenderWindow& window, const sf::Vector2f& slider_to_window_proportions,
                                const sf::Vector2f& pos);

    void initialize_slider_range();
    void initialize_slider();
    void initialize_texts(const std::string& label, const sf::Vector2f& range);
    void initialize_single_text(sf::Text& text, const std::string& str, const sf::Vector2f& position, unsigned int char_size) const;

public:
    explicit Slider(const sf::RenderWindow& window,
                    const sf::Vector2f& slider_to_window_proportions,
                    const sf::Vector2f& position,
                    const std::string& str,
                    float* val,
                    const sf::Vector2f& range = {0, 1});

    void update(float& x);
    ~Slider();

    friend class ExtendedRenderWindow;
};