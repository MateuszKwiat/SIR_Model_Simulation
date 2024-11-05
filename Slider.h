#pragma once

#include <SFML/Graphics.hpp>

class Slider {
private:
    float* value;
    int low;
    int high;
    std::string label_str;
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

    void initialize_single_text(sf::Text& text, const std::string& str, const sf::Vector2f& position,
                                unsigned int char_size) const;

    void initialize_texts(const sf::Vector2i& range, unsigned int label_char_size, unsigned int ranges_char_size);
    void initialize_slider_range();
    void initialize_slider();

public:
    explicit Slider(const sf::RenderWindow& window,
                    const sf::Vector2f& slider_to_window_proportions,
                    const sf::Vector2f& position,
                    const std::string& str,
                    float* val,
                    unsigned int label_char_size,
                    unsigned int ranges_char_size,
                    const sf::Vector2i& range = {0, 1});

    void update(float& x);
    ~Slider();

    friend class ExtendedRenderWindow;
};