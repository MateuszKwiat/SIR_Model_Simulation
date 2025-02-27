#pragma once

#include <SFML/Graphics.hpp>

class ExtendedRenderWindow;

class Slider {
private:
    float* value = nullptr;
    float min{};
    float max{};
    std::string label_str{};
    sf::RectangleShape* slider = nullptr;
    sf::RectangleShape* slider_body = nullptr;
    sf::RectangleShape* slider_range = nullptr;
    sf::Text* label = nullptr;
    sf::Text* range_low = nullptr;
    sf::Text* range_high = nullptr;
    float a{};
    float b{};

private:
    void initialize_slider_body(const sf::RenderWindow& window, const sf::Vector2f& size,
                                const sf::Vector2f& pos);

    void initialize_single_text(sf::Text& text, const std::string& str, const sf::Vector2f& position,
                                unsigned int char_size) const;

    void initialize_texts(unsigned int label_char_size, unsigned int ranges_char_size, const sf::Font& font);
    void initialize_slider_range();
    void initialize_slider();
    [[nodiscard]] float normalize() const;
    [[nodiscard]] bool slider_is_pressed(const ExtendedRenderWindow& window) const;
    [[nodiscard]] bool slider_is_in_range() const;
    void follow_mouse(const ExtendedRenderWindow& window) const;
    [[nodiscard]] bool slider_is_outside_range_left() const;
    [[nodiscard]] bool slider_is_outside_range_right() const;
    void place_back_on_range(bool left) const;
    void update_value() const;
    void update_label() const;

public:
    explicit Slider(const sf::RenderWindow& window,
                    const sf::Vector2f& size,
                    const sf::Vector2f& position,
                    const std::string& str,
                    float* val,
                    unsigned int label_char_size,
                    unsigned int ranges_char_size,
                    const sf::Font& font);

    void update(const ExtendedRenderWindow& window) const;
    ~Slider();

    friend class ExtendedRenderWindow;
};
