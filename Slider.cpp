//
// Created by Mateusz Kwiatkowski on 03/11/2024.
//

#include <iostream>
#include <format>

#include "Slider.h"
#include "ExtendedRenderWindow.h"

Slider::Slider(const sf::RenderWindow& window,
               const sf::Vector2f& slider_to_window_proportions,
               const sf::Vector2f& position,
               const std::string& str,
               float* val,
               const unsigned int label_char_size,
               const unsigned int ranges_char_size) : label_str(str + ": ") {

    value = val;
    this->initialize_slider_body(window, slider_to_window_proportions, position);
    this->initialize_slider_range();
    this->initialize_slider();
    this->initialize_texts(label_char_size, ranges_char_size);

    min = slider_range->getPosition().x - slider_range->getSize().x / 2.f + slider->getSize().x / 2.f;
    max = slider_range->getPosition().x + slider_range->getSize().x / 2.f - slider->getSize().x / 2.f;
}

// slider_body_size = 160, 70

float Slider::normalize() const {
    return (slider->getPosition().x - min) / (max - min);
}

void Slider::initialize_slider() {
    const auto size = sf::Vector2f(slider_body->getSize().x * 0.1f, slider_body->getSize().y * 0.35f);
    const auto origin = sf::Vector2f(size.x / 2, size.y / 2);
    const auto position = slider_range->getPosition();

    slider = new sf::RectangleShape(size);
    slider->setOrigin(origin);
    slider->setPosition(position);
    slider->setFillColor(sf::Color::Red);
}

void Slider::initialize_slider_body(const sf::RenderWindow& window, const sf::Vector2f& slider_to_window_proportions,
                                    const sf::Vector2f& pos) {

    const auto size = sf::Vector2f(static_cast<float>(window.getSize().x) * slider_to_window_proportions.x,
                                   static_cast<float>(window.getSize().y) * slider_to_window_proportions.y);

    const auto origin = sf::Vector2f(size.x / 2.f, size.y / 2.f);
    const auto position = pos;

    slider_body = new sf::RectangleShape(size);
    slider_body->setOrigin(origin);
    slider_body->setPosition(position);
    slider_body->setFillColor(sf::Color::White);
}

void Slider::initialize_slider_range() {
    const auto size = sf::Vector2f(slider_body->getSize().x * 0.75f, slider_body->getSize().y * 0.20f);
    const auto origin = sf::Vector2f(size.x / 2.f, size.y / 2.f);
    const auto position = sf::Vector2f(slider_body->getPosition().x,slider_body->getPosition().y + slider_body->getSize().y / 5.f);

    slider_range = new sf::RectangleShape(size);
    slider_range->setOrigin(origin);
    slider_range->setPosition(position);
    slider_range->setFillColor(sf::Color::Black);
}

void Slider::initialize_texts(const unsigned int label_char_size, const unsigned int ranges_char_size) {

    label = new sf::Text();
    range_low = new sf::Text();
    range_high = new sf::Text();

    if(!font.loadFromFile("/Users/mateuszkwiatkowski/Projects/sir_model_simulation/font.ttf")) {
        std::cerr << "Failed to load font." << std::endl;
    }
    const float range_label_offset = slider_body->getSize().x * 0.0625f;
    auto position = sf::Vector2f(slider_body->getPosition().x, slider_body->getPosition().y - slider_body->getSize().y / 3.5f);
    this->initialize_single_text(*label, label_str + std::format("{:.2f}", *value), position, label_char_size);

    position = sf::Vector2f(slider_range->getPosition().x - slider_range->getSize().x / 2.f - range_label_offset,
                            slider_range->getPosition().y - slider_range->getSize().y / 4.f);
    this->initialize_single_text(*range_low, "0", position, ranges_char_size);

    position = sf::Vector2f(slider_range->getPosition().x + slider_range->getSize().x / 2.f + range_label_offset,
                            slider_range->getPosition().y - slider_range->getSize().y / 4.f);
    this->initialize_single_text(*range_high, "1", position, ranges_char_size);
}

void Slider::initialize_single_text(sf::Text& text, const std::string& str, const sf::Vector2f& position, unsigned int char_size) const {
    text.setFont(font);
    text.setString(str);
    text.setCharacterSize(char_size);
    text.setStyle(sf::Text::Bold);
    text.setFillColor(sf::Color::Black);
    text.setOrigin(text.getLocalBounds().width / 2.f, text.getLocalBounds().height / 2.f);
    text.setPosition(position);
}

bool Slider::slider_is_pressed(const ExtendedRenderWindow& window) const {
    return  sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
        slider->getGlobalBounds().contains(sf::Vector2<float>(sf::Mouse::getPosition(window)));
}

bool Slider::slider_is_in_range() const {
    return slider->getGlobalBounds().left > slider_range->getPosition().x - slider_range->getSize().x / 2.f &&
           slider->getGlobalBounds().left + slider->getGlobalBounds().width < slider_range->getPosition().x + slider_range->getSize().x / 2.f;
}

void Slider::follow_mouse(const ExtendedRenderWindow& window) const {
    slider->setPosition(static_cast<float>(sf::Mouse::getPosition(window).x), slider->getPosition().y);
}

bool Slider::slider_is_outside_range_left() const {
    return slider->getGlobalBounds().left <= slider_range->getGlobalBounds().left;
}

bool Slider::slider_is_outside_range_right() const {
    return slider->getGlobalBounds().left + slider->getGlobalBounds().width >=
           slider_range->getGlobalBounds().left + slider_range->getGlobalBounds().width;
}

void Slider::place_back_on_range(const bool left) const {
    constexpr float offset = 0.001f;
    if (left) {
        slider->setPosition(slider_range->getGlobalBounds().left + slider->getSize().x / 2.f + offset, slider->getPosition().y);
    }
    else {
        slider->setPosition(slider_range->getGlobalBounds().left + slider_range->getGlobalBounds().width -
        slider->getSize().x / 2.f - offset, slider->getPosition().y);
    }
}

void Slider::update_value() const {
    *value = normalize();
}

void Slider::update_label() const {
    label->setString(label_str + std::format("{:.2f}", *value));
}


void Slider::update(const ExtendedRenderWindow& window) const {
    if (slider_is_pressed(window) && slider_is_in_range()) {
        this->follow_mouse(window);
        this->update_value();
        if (slider_is_outside_range_left()) {
            this->place_back_on_range(true);
            *value = 0.f;
        }
        if (slider_is_outside_range_right()) {
            this->place_back_on_range(false);
            *value = 1.f;
        }
        this->update_label();
    }
}

Slider::~Slider() {
    delete slider_body;
    delete slider_range;
    delete slider;
}