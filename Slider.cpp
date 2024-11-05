//
// Created by Mateusz Kwiatkowski on 03/11/2024.
//

//  TODO
// add responsiveness to mouse
// finally make it possible to change the value of value XD

#include "Slider.h"

#include <iostream>
#include <format>

Slider::Slider(const sf::RenderWindow& window,
               const sf::Vector2f& slider_to_window_proportions,
               const sf::Vector2f& position,
               const std::string& str,
               float* val,
               unsigned int label_char_size,
               unsigned int ranges_char_size,
               const sf::Vector2i& range) : low(range.x), high(range.y), label_str(str + ": ") {

    value = val;
    this->initialize_slider_body(window, slider_to_window_proportions, position);
    this->initialize_slider_range();
    this->initialize_slider();
    this->initialize_texts(range, label_char_size, ranges_char_size);
    std::cout << "slider body size: " << slider_body->getSize().x << std::endl;
    std::cout << "slider range size: " << slider_range->getSize().x << std::endl;
    std::cout << "slider size: " << slider->getSize().x << std::endl;
}

// slider_body_size = 160, 70

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

void Slider::initialize_texts(const sf::Vector2i& range, const unsigned int label_char_size, const unsigned int ranges_char_size) {

    label = new sf::Text();
    range_low = new sf::Text();
    range_high = new sf::Text();

    if(!font.loadFromFile("/Users/mateuszkwiatkowski/Projects/sir_model_simulation/PixeloidMono-d94EV.ttf")) {
        std::cerr << "Failed to load font." << std::endl;
    }
    const float range_label_offset = slider_body->getSize().x * 0.0625f;
    auto position = sf::Vector2f(slider_body->getPosition().x, slider_body->getPosition().y - slider_body->getSize().y / 3.5f);
    this->initialize_single_text(*label, label_str + std::format("{:.2f}", *value), position, label_char_size);

    position = sf::Vector2f(slider_range->getPosition().x - slider_range->getSize().x / 2.f - range_label_offset,
                            slider_range->getPosition().y - slider_range->getSize().y / 4.f);
    this->initialize_single_text(*range_low, std::to_string(range.x), position, ranges_char_size);

    position = sf::Vector2f(slider_range->getPosition().x + slider_range->getSize().x / 2.f + range_label_offset,
                            slider_range->getPosition().y - slider_range->getSize().y / 4.f);
    this->initialize_single_text(*range_high, std::to_string(range.y), position, ranges_char_size);
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

void Slider::update(float& x) {

}

Slider::~Slider() {
    delete slider_body;
    delete slider_range;
    delete slider;
}